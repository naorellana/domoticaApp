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

public class ArduinoLeoSendData4 {
    private static String textoEnviado;
     static String info="";
     static float s1,s2,s3;
     static int cont=0;
    public String getInfo() {
        return info;
    }

    public float getS1() {
        return s1;
    }

    public float getS2() {
        return s2;
    }

    public float getS3() {
        return s3;
    }

     
   
    

    /**
     * @param args the command line arguments
     */
    //contructor
    public ArduinoLeoSendData4(){
    }
    
    //funcion para enviar los datos
    public  void enviarDato(String texto) {
        textoEnviado=texto;
        try {
            //ino.killArduinoConnection();
            ino.arduinoRXTX(PuertoSerie, 9600, listener);
            multi.flushBuffer();
            ino.sendData(textoEnviado);//pero no se usa, solo esta aqui para que no de error de sintaxis
        } catch (ArduinoException | SerialPortException ex) {
            Logger.getLogger(ArduinoLeoSendData4.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    public void kill() throws ArduinoException, SerialPortException {
        try {
            ino.killArduinoConnection();
            ino.arduinoRXTX(PuertoSerie, 9600, listener);
            ino.killArduinoConnection();
            ino.sendData(textoEnviado);//pero no se usa, solo esta aqui para que no de error de sintaxis
        } catch (ArduinoException ex) {
            Logger.getLogger(ArduinoLeoSendData4.class.getName()).log(Level.SEVERE, null, ex);
        }   
    }
    
    //ttrabbajarco base deatos
    private  static JdbcTemplate jdbcTemplate;
    private static    Conectar con=new Conectar();
    //se declara el nombre del puerto ||ya que funciona en linux y windows, pero los nombres del puerto cambian
    private static String PuertoSerie="/dev/ttyACM1"; //liunx
    //private static String PuertoSerie="COM3"; //windows
    //Cantidad de variables--Serial.println();-- que se leeran desde arduino
    private static int arduinoVariables=4;
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
                    
                    ino.sendData(textoEnviado);
                    //si el codigo recibido es igual a 10 (o se puede comparar ya con datos del sistema)
                    if(multi.getMessage(0)!=""){
                        //ino.killArduinoConnection();
                    }
                    if(multi.getMessage(0).toString().equals("Monitoreo")){
                        ino.killArduinoConnection();
                    }
                    if(multi.getMessage(0).toString().equals("Encendido")){
                        ino.killArduinoConnection();
                    }
                    if (multi.getMessage(0).toString().equals("APAGADO")) {
                        ino.killArduinoConnection();
                    }
                    
                    System.out.println("dato1  -------> " + multi.getMessage(0));
                    info=multi.getMessage(0);
                    System.out.println("dato2    -------> " + multi.getMessage(1));
                    s1=Float.parseFloat(multi.getMessage(1));
                    System.out.println("dato3  -------> " + multi.getMessage(2));
                    s2=Float.parseFloat(multi.getMessage(2));
                    System.out.println("dato4    -------> " + multi.getMessage(3));
                    s3=Float.parseFloat(multi.getMessage(3));
                    System.out.println("-----------------------------------");
                    
                    multi.flushBuffer();
                    cont=cont+1;
                    /*if (cont>1){
                        multi.flushBuffer();
                        ino.killArduinoConnection();
                        System.out.println("salio en if");
                        
                    }*/
                }
            } catch (SerialPortException | ArduinoException ex) {
                Logger.getLogger(ArduinoLeoSendData4.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    };

    
    
}