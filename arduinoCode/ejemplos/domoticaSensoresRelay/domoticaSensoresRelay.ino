#include <SoftwareSerial.h>

SoftwareSerial BT1(0,1); // RX, TX
const int LEDBT = 3;
const int BTPWR = 2;
//Bluetooth
char nombreBT[10] = "domotica";
char velocidad = '4';
char pin[5] = "0000"; 

// 8,9,10 para led
int LED_one = 8;
int LED_two = 9;
int LED_tree = 10;

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

  }
     
  
void loop() {
  //mensaje que muestra valore een patlla, solo necesario para arduino LEONARDO
  Msg("0");
  
        // send data only when you receive data SERIAL app WEB:
        if (Serial.available() > 0) {
                // read the incoming byte:
                texto=Serial.readString();
                if (texto.toInt()==1){
                  dispositivo="LED 1 Encendido";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchOneOn();
                }
                if (texto.toInt()==2){
                  dispositivo="LED1 APAGADO";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchOneOff();
                }
                if (texto.toInt()==3){
                  dispositivo="LED 2 Encendido";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchTwoOn();
                }
                if (texto.toInt()==4){
                  dispositivo="LED 2 APAGADO";
                  Serial.println(dispositivo);
                  dataSensor1();
                  Serial.println(sensor2,3);
                  Serial.println(sensor3,3);
                  switchTwoOff();
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
void dataSensor1(){
  sensor1=random(30);
  Serial.println(sensor1,3);
}

