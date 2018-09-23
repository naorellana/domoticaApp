#include <SoftwareSerial.h>
String text;
int Pecho= 11;
int Ptrig= 10;
long duracion, distancia;

int i=1;

void setup() {
  Serial.begin (9600);      // inicializa el puerto serial a 9600 baudios
  pinMode(Pecho, INPUT);    // define el pin 6 como entrada (echo)
  pinMode(Ptrig, OUTPUT);   // define el pin 7 como salida  (triger)
  pinMode(13,1);            // define el pin 13 como salida
  delay(100);
delay(1);
Msg("test");
if (Serial.available() <1) {
  Serial.println("leo");
}
  }
     
  
void loop() {
  
Msg("test");
if (i==1){
  Serial.println("Leonardo");
  Serial.println("Leonardo");
  i++;
}
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                text=Serial.readString();
                // say what you got:
                
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH); //  genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;    // calcula la distancia en centimetros

  if (distancia >= 500 || distancia <= 0){  //  si la distancia en mayor a 500cm o menor a 0cm
    Serial.println("FUERA DE ALCANCE");
    Serial.println("FUERA DE ALCANCE");// no mide nada
  }
  else {
    Serial.println("Distancia");
    Serial.print(distancia);                //  envia el valor de la distancia por el puerto serial
    Serial.println("cm");                   // le coloca a la distancia los centimetros "cm"
    digitalWrite(13,0);                     // en bajo el pin 13
    }

  if (distancia <= 10 && distancia >= 1){
    digitalWrite(13, 1);                    // en alto el pin 13 si ladistancia es menor a 10cms
    Serial.println("Alarma.......");  
    Serial.print(distancia);                //  envia el valor de la distancia por el puerto serial
    Serial.println("cm"); // envia la palabra Alarma por el puerto serial
    }
    delay(400);
                
                
        }
}

void inicio(){  
while (!Serial); { // For Yun/Leo/Micro/Zero/...
Serial.println("Arduino");
Serial.println("Arduino");}
} 

void Msg(String msg)
{
  if( !Serial ) {    
    Serial.println(msg);
    
    Serial.println(msg);
  } 
} 
