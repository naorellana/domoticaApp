//******************modulos lcd******
//en arduino leonardo conectar a pines digitales 2 y 3
//en arduio uno conectar a pines analogicos 4 y 5
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//**************MODULO SIM900********
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);//Configarión de los pines serial por software
char caracter=0;// Variable para guardar los caracteres mensajes entrantes
String mensaje="";


String a="1 ACTIIVAR";
String b="2 DESACTIVAR";
String monitoreo="sin alertas";
String secret="3190";   //contraseña
int contador=0;
int intentos=1;
boolean estado=true;
int tiempoBloqueo=3; //en segundos

const int buzzer = A3; //buzzer to arduino pin 5d
byte sensorpir = 12;
byte led=A1;
byte botonMagnetico=13;

#include<Keypad.h>
const byte filas = 4;
const byte columnas = 4;
byte pinesF[filas] = {11,10,9,3};//cables de izquierda a derecha
byte pinesC[columnas] = {2,6,5,4};//continuacion cables de izquierda a derecha
//SE CAMBIAN PINES 7 Y 8 PARA USO DE SIM900
 String texto="";
char teclas[filas][columnas] = {
 
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
 
Keypad teclado = Keypad(makeKeymap(teclas), pinesF, pinesC, filas, columnas);
 
char tecla;
 
void setup() {
  Serial.begin(9600);
  SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
  imprimirPantalla("CONECTANDO SIM","BUSCNDO RED"); 
  //delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador
  SIM900.print("AT+CMGF=1\r");// comando AT para configurar el SIM900 en modo texto
  delay(200);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");//Configuramos el módulo para que muestre los SMS por el puerto serie.
  delay(200);
  imprimirPantalla(a,b); 
  pinMode(led, OUTPUT);
  pinMode(sensorpir, INPUT);
  pinMode(botonMagnetico,INPUT);
  Serial.println("sistema De alarma");
  Serial.println("Sistema De alarma");
}
void loop() {

  //activa led de alerta o buzzer si estado es true y hay movimiento en sensores
  if(digitalRead(sensorpir) == HIGH && estado==true){
    digitalWrite(led, HIGH);
    monitoreo="Alerta De Movimiento";  
    monitoreo="Alerta De Movimiento";
    sonido(1);
  }
  else{
    digitalWrite(led, LOW);
  }
  //activa led de alerta o buzzer si estado es true y hay cambios en sensor mgnetico(simulado por un switch)
  if(digitalRead(botonMagnetico) == LOW && estado==true){
    digitalWrite(led, HIGH);
    monitoreo="Alerta En Cerradura";  
    monitoreo="Alerta En Cerradura";
    sonido(1);
  }
  else{
    digitalWrite(led, LOW);
    
  }

  //bloquea cuando se ha llegado al limite de intento
  String letra="";
  if (contador<intentos){
if (Serial.available() > 0) {
      // read the incoming byte:
      letra = Serial.readString();
      if (letra.toInt()==1){
        Serial.println("SISTEMA ACTIVADO, PRES 2, DESACTIVAR");
        Serial.println("SISTEMA ACTIVADO, PRES 2, DESACTIVAR");
        imprimirPantalla("SISTEMA ACTIVADO","PRES 2, DESACTIVAR");
        //monitorear
        estado=true;
      }
      if (letra.toInt()==2){
        Serial.println("SISTEMA DESACTIVADO, PRES 1, activar");
        Serial.println("SISTEMA DESACTIVADO, PRES 1, activar");
         imprimirPantalla("SISTEMA DESACTIVADO","PRES 1, activar");
         //hacerLlamada();
        //monitorear
        estado=false;
      }
      if (letra.toInt()==3){
        Serial.println(monitoreo);
                Serial.println(monitoreo);
        }
    }
    
    if(tecla = teclado.getKey()){ //si se ingresan datos por telcado matricial
    if (tecla=='3'){
      imprimirPantalla("Opcion","PRUEBAS");
    }
    if (tecla=='1'){
      int i=0;
      String clave="";
      String mascaraTexto="";
      imprimirPantalla("INGRESE CLAVE","ACTIVANDO");
      while (i<4){
        if(tecla = teclado.getKey()){
          i++;
          clave=clave+tecla;
          mascaraTexto=mascaraTexto+'*';
          imprimirPantalla("CONTRASENA",mascaraTexto);
        }
      }
      if (clave==secret){
        imprimirPantalla("SISTEMA ACTIVADO","PRES 2, DESACTIVAR");
        //monitorear
        estado=true;
        contador=0;
        delay(2000);
        imprimirPantalla(a,b);
      }
      else{
        imprimirPantalla("ERROR","INTENTE DE NUEVO");
        contador++;
        delay(1000);
        imprimirPantalla("INTENTO FALLIDO","PRES 1 pra activar");
      }
  }
  if (tecla=='2'){
      int i=0;
      String clave="";
      String mascaraTexto="";
      imprimirPantalla("INGRESE CLAVE","DESACTIVANDO");
      while (i<4){
        if(tecla = teclado.getKey()){
          i++;
          clave=clave+tecla;
          mascaraTexto=mascaraTexto+'*';
          imprimirPantalla("CONTRASENA",mascaraTexto);
        }
      }
      if (clave==secret){
        imprimirPantalla("SISTEMA DESACTIVADO","PRES 1, activar");
        //monitorear
        estado=false;
        contador=0;
        delay(2000);
        hacerLlamada();
        imprimirPantalla(a,b);
      }
      else{
        imprimirPantalla("ERROR","INTENTE DE NUEVO");
        contador++;
        delay(1000);
        imprimirPantalla("INTENTO FALLIDO","PRES 1 pra desactivar");
      }
  }
}
  
  }
  else{
    imprimirPantalla("BLOQUEADO","BLOQUEADO");
    delay(tiempoBloqueo*1000);
    imprimirPantalla(a,b);
    contador=0;
  }
  
    


}

void imprimirPantalla(String t1, String t2){
  lcd.begin(16, 2);
  // Mover el cursor a la primera posición de la pantalla (0, 0)
  lcd.home ();
  // Imprimir en la primera linea
  lcd.print(t1);
  // Mover el cursor a la segunda linea (1) primera columna
  lcd.setCursor ( 0, 1 );
  // Imprimir otra cadena en esta posicion
  lcd.print(t2);
  // Esperar un segundo
  delay(1000);
}

void sensorMov(){
  
  if(digitalRead(sensorpir) == HIGH)
  {
    //dispLCD("Detectado Ingreso","Sensor Movimiento");
    Serial.println("Detectado Ingreso Sensor Movimiento");
    Serial.println("Detectado Ingreso Sensor Movimiento");
    sonido(1);
  delay(250);
  sonido(1);
  //delay(250);
  //sonido(1);
  }
  
}


//********** FUNCION DE TONO (BUZZER) ******************
void sonido(int segundos){
   
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(segundos*1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  //delay(1000);        // ...for 1sec
}
//******************************
void envioMensaje(String estado) {
  SIM900.println("AT + CMGS = \"+50233120413\"");//reemplzar por el número a enviar el mensaje
  delay(200);
  SIM900.println("Estado:" + estado);// Reemplzar por el texto a enviar
  delay(200);
  //Finalizamos este comando con el caracter de sustitución (→) código Ascii 26 para el envio del SMS
  SIM900.println((char)26); 
  delay(200);
  SIM900.println();}

void hacerLlamada() {
  SIM900.print("ATD");//Comando AT para iniciar una llamada
  SIM900.print("+50233120413");//Número de telefono al cual queremos llamar
  SIM900.println(";");//El ";" indica llamada de voz y no llamada de datos ej:(FAX) 
  Serial.println("Llamando...");//Leyenda que indica que se inicio el llamado
  delay(15000);//Duración del llamado antes de cortar
  SIM900.println("ATH"); // comando AT cortar llamada
  Serial.println("Llamada finalizada");//Leyenda que indica que finalizó el llamado
}
