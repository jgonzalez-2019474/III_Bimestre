/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Francisco Barillas
 * Carnet: 2019376
 * Proyecto: Practica 1
*/
//Icluyo Librerias
#include <Ticker.h>

//Defino mis directivas de preprocesador
#define LED_RED 3
#define LED_GREEN 5
#define LED_BLUE 6
#define Potenciometro A0

//Funciones
void Salidas();
int  Control_Brilo();
void Secuencia_Led();
void Lectura();
void Actualizacion();

//Variables
int Brillo;
int Escala;
int Tiempo;

//Constructor
Ticker ISR_tiempo(Lectura, 10);

void setup() 
{
  Salidas();
}

void loop() 
{
  Secuencia_Led();
  Actualizacion();
}
void Salidas()
{
  ISR_tiempo.start();
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(Potenciometro, INPUT);
}
void Actualizacion()
{
  ISR_tiempo.update();  
}

int Control_Brilo()
{
  Brillo = analogRead(Potenciometro);
  Escala = map (Brillo, 0, 1023, 0, 255);
  return Escala;
}

 void Lectura()
{
  Tiempo = Control_Brilo();
}
    
void Secuencia_Led()
{
    analogWrite(LED_RED, 174);
    analogWrite(LED_GREEN, 92);
    analogWrite(LED_BLUE, 230);
    delay(Tiempo);
    //
    analogWrite(LED_RED, 255);
    analogWrite(LED_GREEN, 255);
    analogWrite(LED_BLUE, 255);
    delay(Tiempo);
    //
    analogWrite(LED_RED, 0);
    analogWrite(LED_GREEN, 255);
    analogWrite(LED_BLUE, 255);
    delay(Tiempo);
    //;
    analogWrite(LED_RED, 189);
    analogWrite(LED_GREEN, 174);
    analogWrite(LED_BLUE, 20);
    delay(Tiempo);
    //
    analogWrite(LED_RED, 255);
    analogWrite(LED_GREEN, 87);
    analogWrite(LED_BLUE, 35);
    delay(Tiempo);
}
