/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Francisco Barillas
 * Carnet: 2019376
 * Proyecto: Practica 2
*/
//Incluyo las Librerias
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Defino mis directivas de preprocesador
#define Direccion_LCD 0x27
#define COLUMNAS 16
#define FILAS 2
#define Divisor_de_Voltaje A0  

//Funciones
void Salidas();
void LCD_RES();
int medicion_resistencia();

//Constructor
LiquidCrystal_I2C LCD_FRANCISCO_BARILLAS(Direccion_LCD, COLUMNAS, FILAS); 

void setup()  
{
  Salidas();
}

void loop() 
{
  LCD_RES();
}

void Salidas()
{

  LCD_FRANCISCO_BARILLAS.begin(16,2);
  LCD_FRANCISCO_BARILLAS.init();
  LCD_FRANCISCO_BARILLAS.backlight();
  pinMode(Divisor_de_Voltaje, INPUT);
}

void LCD_RES()
{
  LCD_FRANCISCO_BARILLAS.setCursor(0,0);
  LCD_FRANCISCO_BARILLAS.print("Valor de Res");
  unsigned long int ohms = medicion_resistencia();
  LCD_FRANCISCO_BARILLAS.setCursor(0,1);
  LCD_FRANCISCO_BARILLAS.print(ohms);
  LCD_FRANCISCO_BARILLAS.print(" ohms         ");
  
}
 int medicion_resistencia(){
   int Lectura = 0;  
   int   V = 5;   
   float Vr2 = 0;   
   float Res1 = 10000;    
   float Res2 = 0;         
   float Conexion = 0;

   Lectura = analogRead(Divisor_de_Voltaje);
   if(Lectura) 
{
    Conexion = Lectura * V;
    Vr2 = (Conexion)/1024.0; 
    Conexion = (V/Vr2) -1;   
    Res2= (Res1 * Conexion)-20;  
    Serial.print("Resistencia");
    Serial.println(Res2);
    return Res2;
}
   else 
{
   return 0;
}
}
