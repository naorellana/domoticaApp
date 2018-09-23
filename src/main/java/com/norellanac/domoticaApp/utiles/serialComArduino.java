/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.norellanac.domoticaApp.utiles;

//import com.norellanac.arduinoSerialCom.test001.arduinoNerytest001;
import com.panamahitek.ArduinoException;
import com.panamahitek.PanamaHitek_Arduino;
import java.util.logging.Level;
import java.util.logging.Logger;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;

/**
 *
 * @author norellanac
 */
public class serialComArduino {
        String textoEnviado;
        String Puerto="/dev/ttyACM0"; //nombre del puerto en linux
        
    
    public void enviaDatoArduino(String texto){
        textoEnviado=texto;
             
    //***inicia la conxion usando el istener que tiene arametros para leer un mensaje
    //initComponents();
        //Se inicia la conexion con el puerto serie COM20 a 9600 baudios
        try {
            ino.arduinoRXTX(Puerto, 9600, listener);
           
        } catch (ArduinoException ex) {
            Logger.getLogger(serialComArduino.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public serialComArduino() {
    }
    

     //Se crea una variable tipo PanamaHitek_Arduino
    PanamaHitek_Arduino ino = new PanamaHitek_Arduino();
    //Se crea un eventListener para el puerto serie
    SerialPortEventListener listener = new SerialPortEventListener() {
        @Override
        //Si se recibe algun dato en el puerto serie, se ejecuta el siguiente metodo
        public void serialEvent(SerialPortEvent serialPortEvent) {
            try {
                //ino.sendData("1R");
                /*
                Los datos en el puerto serie se envian caracter por caracter. Si se
                desea esperar a terminar de recibir el mensaje antes de imprimirlo, 
                el metodo isMessageAvailable() devolvera TRUE cuando se haya terminado
                de recibir el mensaje, el cual podra ser impreso a traves del metodo
                printMessage()
                 */
                if (ino.isMessageAvailable()) {
                    //Se recibe el dato y se le asigna al jLabelAnswer
                    System.out.println(ino.printMessage());
                    ino.sendData(textoEnviado);
                    ino.killArduinoConnection();
                }
            } catch (SerialPortException | ArduinoException ex) {
                Logger.getLogger(serialComArduino.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    };
   
    
       
}
