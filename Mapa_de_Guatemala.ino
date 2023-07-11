/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Francisco Barillas
 * Nombre: Byron Dávila
 * Carnet: 2019376
 * Carnet: 2019618
*/

//Librerias
#include <Wire.h>
#include <PCF8574.h>
#include <SoftwareSerial.h>

//Directivas de Preprocesador 
#define buzzerPin A0
#define Expansor_HIGH LOW  
#define Expansor_LOW HIGH  
#define Peten 2
#define Izabal 3
#define Alta_Verapaz 4
#define Baja_Verapaz 5
#define Huehuetenango 6
#define Quiche 7
#define Zacapa 22
#define Chiquimula 23
#define El_Progreso 24
#define Jalapa 25
#define Jutiapa 0
#define Guatemala 26
#define Totonicapan 27
#define Solola 28
#define Quetzaltenango 29
#define San_Marcos 30
#define Retalhuleu 31
#define Escuintla 32
#define Chimaltenango 33
#define Sacatepequez 34
#define Suchitepequez 35
#define Santa_Rosa 36

//Constructores
PCF8574 expansor_PCF(0x27);
SoftwareSerial BT(10, 11); // RX, TX  

//Variables
int num_de_pregunta;
String respuesta;

//Funciones
void incorrecta();
void Salidas();
void Led_Inicio();
void Preguntas();
int Numeros_Aleatorios();
void tiempo_de_respuesta();


void setup() 
  {
  Salidas();
  Led_Inicio();  
  Serial.begin(9600);
  expansor_PCF.begin();
  Wire.begin();
  BT.begin(9600);
  }  

void loop() {
  num_de_pregunta =  Numeros_Aleatorios();
  Preguntas();
}

int Numeros_Aleatorios() 
  {
  int Numeros = random(0, 21);
  return Numeros;
  }

void Salidas()
{
  pinMode(Peten, OUTPUT); 
  pinMode(Izabal, OUTPUT);
  pinMode(Alta_Verapaz, OUTPUT);
  pinMode(Baja_Verapaz, OUTPUT);
  pinMode(Huehuetenango, OUTPUT);
  pinMode(Quiche, OUTPUT);
  pinMode(Zacapa, OUTPUT);
  pinMode(Chiquimula, OUTPUT);
  pinMode(El_Progreso, OUTPUT);
  pinMode(Jalapa, OUTPUT);
  pinMode(Guatemala, OUTPUT);
  pinMode(Totonicapan, OUTPUT); 
  pinMode(Solola, OUTPUT);
  pinMode(Quetzaltenango, OUTPUT);
  pinMode(San_Marcos, OUTPUT);
  pinMode(Retalhuleu, OUTPUT);
  pinMode(Escuintla, OUTPUT);
  pinMode(Chimaltenango, OUTPUT); 
  pinMode(Sacatepequez, OUTPUT);
  pinMode(Suchitepequez, OUTPUT);
  pinMode(Santa_Rosa, OUTPUT);
}
void Led_Inicio()
{
  digitalWrite(Peten, HIGH);
  digitalWrite(Izabal, HIGH);
  digitalWrite(Alta_Verapaz, HIGH);
  digitalWrite(Baja_Verapaz, HIGH);
  digitalWrite(Huehuetenango, HIGH); 
  digitalWrite(Quiche, HIGH); 
  digitalWrite(Zacapa, HIGH);
  digitalWrite(Chiquimula, HIGH);
  digitalWrite(El_Progreso, HIGH);
  digitalWrite(Jalapa, HIGH);
  expansor_PCF.write(Jutiapa, Expansor_LOW);
  digitalWrite(Guatemala, HIGH);
  digitalWrite(Totonicapan, HIGH);
  digitalWrite(Solola, HIGH);
  digitalWrite(Quetzaltenango, HIGH);
  digitalWrite(San_Marcos, HIGH);
  digitalWrite(Retalhuleu, HIGH);
  digitalWrite(Escuintla, HIGH);
  digitalWrite(Chimaltenango, HIGH);
  digitalWrite(Sacatepequez, HIGH);
  digitalWrite(Suchitepequez, HIGH);
  digitalWrite(Santa_Rosa, HIGH);
}   


void Preguntas() {
  switch (num_de_pregunta) {
    case 0:
      BT.println("¿Cual es la cabecera departamental de Petén?");
      tiempo_de_respuesta();
      if (respuesta == String("Flores"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Peten, LOW);
        delay(5000);
        digitalWrite(Peten, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Flores");
        incorrecta();
      }
      break;
    case 1:
      BT.println("¿Cual es la cabecera departamental de Izabal?");
      tiempo_de_respuesta();
      if (respuesta == String("Puerto Barrios")){
        BT.println("Respuesta Correcta");
        digitalWrite(Izabal, LOW);
        delay(5000);
        digitalWrite(Izabal, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Puerto Barrios");
        incorrecta();
      }
      break;
      case 2:
      BT.println("¿Cual es la cabecera departamental de Alta Verapaz?");
      tiempo_de_respuesta();
      if (respuesta == String("Cobán")){
        BT.println("Respuesta Correcta"); 
        digitalWrite(Alta_Verapaz, LOW);
        delay(5000);
        digitalWrite(Alta_Verapaz, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Cobán");
        incorrecta();
      }
      break;
      case 3:
      BT.println("¿Cual es la cabecera departamental de Baja Verapaz?");
      tiempo_de_respuesta();
      if (respuesta == String("Salamá")){
        BT.println("Respuesta Correcta");
        digitalWrite(Baja_Verapaz, LOW);
        delay(5000);
        digitalWrite(Baja_Verapaz, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Salamá");
        incorrecta();
      }
      break;
      case 4:
      BT.println("¿Cual es la cabecera departamental de Huehuetenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Huehuetenango"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Huehuetenango, LOW);
        delay(5000);
        digitalWrite(Huehuetenango, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Huehuetenango");
        incorrecta();
      }
      break;
      case 5:
      BT.println("¿Cual es la cabecera departamental de Quiché?");
      tiempo_de_respuesta();
      if (respuesta == String("Santa Cruz del Quiché"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Quiche, LOW);
        delay(5000);
        digitalWrite(Quiche, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Santa Cruz del Quiché");
        incorrecta();
      }
      break;
       case 6:
      BT.println("¿Cual es la cabecera departamental de Zacapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Zacapa"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Zacapa, LOW);
        delay(5000);
        digitalWrite(Zacapa, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Zacapa");
        incorrecta();
      }
      break;
      case 7:
      BT.println("¿Cual es la cabecera departamental de Chiquimula?");
      tiempo_de_respuesta();
      if (respuesta == String("Chiquimula"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Chiquimula, LOW);
        delay(5000);
        digitalWrite(Chiquimula, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Chiquimula");
        incorrecta();
      }
      break;
      case 8:
      BT.println("¿Cual es la cabecera departamental de El Progreso?");
      tiempo_de_respuesta();
      if (respuesta == String("Guastatoya"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(El_Progreso, LOW);
        delay(5000);
        digitalWrite(El_Progreso, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Guastatoya");
        incorrecta();
      }
      break;
      case 9:
      BT.println("¿Cual es la cabecera departamental de Jalapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Jalapa"))
        {
        BT.println("Respuesta Correcta");
        digitalWrite(Jalapa, LOW);
        delay(5000);
        digitalWrite(Jalapa, HIGH); 
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Jalapa");
        incorrecta();
      }
      break;
      case 10:
      BT.println("¿Cual es la cabecera departamental de Jutiapa?");
      tiempo_de_respuesta();
      if (respuesta == String("Jutiapa")) {
        BT.println("Respuesta Correcta");
        expansor_PCF.write(0, Expansor_HIGH);
        delay(5000);
        expansor_PCF.write(0, Expansor_LOW);
      } else {
        BT.println("Incorrecto - Respuesta Correcta:Jutiapa");
        incorrecta();
      }
      break;
      case 11:
      BT.println("¿Cual es la cabecera departamental de Guatemala?");
      tiempo_de_respuesta();
      if (respuesta == String("Ciudad de Guatemala")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Guatemala, LOW);
        delay(5000);
        digitalWrite(Guatemala, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Ciudad de Guatemala");
        incorrecta();
      }
      break;
      case 12:
      BT.println("¿Cual es la cabecera departamental de Totonicapán?");
      tiempo_de_respuesta();
      if (respuesta == String("Totonicapán")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Totonicapan, LOW);
        delay(5000);
        digitalWrite(Totonicapan, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Totonicapán");
        incorrecta();
      }
      break;
      case 13:
      BT.println("¿Cual es la cabecera departamental de Sololá?");
      tiempo_de_respuesta();
      if (respuesta == String("Sololá")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Solola, LOW);
        delay(5000);
        digitalWrite(Solola, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Sololá");
        incorrecta();
      }
      break;
      case 14:
      BT.println("¿Cual es la cabecera departamental de Quetzaltenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Quetzaltenango")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Quetzaltenango, LOW);
        delay(5000);
        digitalWrite(Quetzaltenango, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Quetzaltenango");
        incorrecta();
      }
      break;
      case 15:
      BT.println("¿Cual es la cabecera departamental de San Marcos?");
      tiempo_de_respuesta();
      if (respuesta == String("San Marcos")) {
        BT.println("Respuesta Correcta");
        digitalWrite(San_Marcos, LOW);
        delay(5000);
        digitalWrite(San_Marcos, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: San Marcos");
        incorrecta();
      }
      break;
      case 16:
      BT.println("¿Cual es la cabecera departamental de Retalhuleu?");
      tiempo_de_respuesta();
      if (respuesta == String("Retalhuleu")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Retalhuleu, LOW);
        delay(5000);
        digitalWrite(Retalhuleu, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Retalhuleu");
        incorrecta();
      }
      break;
      case 17:
      BT.println("¿Cual es la cabecera departamental de Escuintla?");
      tiempo_de_respuesta();
      if (respuesta == String("Escuintla")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Escuintla, LOW);
        delay(5000);
        digitalWrite(Escuintla, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Escuintla");
        incorrecta();
      }
      break;
      case 18:
      BT.println("¿Cual es la cabecera departamental de Chimaltenango?");
      tiempo_de_respuesta();
      if (respuesta == String("Chimaltenango")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Chimaltenango, LOW);
        delay(5000);
        digitalWrite(Chimaltenango, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Chimaltenango");
        incorrecta();
      }
      break;
      case 19:
      BT.println("¿Cual es la cabecera departamental de Sacatepéquez?");
      tiempo_de_respuesta();
      if (respuesta == String("La Antigua Guatemala")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Sacatepequez, LOW);
        delay(5000);
        digitalWrite(Sacatepequez, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: La Antigua Guatemala");
        incorrecta();
      }
      break;
      case 20:
      BT.println("¿Cual es la cabecera departamental de Suchitepéquez?");
      tiempo_de_respuesta();
      if (respuesta == String("Mazatenango")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Suchitepequez, LOW);
        delay(5000);
        digitalWrite(Suchitepequez, HIGH);
      } else {
          BT.println("Incorrecto - Respuesta Correcta: Mazatenango");
        incorrecta();
      }
      break;
      case 21:
      BT.println("¿Cual es la cabecera departamental de Santa Rosa?");
      tiempo_de_respuesta();
      if (respuesta == String("Cuilapa")) {
        BT.println("Respuesta Correcta");
        digitalWrite(Santa_Rosa, LOW);
        delay(5000);
        digitalWrite(Santa_Rosa, HIGH);
      } else {
        BT.println("Incorrecto - Respuesta Correcta: Cuilapa");
        incorrecta();
      }
      break;
  }}

  void tiempo_de_respuesta() 
  {
    bool Tiempo = false;
    int Tiempo_1 = 10;
    while ((!BT.available() > 0) && Tiempo == false) {
    BT.print(Tiempo_1);
    BT.print(",");
    delay(1000);
    Tiempo_1--;
    if (Tiempo_1 < 0) {
      Tiempo = true;
      BT.println("Se ha acabo tu tiempo");
    }
  }

  BT.println();
  respuesta = BT.readStringUntil('\n');

  if (Tiempo == false) {
  }
}

void incorrecta() {
  tone(buzzerPin, 330);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 523);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 262);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 392);
  delay(200);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(300);
  noTone(buzzerPin);

  tone(buzzerPin, 330);
  delay(300);
  noTone(buzzerPin);

  tone(buzzerPin, 349);
  delay(700);
  noTone(buzzerPin);

  tone(buzzerPin, 440);
  delay(230);
  noTone(buzzerPin);

  tone(buzzerPin, 494);
  delay(230);
  noTone(buzzerPin);

  tone(buzzerPin, 440);
  delay(233);
  noTone(buzzerPin);

  tone(buzzerPin, 349);
  delay(900);
  noTone(buzzerPin);

  tone(buzzerPin, 415);
  delay(300);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(300);
  noTone(buzzerPin);

  tone(buzzerPin, 415);
  delay(300);
  noTone(buzzerPin);

  tone(buzzerPin, 330);
  delay(150);
  noTone(buzzerPin);

  tone(buzzerPin, 392);
  delay(150);
  noTone(buzzerPin);

  tone(buzzerPin, 294);
  delay(150);
  noTone(buzzerPin);

  tone(buzzerPin, 349);
  delay(150);
  noTone(buzzerPin);

  tone(buzzerPin, 330);
  delay(1800);
  noTone(buzzerPin);
}
