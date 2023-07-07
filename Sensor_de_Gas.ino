/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Francisco Barillas
 * Carnet: 2019376
*/

//Incluyo Librerias
#include <LedControl.h>
#include <Ticker.h>

//Directivas de preprocesador
#define DIN 2
#define CLK 3
#define CS 4
#define Sensor 6

//Constructores
void Lectura_Gas();
LedControl Led_Chisco = LedControl(DIN,CLK,CS,1);
Ticker ISR_Gas(Lectura_Gas, 5000);

//Funciones
void Salidas();
void Valor_Gas();
void Actualizacion();
void Animacion();

//Variables
const int ancho_matriz = 8; 
const int alto_matriz = 8; 
float gas;
float propano; 

byte Fuego[8] = 
{
B00001000,
B00001100,
B00011100,
B00111100,
B01101110,
B01011110,
B00101100,
B00011000
};
byte Fuego2[8] = 
{
B01001001,
B01011001,
B00111110,
B01111110,
B01101110,
B01011110,
B00101100,
B00011000
};
byte Copo_Nieve[8] = 
{
B10011001,
B01011010,
B00111100,
B11111111,
B11111111,
B00111100,
B01011010,
B10011001
};

void setup() 
{
  Salidas();
}

void loop() 
{
  Valor_Gas();
  Actualizacion();
  Animacion();
}

//
void Salidas()
{
  Led_Chisco.shutdown(0, false); 
  Led_Chisco.setIntensity(0, 15); 
  Led_Chisco.clearDisplay(0); 
  pinMode(6, INPUT); 
  ISR_Gas.start();
  Serial.begin(9600); 
}

//
void Actualizacion()
{
  ISR_Gas.update();
}


//
void Valor_Gas()
{
  if (propano > 60) 
  {
  Animacion();
  } 
  else {
  for (int i = 0; i < alto_matriz; i++) {
  Led_Chisco.setColumn(0, i, Copo_Nieve[i]);
  }
  }
  delay(1000);
}

//
void Lectura_Gas(){
  int suma =0;
  for(int i = 0; i < 5; i++){
  gas = map(analogRead(6),0,1023,0,100);
  suma = suma + gas;
  delay(100);
  }
  propano = suma/5;
  Serial.println(gas);
}

//
void Animacion()
{
  Led_Chisco.clearDisplay(0);
  for(int t = 0; t<5;t++){
  for (int i = alto_matriz; i > 0; i--) {
  Led_Chisco.setColumn(0, i, Fuego[i]);
  }
  delay(500);
  
  for (int i = alto_matriz; i > 0; i--) {
  Led_Chisco.setColumn(0, i, Fuego2[i]);
  }
  delay(500);
}
}
