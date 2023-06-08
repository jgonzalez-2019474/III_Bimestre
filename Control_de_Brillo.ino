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
//Defino Directivas de preprocesador
#define LED_RED 3
#define Potenciometro A6

//Funciones
void Salidas();
void Control_Brilo();

//Variables
int Brillo;
long Escala;

void setup() 
{
  Salidas();
}

void loop() 
{
  Control_Brilo();
}

void Salidas()
{
 pinMode(LED_RED, OUTPUT);  
 pinMode(Potenciometro, INPUT); 
}

void Control_Brilo()
{
 Brillo = analogRead(Potenciometro);
 Escala = map (Brillo, 0, 1023, 0, 255);
 analogWrite(LED_RED, Escala);
}
