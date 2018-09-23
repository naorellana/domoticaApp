
package com.norellanac.domoticaApp.controllers;



import com.norellanac.domoticaApp.models.Conectar;
import com.norellanac.domoticaApp.models.Usuarios;
import com.norellanac.domoticaApp.utiles.arduinoRecibe2EnviaString;
import java.io.IOException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.servlet.ModelAndView;
import java.util.List;
import java.util.Map;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class HomeController {
    //@Autowired	
    private JdbcTemplate jdbcTemplate;
    public HomeController()
    {
        Conectar con=new Conectar();
        this.jdbcTemplate=new JdbcTemplate(con.conectar());
    }
    @GetMapping("/")
	public String init(HttpServletRequest req) {
                return "index";
	}
        
   
    @GetMapping("home")
    public ModelAndView home()
    {
        ModelAndView mav=new ModelAndView();
        String sql="select * from usuarios order by id desc";
        List datos=this.jdbcTemplate.queryForList(sql);
        mav.addObject("datos",datos);
        mav.setViewName("home");
        return mav;
    }
    
    
    
    @GetMapping("/new")
	public String neww(HttpServletRequest req) {
                //String sql="select * from usuarios order by id desc";
                //List usuarios=this.jdbcTemplate.queryForList(sql);
		//req.setAttribute("usuarios",usuarios);
		req.setAttribute("action", "save");
		return "add_U";
	}
    
    @GetMapping("save")
	public void guardar( @ModelAttribute Usuarios usuarios, BindingResult bindingResult, HttpServletResponse resp) throws IOException{
		jdbcTemplate.update
        (
        "insert into usuarios (id,nombre,correo,telefono, estado, rol ) values (?,?,?,?,?,?)",
         usuarios.getId(), usuarios.getNombre(),usuarios.getCorreo(),usuarios.getTelefono(), usuarios.getEstado(), usuarios.getRol()
        ); 
		//req.setAttribute("books", springService.findAllBooks());
		//req.setAttribute("mode", "BOOK_VIEW");
		resp.sendRedirect("/home");
	} 
        
       @GetMapping("edit")
	public String edit(@RequestParam int id, HttpServletRequest req) {
            String sql = "SELECT * FROM usuarios WHERE id='" + id+"'";
            List usuarios=this.jdbcTemplate.queryForList(sql);
		req.setAttribute("usuarios", usuarios.get(0));//obtiene un array con un registro en la posicion 0
                req.setAttribute("action", "update");
		return "add_U";
	} 
        
        @GetMapping("/delete")
	public void delete(@RequestParam long id, HttpServletRequest req, HttpServletResponse resp) throws IOException {
        this.jdbcTemplate.update(
                    "delete from usuarios "
                + "where "
                + "id=? ",
        id);
        //elimina huella arduino
        String codigo="";
        codigo="4,"+id;
        System.out.println("Comando: "+ codigo);
                arduinoRecibe2EnviaString ard=new arduinoRecibe2EnviaString();
                System.out.println("El codigo enviado es: " +codigo);
                ard.enviarDato(codigo);
        //fin arduino
        this.jdbcTemplate.update(
                    "delete from ingresos_per "
                + "where "
                + "usuario_id=? ",
        id);
        //DELETE FROM `ingresos_per` WHERE usuario_id=
        resp.sendRedirect("/home");
    }
        
        @GetMapping("/update")
	public void update( @ModelAttribute Usuarios u,  HttpServletResponse resp) throws IOException{
		jdbcTemplate.update(
                    "update usuarios "
                + "set nombre=?,"
                + " correo=?,"
                + "telefono=?, "
                + "rol=?, "
                + "estado=? "
                + "where "
                + "id=? ",
         u.getNombre(),u.getCorreo(),u.getTelefono(),u.getRol(), u.getEstado(), u.getId());
		resp.sendRedirect("/home");
	} 
    
}