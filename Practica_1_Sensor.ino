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
//Incluyo las Librerias necesarias
#include <Ticker.h>
#include <OneWire.h>                
#include <DallasTemperature.h>

//Variables
volatile static bool Estado_Sensor;

//Defino mis directivas de preprocesador
#define Push_Boton 3

//Funciones
void IRS_Temperatura();
void IRS_Push_Boton();
void Salidas();
void Actualizar();
//Constructores 
Ticker IRS_Accion_Sensor    (IRS_Temperatura, 3000);
Ticker IRS_Accion_Push_Boton(IRS_Push_Boton, 6000);
OneWire ourWire(2);
DallasTemperature SENSOR(&ourWire); 

void setup() 
{
  Salidas();
}
void loop() 
{
 Actualizar();
}
void Salidas()
{
  Serial.begin(9600);
  SENSOR.begin();
  pinMode(Push_Boton, INPUT);
  IRS_Accion_Sensor.start();
  IRS_Accion_Push_Boton.start();
  Serial.println("****Inicio****");
} 
void Actualizar()
{
 IRS_Accion_Sensor.update(); 
 IRS_Accion_Push_Boton.update();
} 
void IRS_Temperatura()
{
  SENSOR.requestTemperatures();
  int Temperatura_C = SENSOR.getTempCByIndex(0);
  Serial.print("-------");  
  Serial.print("La temperatura es: ");  
  Serial.print(Temperatura_C  );
  Serial.print(" C");  
  Serial.println("-------"); 
}
void IRS_Push_Boton(){
  Estado_Sensor = digitalRead(Push_Boton);
  if(Estado_Sensor == HIGH)
{
  Serial.println("Push_Boton Presionado");
}
  if(Estado_Sensor == LOW)
{
  Serial.println("Push_Boton sin Presionar  ");
}
}
