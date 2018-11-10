package com.norellanac.domoticaApp.controllers;



import com.norellanac.domoticaApp.models.Conectar;
import com.norellanac.domoticaApp.utiles.SendMailGmail;
import com.norellanac.domoticaApp.utiles.arduinoUnoSendData2;
import com.norellanac.domoticaApp.utiles.fechasNorellanac;
import com.panamahitek.ArduinoException;
import java.io.IOException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import jssc.SerialPortException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class AlarmaController {
    //@Autowired	
    private  static JdbcTemplate jdbcTemplate;
    private static    Conectar con=new Conectar();
    //arduinoUnoSendData2 ardUno=new arduinoUnoSendData2();
    fechasNorellanac fecha= new fechasNorellanac();
   

        
        @GetMapping("/alarma")
        public String alarma(HttpServletRequest req) {
            return "alarma";
        }
        
        
        
        @GetMapping("/alertaMail")
        public String alertaMail(@RequestParam String alerta, HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Prueba", alerta);
            return "clima";

        }
        
        
        @GetMapping("/alarmActive")
        public String alarmActive(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            //    arduinoUnoSendData2 ardUno=new arduinoUnoSendData2();
            //ardUno.enviarDato("1");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta", "Sistema ACTIVADO");
            sendM.enviarMail("alexis_oc@yahoo.es", "Alerta", "Sistema ACTIVADO");
            arduinoUnoSendData2 ard=new arduinoUnoSendData2();
        ard.enviarDato("1");
            return "alarma";

        }
        
        @GetMapping("/alarmInactive")
        public String alarmInactive(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
              //  arduinoUnoSendData2 ardUno=new arduinoUnoSendData2();
            //ardUno.enviarDato("2");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "ALERTA", "Sistema DESACTIVADO");           
            sendM.enviarMail("alexis_oc@yahoo.es", "Alerta", "Sistema DESACTIVADO");
            arduinoUnoSendData2 ard=new arduinoUnoSendData2();
        ard.enviarDato("2");
            return "alarma";

        }
        
    
}