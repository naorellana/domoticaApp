/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.norellanac.domoticaApp.utiles;

/**
 *
 * @author mmendez
 */
public class TestThread extends Thread {
    
    @Override
    public void run() {
        
        while (true) {
            try {
                
                
                System.out.println("Enviando mensaje....");
                //Thread.sleep(500);
                
            } catch (Exception e) {
                System.out.println("Error....");
                e.printStackTrace();
            }
        }
    }
    
}
