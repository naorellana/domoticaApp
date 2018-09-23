package com.norellanac.domoticaApp.controllers;



import com.norellanac.domoticaApp.models.Conectar;
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
   

    
    @GetMapping("/inicio1")
	public String init(HttpServletRequest req) {
                return "index";
	}
    @GetMapping("/control")
	public void delete(@RequestParam String motor, HttpServletRequest req, HttpServletResponse resp) throws IOException {
                //String sql="select * from usuarios order by id desc";
                //List usuarios=this.jdbcTemplate.queryForList(sql);
		//req.setAttribute("usuarios",usuarios);
                System.out.println("Comando: "+ motor);
                serialComArduino comArduino= new serialComArduino();
        comArduino.enviaDatoArduino(motor);
                resp.sendRedirect("/inicio1");
                
        }
        
        @GetMapping("/test")
	public String test(HttpServletRequest req) {
                //req.setAttribute("datos",datos);
		//req.setAttribute("mode", "BOOK_VIEW");
		return "crudHuellaBETA";
	}
        
        @GetMapping("/beta")
	public void beta(@RequestParam String codigo, HttpServletRequest req, HttpServletResponse resp) throws IOException {
                //String sql="select * from usuarios order by id desc";
                //List usuarios=this.jdbcTemplate.queryForList(sql);
		//req.setAttribute("usuarios",usuarios);
                System.out.println("Comando: "+ codigo);
                System.out.println("El codigo enviado es: " +codigo);
                System.out.println(codigo.substring(0,1));
                System.out.println(Integer.parseInt(codigo.substring(2, codigo.length())));
                if (Integer.parseInt(codigo.substring(0,1))  ==3){
                   /* jdbcTemplate=new JdbcTemplate(con.conectar());
                        jdbcTemplate.update
                            (
                            "insert into ingresos_per (usuario_id,fecha,hora,marca,observacion ) values (?,?,?,?,?)",
                             Integer.parseInt(codigo.substring(2, codigo.length())),fecha.date(),fecha.time(),1,"ingresando desde java");*/
                }
                arduinoRecibe2EnviaString ard=new arduinoRecibe2EnviaString();
                
                 try{
                     Thread.sleep(5);
                }catch(InterruptedException e){}
                ard.enviarDato(codigo);
                resp.sendRedirect("/");
                
        }
        
        @GetMapping("/kill")
	public String beta(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
                //String sql="select * from usuarios order by id desc";
                //List usuarios=this.jdbcTemplate.queryForList(sql);
		//req.setAttribute("usuarios",usuarios);
                
                
                 try
        {
            Thread.sleep(5);
        }catch(InterruptedException e){}
                ard.kill();
                ard.getCode();
                req.setAttribute("codigo",ard.getCode());
                req.setAttribute("valor",ard.getVal());
                System.out.println(ard.getCode());
                System.out.println(ard.getVal());
                return "index";
                
        }
        
        @GetMapping("/ard")
        public String ard(@RequestParam String codigo, HttpServletRequest req, HttpServletResponse resp) {
            arduinoRecibe2EnviaString ard = new arduinoRecibe2EnviaString();
             Thread thread = new Thread() {
                public void run() {
                    //System.out.println("Thread Running");
                    req.setAttribute("codigo", ard.getCode());
                    req.setAttribute("valor", ard.getVal());
                    }
                };
            thread.start();
            try {
                Thread.sleep(5);
            } catch (InterruptedException e) {
            }
            ard.enviarDato(codigo);
            //resp.sendRedirect("/");
            
            req.setAttribute("action", "save");
            return "home";
        }
        
        @GetMapping("/graf")
        public String graf(HttpServletRequest req, HttpServletResponse resp) throws IOException, ArduinoException, SerialPortException {
            //String sql="select * from usuarios order by id desc";
            //List usuarios=this.jdbcTemplate.queryForList(sql);
            //req.setAttribute("usuarios",usuarios);
           // ard.kill();
            ard.getCode();
            req.setAttribute("codigo", ard.getCode());
            req.setAttribute("valor", ard.getVal());
            //System.out.println(ard.getCode());
            //System.out.println(ard.getVal());
            return "index";

        }

    
}