/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.norellanac.domoticaApp.utiles;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author ORELLANA CUY
 */
public class fechasNorellanac {
    //https://docs.oracle.com/javase/7/docs/api/java/text/SimpleDateFormat.html
    
    Date fechaActual = new Date();
    
    public String time(){
        SimpleDateFormat formato = new SimpleDateFormat("H:mm");
        String cadenaFecha = formato.format(fechaActual);
        return cadenaFecha;
    }
    
    public String date(){
        SimpleDateFormat formato = new SimpleDateFormat("yyyy-MM-dd");
        String cadenaFecha = formato.format(fechaActual);
        return cadenaFecha;
    }
    
}
