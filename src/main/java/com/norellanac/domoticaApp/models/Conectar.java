
package com.norellanac.domoticaApp.models;

import org.springframework.jdbc.datasource.DriverManagerDataSource;

public class Conectar {
 
    public DriverManagerDataSource conectar()
    {
        DriverManagerDataSource dataSource=new DriverManagerDataSource();
        dataSource.setDriverClassName("com.mysql.jdbc.Driver");
        dataSource.setUrl("jdbc:mysql://localhost:3306/spring_test?useSSL=false"); //spring_test es el nombre de la base de datos
        dataSource.setUsername("root");
        dataSource.setPassword("");
        return dataSource;
        
    }
    //pruebas con tabla//
    /*
    CREATE TABLE `spring_test`.`usuarios` ( `id` INT NOT NULL , `nombre` VARCHAR(100) NOT NULL , `correo` VARCHAR(100) NOT NULL , `telefono` INT NOT NULL ) ENGINE = InnoDB;
    */
    
    //conexion a ORACLE11G//
    /*
    
    public DriverManagerDataSource conectar()
    {
        DriverManagerDataSource dataSource=new DriverManagerDataSource();
        dataSource.setDriverClassName("oracle.jdbc.OracleDriver");
        dataSource.setUrl("jdbc:oracle:thin:@172.17.0.1:1521:XE"); //ip del bridge de docker ya que oracle corre en docker
        dataSource.setUsername("TESTDB2");
        dataSource.setPassword("Oracle_11g");
        return dataSource;
        
    }
    
    */
}
