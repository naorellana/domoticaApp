#include <SoftwareSerial.h>
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 5
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial BT1(0,1); // RX, TX
const int LEDBT = 3;
const int BTPWR = 2;
//Bluetooth
char nombreBT[10] = "domotica";
char velocidad = '4';
char pin[5] = "0000"; 

// 8,9,10 para led
int LED_one = 9;
int LED_two = 10;
int LED_tree = 11;

int ldrPin = 0; // LDR en el pin analogico 0
int ldrValue = 0;

//variables para app web
String texto;
String dispositivo;
float  sensor1=1.1;
float sensor2=2.2; 
float sensor3=3.3;

void setup() {
  Serial.begin (9600);      // inicializa el puerto serial a 9600 baudios
  /*Bluetooth configuracion*/
  pinMode(LEDBT, OUTPUT);//APAGA LOS PINES
  pinMode(BTPWR, OUTPUT);//APAGA LOS PINES
  
  digitalWrite(LEDBT, LOW);//VALOR BAJO
  digitalWrite(BTPWR, HIGH);//VALOR ALTO, PARA QUE EL BT ESTE ABAJO HASTA QUE EL PROGRAMA ESTE ARRIBA Y EL BT FUNCIONE
  Serial.begin(9600);
  
  digitalWrite(LEDBT, HIGH);
  /*FIN Bluetooth configuracion*/
  pinMode( LED_one, OUTPUT );
  pinMode( LED_two, OUTPUT );
  pinMode( LED_tree, OUTPUT );

  MsgSensoresInicialUNO();
  }
     
  
void loop() {
  ldrValue = analogRead(ldrPin); 
//Serial.println(ldrValue);
if (ldrValue >= 1010){
digitalWrite(LED_one,HIGH);
}
else {
digitalWrite(LED_one,LOW);
}
  //mensaje que muestra valore een patlla, solo necesario para arduino LEONARDO
  //Msg("0.1");
  //MsgSensoresInicial();
  
        // send data only when you receive data SERIAL app WEB:
        if (Serial.available() > 0) {
                // read the incoming byte:
                texto=Serial.readString();
                if (texto.toInt()==1){
                  dispositivo="Encendido";
                  Serial.println(dispositivo);
                  delay(200);// milesimas segundo 
                  dataSensor1();
                  delay(200);// milesimas segundo 
                  Serial.println(sensor2,3);
                  delay(200);// milesimas segundo 
                  Serial.println(sensor3,3);
                  delay(200);// milesimas segundo 
                  switchOneOn();
                  delay(200);// milesimas segundo 
                }
                if (texto.toInt()==2){
                  dispositivo="APAGADO";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchOneOff();
                }
                if (texto.toInt()==3){
                  dispositivo="Encendido";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchTwoOn();
                }
                if (texto.toInt()==4){
                  dispositivo="APAGADO";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchTwoOff();
                }
                if (texto.toInt()==5){
                  dispositivo="Monitoreo";
                  Serial.println(dispositivo);
                  dataSensor1();
                  dataSensor2();
                  dataSensor3();
                }
        }

        //*************
        BT1.listen();
        if(BT1.available()){
          char COM_value = Serial.read();
          controlPuertasLuces(COM_value);
        }
        
}

//****************funcion para imprimir en el setup de arduino LEONARDO********
void Msg(String msg)
{
  if( !Serial ) {    
    for(int i=0; i<4;i++){
     
    Serial.println(msg); 
    }
  } 
} 

void MsgSensoresInicial()
{
  if( !Serial ) {    
    dispositivo="Arrancando";
                  Serial.println(0.1);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
  } 
} 

void MsgSensoresInicialUNO()
{
dispositivo="Arrancando";
                  Serial.println(dispositivo);
                  dataSensor1();
                  dataSensor2();
                  dataSensor3();
} 



//funcion que recibe para puertas o luces
void controlPuertasLuces(char COM_value){

                if( COM_value == 'a' )
                {
                    digitalWrite( LED_one, HIGH ); // HIGH VOLTAGE - TURNED ON
                }
                if( COM_value == 'b' )
                {
                    digitalWrite( LED_one, LOW ); // HIGH VOLTAGE - TURNED ON
                }
                
                if( COM_value == 'c' )
                {
                    digitalWrite( LED_two, HIGH ); // HIGH VOLTAGE - TURNED ON
                }
                if( COM_value == 'd' )
                {
                    digitalWrite( LED_two, LOW ); // HIGH VOLTAGE - TURNED ON
                }
                
                if( COM_value == 'e' )
                {
                     digitalWrite( LED_tree, HIGH ); // HIGH VOLTAGE - TURNED ON        
                }
                if( COM_value == 'f' )
                {
                      digitalWrite( LED_tree, LOW ); // HIGH VOLTAGE - TURNED ON
                }

}
//***************************************************

//************ FUNCION ACTIVAR SWWITCH1 110V ***************
void switchOneOn(){
  //activar el switch 110v
    pinMode(LED_one, OUTPUT); // Configurar relay como salida o OUTPUT
    //Serial.println("switchON");
    delay(200);// milesimas segundo 
    digitalWrite(LED_one, HIGH);
}
void switchOneOff(){
  //activar el switch 110v
    pinMode(LED_one, OUTPUT); // Configurar relay como salida o OUTPUT
    //Serial.println("switchOFF");
    delay(200);// milesimas segundo 
    digitalWrite(LED_one, LOW);
}
//***************************

//************ FUNCION ACTIVAR SWWITCH2 110V ***************
void switchTwoOn(){
  //activar el switch 110v
    pinMode(LED_two, OUTPUT); // Configurar relay como salida o OUTPUT
    //Serial.println("switchON");
    delay(200);// milesimas segundo 
    digitalWrite(LED_two, HIGH);
}
void switchTwoOff(){
  //activar el switch 110v
    pinMode(LED_two, OUTPUT); // Configurar relay como salida o OUTPUT
    //Serial.println("switchOFF");
    delay(200);// milesimas segundo 
    digitalWrite(LED_two, LOW);
}
//***************************


//**********fucion que devuelve dato de un sensor (en este caso genera un dato random)***
void dataSensor1(){ ///TEMPERATURA
  sensor1=dht.readTemperature();
  Serial.println(sensor1,3);
}

void dataSensor2(){ //HUMEDAD %
    sensor2=dht.readHumidity();
  Serial.println(sensor2,3);
}

void dataSensor3(){ //INTENSIDAD DE LUZ
  ldrValue = analogRead(ldrPin);
    sensor3=1020-ldrValue;
  Serial.println(sensor3,3);
}
void dataSensorA(){
  //sensor1=random(30);
  //Serial.println(sensor1,3);
  
  //delay(5000);// Esperamos 5 segundos entre medidas
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" C");
}
