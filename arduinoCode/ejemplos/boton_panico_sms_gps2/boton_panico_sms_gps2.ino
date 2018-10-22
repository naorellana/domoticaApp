#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);//Configarión de los pines serial por software
char caracter=0;// Variable para guardar los caracteres mensajes entrantes
int led=12;
String estado="";
void setup() {
   SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
   Serial.begin(19200);//Velocidad del puerto serial de arduino 
   delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador
 pinMode(led, OUTPUT);
  SIM900.print("AT+CMGF=1\r");// comando AT para configurar el SIM900 en modo texto
  delay(200);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");//Configuramos el módulo para que muestre los SMS por el puerto serie.
  delay(200);
}
void loop() {  
  if(SIM900.available() >0) {//Verificamos si hay datos disponibles desde el SIM900
    caracter=SIM900.read(); // Leemos los datos y los almcanamos en la variable mensaje
    Serial.print(caracter); //Imprime los datos entrantes uno a uno en el terminal serial
    if(caracter=='H'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, HIGH);
      estado="https://maps.google.com/?q=14.557060,-90.734058&z=19";
      envioMensaje(estado);
      }
    if(caracter=='L'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, LOW);
      estado="dispositivo apagado";
      envioMensaje(estado);
      }  
  }
}
void envioMensaje(String estado) {
  SIM900.println("AT + CMGS = \"+50255176044\"");//reemplzar por el número a enviar el mensaje
  delay(200);
  SIM900.println("Estado:" + estado);// Reemplzar por el texto a enviar
  delay(200);
  //Finalizamos este comando con el caracter de sustitución (→) código Ascii 26 para el envio del SMS
  SIM900.println((char)26); 
  delay(200);
  SIM900.println();
}
