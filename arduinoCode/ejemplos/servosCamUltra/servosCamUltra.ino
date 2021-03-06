// Includes the Servo library
#include <Servo.h>. 

#define Pecho 11
#define Ptrig 10
Servo myServo1;
Servo myServo2;



void setup() {
  Serial.begin (9600);      // inicializa el puerto serial a 9600 baudios
  pinMode(Pecho, INPUT);    // define el pin 11 como entrada (echo)
  pinMode(Ptrig, OUTPUT);   // define el pin 10 como salida  (triger)
  pinMode(13,1);            // define el pin 13 como salida LED

  myServo1.attach(12); // Define el pin del servo1
  myServo2.attach(7); // Define el pin del servo2
  }

void loop() {
servoUno();

}
boolean alertaCam(){
  boolean estado;
long distVar=ultraDistancia();
  if (distVar >= 200 || distVar <= 0){  //  si la distancia en mayor a 500cm o menor a 0cm
    Serial.println("FUERA DE ALCANCE");// no mide nada
    estado=false;
  }
  else {
    Serial.println("Distancia");
    Serial.println(distVar);                //  envia el valor de la distancia por el puerto serial
    digitalWrite(13,0);                     // en bajo el pin 13
    estado=false;
    }

  if (distVar <= 100 && distVar >= 1){
    digitalWrite(13, 1);                    // en alto el pin 13 si ladistancia es menor a 10cms
    Serial.println("****INTRUSO A MENOS DE UN METRO***.......");  
    estado=true;
    delay(1000);
    Serial.print(distVar);                //  envia el valor de la distancia por el puerto serial
    Serial.println("cm"); // envia la palabra Alarma por el puerto serial
    }
    delay(5); 
    return estado;  
}


void muestraDatos(){
  
long distVar=ultraDistancia();
  if (distVar >= 500 || distVar <= 0){  //  si la distancia en mayor a 500cm o menor a 0cm
    Serial.println("FUERA DE ALCANCE");
    Serial.println("FUERA DE ALCANCE");// no mide nada
  }
  else {
    Serial.println("Distancia");
    Serial.print(distVar);                //  envia el valor de la distancia por el puerto serial
    Serial.println("cm");                   // le coloca a la distancia los centimetros "cm"
    digitalWrite(13,0);                     // en bajo el pin 13
    }

  if (distVar <= 100 && distVar >= 1){
    digitalWrite(13, 1);                    // en alto el pin 13 si ladistancia es menor a 10cms
    Serial.println("Alarma.......");  
    Serial.print(distVar);                //  envia el valor de la distancia por el puerto serial
    Serial.println("cm"); // envia la palabra Alarma por el puerto serial
    }
    delay(5);   
}

long ultraDistancia(){
  long duracion, distancia;
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH); //  genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;    // calcula la distancia en centimetros
  return distancia;
}
void servoUno(){
  for(int i=15;i<=165;i=i+2){  
  myServo1.write(i);
  delay(30);
  if (alertaCam()==true){
    Serial.println("camara");
    myServo2.write(i);
  }
  }
  for(int i=165;i>15;i=i-2){  
  myServo1.write(i);
  delay(30);
  if (alertaCam()==true){
    Serial.println("camara");
    myServo2.write(i);
  }
   
  }
}
void servoDos(){
  for(int j=15;j<=165;j=j+2){  
  myServo2.write(j);
  delay(30);
  }
  for(int j=165;j>15;j=j-2){  
  myServo2.write(j);
  }
}

