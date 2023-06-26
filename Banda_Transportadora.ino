/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Francisco Barillas
   Carnet: 2019376
   Proyecto: Practica 1
*/
//Icluyo Librerias
#include <Stepper.h>
#include <Servo.h>

//Variables
//Valores de cada color
int resultado_azul, resultado_rojo, resultado_verde;
//Que son captados por la ldr
int resultado;

//Directivas de preprocesador
//LDR en pulldown
#define ch_LDR    A0  //pin A0 del arduino, conectado a Vcc y con una reistencia de 10k a negativo
#define led_Azul  5   //led azul conectado al pin 3
#define led_Verde 4   //led verde conectado al pin 4
#define led_Rojo  3   //led rojo conectado al pin 5, todos del rgb
#define servo 6 //Servomotor
#define Obstaculo 2 //Sensor de obstaculos
#define tiempo 150 //Cuanto tarda el encender de los leds
//Para el stepper
#define Revoluciones 2048 //Revoluciones o vueltas que da el stepper por minuto
#define Velocidad 6 //Velocidad definida al stepper

//Constructor
Stepper Stepper_Banda(Revoluciones, 8, 10, 9, 11); //Stepper que hace funcionar la banda
Servo Separador; //Servo que separa las cosas

void setup()
{
  //Configuracion de los constructores
  Stepper_Banda.setSpeed(Velocidad); //El stepper ira a velocidad de 6
  Separador.attach(servo); //pin 6 para el servo

  //Comunicacion serial
  Serial.begin(9600);
  Serial.println("Verificación de color");

  //Configuracion de pines
  pinMode(ch_LDR, INPUT); //pin A0 como entrada
  pinMode(led_Azul, OUTPUT); //pin 3 como salida
  pinMode(led_Verde, OUTPUT); //pin 4 como salida
  pinMode(led_Rojo, OUTPUT);  //pin 5 como salida
  pinMode(Obstaculo, INPUT); //pin 7 como sensor de obstaculos

  //Los leds van a iniciar apagadas
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
  Separador.write(0);
}

void loop()
{

  if (digitalRead(Obstaculo) == LOW) {
    escaneo_color();
    verificacion();
    delay(400);
  }
  else {
    Stepper_Banda.step(100);
  }

}

//*******FUNCIONES**************
int escaneo_color() {

  //Enviendo el led rojo
  digitalWrite(led_Rojo, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Rojo = ");
  Serial.println(resultado_rojo);
  digitalWrite(led_Rojo, LOW);
  delay(tiempo);

  //Enviendo el led verde
  digitalWrite(led_Verde, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Verde = ");
  Serial.println(resultado_verde);
  digitalWrite(led_Verde, LOW);
  delay(tiempo);

  //Enviendo el led azul
  digitalWrite(led_Azul, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Azul = ");
  Serial.println(resultado_azul);
  digitalWrite(led_Azul, LOW);
  delay(tiempo);

}

void verificacion() {
  if (resultado_verde > resultado_azul && resultado_verde > resultado_rojo) {
    separacion();
  }
  else {
    continuacion();
  }
}

void continuacion() {
  Stepper_Banda.step(Revoluciones);
}

void separacion() {
  Stepper_Banda.step(1100);
  delay(tiempo);
  Separador.write(180);
  delay(tiempo);
  Separador.write(0);
}
