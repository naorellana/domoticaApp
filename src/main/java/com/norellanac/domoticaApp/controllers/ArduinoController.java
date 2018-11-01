package com.norellanac.domoticaApp.controllers;



import com.norellanac.domoticaApp.models.Conectar;
import com.norellanac.domoticaApp.utiles.SendMailGmail;
import com.norellanac.domoticaApp.utiles.arduinoRecibe2EnviaString;
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
public class ArduinoController {
    //@Autowired	
    private  static JdbcTemplate jdbcTemplate;
    private static    Conectar con=new Conectar();
    arduinoRecibe2EnviaString ard=new arduinoRecibe2EnviaString();
    fechasNorellanac fecha= new fechasNorellanac();
   

    
    @GetMapping("/clima")
	public String clima(HttpServletRequest req) {
                return "clima";
	}
        
        @GetMapping("/domotica")
        public String domotica(HttpServletRequest req) {
            return "domotica";
        }
            
        
    
}