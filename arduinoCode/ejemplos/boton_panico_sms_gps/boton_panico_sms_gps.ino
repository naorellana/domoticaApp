//*****************CONFIGURACIONES GPS ARDUINO UNO************************
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
//*************************************************************************************


//*********************CONFIGURACION GSM SIM900********************
#include <SoftwareSerial.h>;
SoftwareSerial SIM900(7, 8); // Configura el puerto serial para el SIM GSM

char incoming_char=0; //Variable que guarda los caracteres que envia el SIM GSM
int salir = 0;

//********************************************
  void setup()
  {
   Serial.begin(9600);  //Iniciamos el puerto serie 115200
   serialgps.begin(9600); //Iniciamos el puerto serie del gps
   
   //Imprimimos en el monitor serial:
   Serial.println("");
   Serial.println("GPS GY-GPS6MV2 Leantec");
   Serial.println(" ---Buscando senal--- ");  
   Serial.println("");
   SIM900.begin(19200); //Configura velocidad serial para el SIM
delay(25000); //Retardo para que encuentra a una RED
Serial.begin(19200); //Configura velocidad serial para el Arduino
Serial.println("OK"); //Mensaje OK en el arduino, para saber que todo va bien.
   gpsLatLon();
  }

  void loop()  {
    //muestraGps();
    llamar(); //Llama
mensaje_sms(); //Envia mensaje
//modo_recibe_mensaje();
for(;;)
{
if(SIM900.available()>0)
{

incoming_char=SIM900.read(); //Get the character from the cellular serial port.
Serial.print(incoming_char); //Print the incoming character to the terminal.
}
if(Serial.available()>0)
{
if(Serial.read() == 'A') break;
}
}
Serial.println("OK-2");

delay(100);
SIM900.println();
delay(30000);
while(1); // Espérate por tiempo indefinido

    gpsLatLon();
  }

String gpsLatLon(){
  String urlMap="https://maps.google.com/?q=";
  String urlSend="https://maps.google.com/?q=", lati, lon;
  
  while(serialgps.available()) {
    int c = serialgps.read(); 
    if(gps.encode(c)) 
    {
     float latitude, longitude;
     gps.f_get_position(&latitude, &longitude);
     lati=latitude;
     /*Serial.print("test: "+urlMap); 
     Serial.print(latitude,6); 
     Serial.print(","); 
     Serial.print(longitude,5);
     Serial.print("&z=19");
     Serial.println();
     Serial.println();*/
     urlSend="https://maps.google.com/?q="+ lati+","+longitude+"&z=19";
     Serial.println(urlSend);
    delay(2000);
     gps.stats(&chars, &sentences, &failed_checksum);
    }
    return urlSend; 
   }
   //return urlSend; 
}

  void muestraGps(){
    
   while(serialgps.available()) {
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


    void llamar()
// Función que permite llamar a un celular local
{
SIM900.println("ATD +50233120413;"); //Celular
delay(100);
SIM900.println();
delay(30000); // wait for 30 seconds...
SIM900.println("ATH"); // Cuelta el telefono
delay(1000);
}
void mensaje_sms()
//Funcion para mandar mensaje de texto
{

SIM900.print("AT+CMGF=1\r"); // AT command to send SMS message
delay(100);
SIM900.println("AT+CMGS=\"+50233120413\""); // recipient's mobile number, in international format
delay(100);
SIM900.println(gpsLatLon()); // message to send
delay(100);
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26 //Comando de finalizacion
delay(100);
SIM900.println();
delay(5000); // Tiempo para que se envie el mensaje
Serial.println("SMS sent successfully");
}

void espera_mensaje()
{
salir = 1;
while(salir==1)
{
if(SIM900.available()>0)
{
incoming_char=SIM900.read(); //Get the character from the cellular serial port.
Serial.print(incoming_char); //Print the incoming character to the terminal.
salir = 0;
}
}
}
void modo_recibe_mensaje()
{
//Configura el modo texto para enviar o recibir mensajes
SIM900.print("AT+CMGF=1\r"); // set SMS mode to text
delay(100);
SIM900.print("AT+CNMI=2,2,0,0,0\r");

// blurt out contents of new SMS upon receipt to the GSM shield's serial out
delay(1000);
}
