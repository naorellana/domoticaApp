  /* Conexion pines
     Arduino        GPS         
        D3           RX
        D4           TX
  */

  #include <SoftwareSerial.h>  //incluimos SoftwareSerial
  #include <TinyGPS.h>         //incluimos TinyGPS

  TinyGPS gps;  //Declaramos el objeto GPS
  SoftwareSerial serialgps(4,3);      //Declaramos el pin 4 (Tx del GPS) y 3 (Rx del GPS)
   
  //Declaramos la variables para la obtención de datos
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long chars;
  unsigned short sentences, failed_checksum;
float latitude=14.51420, longitude=-90.39943;

  
  SoftwareSerial SIM900(7, 8);//Configarión de los pines serial por software
char caracter=0;// Variable para guardar los caracteres mensajes entrantes
int led=12;
String estado="";


  void setup()
  {
   Serial.begin(9600);  //Iniciamos el puerto serie 115200
  // serialgps.begin(9600); //Iniciamos el puerto serie del gps
   
   //Imprimimos en el monitor serial:
   Serial.println("");
   Serial.println("GPS GY-GPS6MV2 Leantec");
   Serial.println(" ---Buscando senal--- ");  
   Serial.println("");
      SIM900.begin(19200);//Arduino se comunica con el SIM900 a una velocidad de 19200bps
   //Serial.begin(9600);//Velocidad del puerto serial de arduino 
   delay(20000);//Tiempo prudencial para el escudo inicie sesión de red con tu operador
 pinMode(led, OUTPUT);
  SIM900.print("AT+CMGF=1\r");// comando AT para configurar el SIM900 en modo texto
  delay(200);
  SIM900.print("AT+CNMI=2,2,0,0,0\r");//Configuramos el módulo para que muestre los SMS por el puerto serie.
  delay(200);
  }

  void muestraDatosGPS()  {
   while(serialgps.available()) 
   {
    int c = serialgps.read(); 
    if(gps.encode(c)) 
    {
     float latitude, longitude;
     gps.f_get_position(&latitude, &longitude);
     Serial.print("Latitud/Longitud: "); 
     Serial.print(latitude,5); 
     Serial.print(", "); 
     Serial.println(longitude,5);
     gps.crack_datetime(&year,&month,&day,&hour,&minute,&second,&hundredths);
     Serial.print("Fecha: "); Serial.print(day, DEC); Serial.print("/"); 
     Serial.print(month, DEC); Serial.print("/"); Serial.print(year);
     Serial.print(" Hora: "); Serial.print(hour, DEC); Serial.print(":"); 
     Serial.print(minute, DEC); Serial.print(":"); Serial.print(second, DEC); 
     Serial.print("."); Serial.println(hundredths, DEC);
     Serial.print("Altitud (metros): "); Serial.println(gps.f_altitude()); 
     Serial.print("Rumbo (grados): "); Serial.println(gps.f_course()); 
     Serial.print("Velocidad(kmph): "); Serial.println(gps.f_speed_kmph());
     Serial.print("Satelites: "); Serial.println(gps.satellites());
     Serial.println();
     
    delay(2000);
     gps.stats(&chars, &sentences, &failed_checksum);
    }
   }
  }



void loop() {  
  SIM900.listen();
  //hacerLlamada();
  if(SIM900.available() >0) {//Verificamos si hay datos disponibles desde el SIM900
    caracter=SIM900.read(); // Leemos los datos y los almcanamos en la variable mensaje
    Serial.print(caracter); //Imprime los datos entrantes uno a uno en el terminal serial
    if(caracter=='H'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, HIGH);
      estado="led encendido";
      envioMensaje(estado);
      }
    if(caracter=='L'){
      Serial.println("-->enviando mensaje");
      digitalWrite(led, LOW);
      estado="led apagado";
      envioMensaje(estado);
      }  
  }
}
void envioMensaje(String estado) {
  SIM900.print("AT+CMGF=1\r"); // AT command to send SMS message
delay(100);
  SIM900.println("AT+CMGS=\"+50235351566\"");//reemplzar por el número a enviar el mensaje
  delay(200);
  SIM900.println("Estado:" + estado);// Reemplzar por el texto a enviar
  delay(200);
  //Finalizamos este comando con el caracter de sustitución (→) código Ascii 26 para el envio del SMS
  SIM900.println((char)26); 
  delay(200);
  SIM900.println();
}

void hacerLlamada() {
  SIM900.print("ATD");//Comando AT para iniciar una llamada
  SIM900.print("+50235351566");//Número de telefono al cual queremos llamar
  SIM900.println(";");//El ";" indica llamada de voz y no llamada de datos ej:(FAX) 
  Serial.println("Llamando...");//Leyenda que indica que se inicio el llamado
  delay(20000);//Duración del llamado antes de cortar
  SIM900.println("ATH"); // comando AT cortar llamada
  Serial.println("Llamada finalizada");//Leyenda que indica que finalizó el llamado
}
