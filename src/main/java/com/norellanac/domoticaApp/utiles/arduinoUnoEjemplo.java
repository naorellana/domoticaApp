/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.norellanac.domoticaApp.utiles;
import com.norellanac.domoticaApp.models.Conectar;
import com.panamahitek.ArduinoException;
import com.panamahitek.PanamaHitek_Arduino;
import com.panamahitek.PanamaHitek_MultiMessage;
import java.util.logging.Level;
import java.util.logging.Logger;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;
import org.springframework.jdbc.core.JdbcTemplate;

/**
 *
 * @author norellanac
 */
public class arduinoUnoEjemplo {
    private static String textoEnviado;
    private static String concatTextArduino="";
    private static String codUsuario="";
    private static String warning="no";
    static String code;
     static int val;

    public  String getCode() {
        return code;
    }

    public  int getVal() {
        return val;
    }

    /**
     * @param args the command line arguments
     */
    //contructor
    public arduinoUnoEjemplo(){
    }
    
    //funcion para enviar los datos
    public  void enviarDato(String texto) {
        textoEnviado=texto;
        try {
            //ino.killArduinoConnection();
            ino.arduinoRXTX(PuertoSerie, 9600, listener);
            ino.sendData(textoEnviado);//pero no se usa, solo esta aqui para que no de error de sintaxis
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(arduinoUnoEjemplo.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    public void kill() throws ArduinoException, SerialPortException {
        try {
            ino.killArduinoConnection();
            ino.arduinoRXTX(PuertoSerie, 9600, listener);
            ino.killArduinoConnection();
            //ino.sendData(textoEnviado);//pero no se usa, solo esta aqui para que no de error de sintaxis
        } catch (ArduinoException ex) {
            Logger.getLogger(arduinoUnoEjemplo.class.getName()).log(Level.SEVERE, null, ex);
        }   
    }
    
    //ttrabbajarco base deatos
    private  static JdbcTemplate jdbcTemplate;
    private static    Conectar con=new Conectar();
    //se declara el nombre del puerto ||ya que funciona en linux y windows, pero los nombres del puerto cambian
    private static String PuertoSerie="/dev/ttyACM0"; //liunx
    //private static String PuertoSerie="COM3"; //windows
    //Cantidad de variables--Serial.println();-- que se leeran desde arduino
    private static int arduinoVariables=2;
    //Se crea una instancia de la librería PanamaHitek_Arduino
    private static PanamaHitek_Arduino ino = new PanamaHitek_Arduino();
    //var multi, sirve para leer multiples println desde arduino y el numero indica la cantidad de lecturas
    private static PanamaHitek_MultiMessage multi = new PanamaHitek_MultiMessage(arduinoVariables, ino);
        private static final SerialPortEventListener listener = new SerialPortEventListener() {
        @Override
        public void serialEvent(SerialPortEvent spe) {
            
        fechasNorellanac fecha= new fechasNorellanac();
            try {
                
                if (multi.dataReceptionCompleted()) {
                    //si el codigo recibido es igual a 10 (o se puede comparar ya con datos del sistema)
                    
                    
                    System.out.println("Codigo  -------> " + multi.getMessage(0));
                    System.out.println("Variable    -------> " + multi.getMessage(1));
                    System.out.println("-----------------------------------");
                    
                    multi.flushBuffer();
                    ino.sendData(textoEnviado);
                    //ino.killArduinoConnection();
                }
            } catch (SerialPortException | ArduinoException ex) {
                Logger.getLogger(arduinoUnoEjemplo.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    };

    
    
}