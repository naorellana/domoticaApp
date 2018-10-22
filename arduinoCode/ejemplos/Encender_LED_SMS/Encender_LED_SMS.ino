#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);//Configarión de los pines serial por software
char caracter=0;// Variable para guardar los caracteres mensajes entrantes
int led=12;
String estado="";
void setup() {
   SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
   Serial.begin(9600);//Velocidad del puerto serial de arduino 
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
      estado="led encendido";
      hacerLlamada();
      //envioMensaje(estado);
      }
    if(caracter=='L'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, LOW);
      estado="led apagado";
      hacerLlamada();
      //envioMensaje(estado);
      }  
  }
}
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
  delay(10000);//Duración del llamado antes de cortar
  SIM900.println("ATH"); // comando AT cortar llamada
  Serial.println("Llamada finalizada");//Leyenda que indica que finalizó el llamado
}
