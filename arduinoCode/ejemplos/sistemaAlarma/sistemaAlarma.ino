//en arduino leonardo conectar a pines digitales 2 y 3
//en arduio uno conectar a pines analogicos 4 y 5
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
String a="1 ACTIIVAR";
String b="2 DESACTIVAR";
String secret="3190";   //contraseña
int contador=2;


#include<Keypad.h>
const byte filas = 4;
const byte columnas = 4;
byte pinesF[filas] = {11,10,9,8};
byte pinesC[columnas] = {7,6,5,4};
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
  imprimirPantalla(a,b); 
}
void loop() {
  if (contador<3){
    
  }
  else{
    imprimirPantalla("BLOQUEDO","BLOQUEDO");
    delay(5000);
    imprimirPantalla(a,b);
    contador=0;
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
        contador=0;
        delay(2000);
        imprimirPantalla(a,b);
      }
      else{
        imprimirPantalla("ERROR","INTENTE DE NUEVO");
        contador++;
        delay(2000);
        imprimirPantalla("INTENTO FALLIDO","PRES 1 pra activar");
      }
  }
  if (tecla=='2'){
      int i=0;
      String clave="";
      String mascaraTexto="";
      imprimirPantalla("INGRESE","CONTRASENA");
      while (i<4){
        if(tecla = teclado.getKey()){
          i++;
          clave=clave+tecla;
          mascaraTexto=mascaraTexto+'*';
          imprimirPantalla("CONTRASENA",mascaraTexto);
        }
      }
      if (clave==secret){
        imprimirPantalla("SISTEMA DESACTIVADO","PRES 1 para activar");
        delay(2000);
        imprimirPantalla(a,b);
      }
      else{
        imprimirPantalla("ERROR","INTENTE DE NUEVO");
        delay(2000);
        imprimirPantalla(a,b);
      }
  }
}
               if (Serial.available() > 0) {
                // read the incoming byte:
                tecla = Serial.read();
                if (tecla=='1'){
                    Serial.println("presiono uno");
                    imprimirPantalla("Presiono","UNO");
                  }
                  if (tecla=='2'){
                    Serial.println("presiono Dos");
                  }
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

