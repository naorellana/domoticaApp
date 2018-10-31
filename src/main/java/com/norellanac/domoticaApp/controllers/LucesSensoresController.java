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
import java.util.List;
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
    {
        Conectar con=new Conectar();
        this.jdbcTemplate=new JdbcTemplate(con.conectar());
    }

        
        
        
                
        
        @GetMapping("/monitorear")
        public String monitorear(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.kill();
            ardLeo.enviarDato("5");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail(correo, asuntoMail, "Sistema En Monitoreo");
            req.setAttribute("info", ardLeo.getInfo());
            req.setAttribute("s1", ardLeo.getS1());
            req.setAttribute("s2", ardLeo.getS2());
            req.setAttribute("s3", ardLeo.getS3());
            
            jdbcTemplate.update(
                    "insert into bitacoraSensores (registro,sensor1,sensor2,sesnor3,  comentario ) values (?,?,?,?,?)",
                    0, ardLeo.getS1(), ardLeo.getS2(), ardLeo.getS3(),  ardLeo.getInfo()
            );
            
            //String sql = "SELECT * FROM bitacoraSensores ORDER BY registro DESC LIMIT 7 ";
            String sql = "select * from usuarios order by id desc";
            List datos = this.jdbcTemplate.queryForList(sql);
            req.setAttribute("datos", datos);
            
             sql = "SELECT * FROM bitacoraSensores ORDER BY registro DESC LIMIT 7 ";
            //String sql = "select * from usuarios order by id desc";
            List dato = this.jdbcTemplate.queryForList(sql);
            req.setAttribute("dato", dato);
            
            return "clima";

        }
        
        @GetMapping("/switchOneON")
        public String switchOneON(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("1");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta DOMOTICA", "Switch 1 Encendido");
            return "domotica";

        }
        
        @GetMapping("/switchOneOff")
        public String switchOneOff(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("2");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta DOMOTICA", "Switch 1 Apagado");
            return "domotica";

        }
        
        
        
        @GetMapping("/switchTwoON")
        public String switchTwoON(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("3");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta DOMOTICA", "Switch 1 Encendido");
            return "domotica";

        }
        
        @GetMapping("/switchTwoOff")
        public String switchTwoOff(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            ardLeo.enviarDato("4");
            SendMailGmail sendM = new SendMailGmail();
            sendM.enviarMail("norellanac@miumg.edu.gt", "Alerta DOMOTICA", "Switch 1 Apagado");
            return "domotica";

        }
        
        
    
}