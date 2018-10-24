package com.norellanac.domoticaApp.controllers;



import com.norellanac.domoticaApp.models.Conectar;
import com.norellanac.domoticaApp.utiles.ArduinoLeoSendData4;
import com.norellanac.domoticaApp.utiles.SendMailGmail;
import com.norellanac.domoticaApp.utiles.arduinoRecibe2EnviaString;
import com.norellanac.domoticaApp.utiles.arduinoUnoSendData2;
import com.norellanac.domoticaApp.utiles.fechasNorellanac;
import com.norellanac.domoticaApp.utiles.serialComArduino;
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
public class LucesSensoresController {
    //@Autowired	
    private  static JdbcTemplate jdbcTemplate;
    private static    Conectar con=new Conectar();
    ArduinoLeoSendData4 ardLeo=new ArduinoLeoSendData4();
    fechasNorellanac fecha= new fechasNorellanac();
    private String correo="norellanac@miumg.edu.gt";
    private String asuntoMail="Alerta DOMOTICA";

        
        
        
                
        
        @GetMapping("/monitorear")
        public String monitorear(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("1");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail(correo, asuntoMail, "Sistema En Monitoreo");
            req.setAttribute("info", ardLeo.getInfo());
            req.setAttribute("s1", ardLeo.getS1());
            req.setAttribute("s2", ardLeo.getS2());
            req.setAttribute("s3", ardLeo.getS3());
            return "clima";

        }
        
        @GetMapping("/deviceOneAcctive")
        public String deviceOneAcctive(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("2");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta DOMOTICA", "Sistema DESACTIVADO");
            return "alarma";

        }
        
    
}