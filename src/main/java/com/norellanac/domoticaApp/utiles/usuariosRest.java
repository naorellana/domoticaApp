/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.norellanac.domoticaApp.utiles;



import com.norellanac.domoticaApp.models.Usuarios;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 *
 * @author mmendez
 */
@RestController
public class usuariosRest {
    
    @RequestMapping(
            value = "rest/{nombre}/{apellido}",
            method = RequestMethod.GET,
            produces = "application/json")
    public String getCadenaJSON(
            @PathVariable String nombre,
            @PathVariable String apellido
    ) {
        String cadena = "{\"mensaje\":\"" + "hola " + nombre + " " + apellido + "\"}";
        return cadena;
    }
    //ingresar a localhost:puerto/rest/nombre/apellido
    
    @RequestMapping(
            value = "rest",
            method = RequestMethod.POST,
            consumes = "application/json",
            produces = "application/json")
    public Usuarios getPersona(@RequestBody Usuarios request) {
        Usuarios usuarios = new Usuarios();
        usuarios.setId(10);
        usuarios.setNombre("hola " + request.getNombre());  
        usuarios.setCorreo(request.getCorreo());
        usuarios.setTelefono(request.getTelefono());
        return usuarios;
    }
    //enviar peticion post con JSON
    /*
    {
    "id": "1",
    "nombre": "nery",
    "correo":"mail",
    "telefono":"50"
    }
    */
}
