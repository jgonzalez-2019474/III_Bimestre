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
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>

//Directivas de Preprocesador
#define LED 3

//Funciones
 void Salidas();
 void Control_Led();
 void IRS_Temperatura();
 void Actualizar();

//Constructores
SoftwareSerial BT(10, 11); // RX, TX  
OneWire ourWire(2);
DallasTemperature Termometro(&ourWire);
Ticker IRS_Accion_Termometro(IRS_Temperatura, 10000);

//Variables
char Recepcion;


 void setup() 
{
  Salidas();
}

 void loop()
{
  Control_Led();
  Actualizar();
}

 void Actualizar()
{
 IRS_Accion_Termometro.update(); 
}

 void Salidas()
{
  IRS_Accion_Termometro.start();
  Serial.begin(9600);
  BT.begin(9600);
  Termometro.begin();
  pinMode(3,OUTPUT);
}

 void Control_Led()
 {
  if(BT.available())
  {
    Recepcion = BT.read();
    
  if(Recepcion=='1'){
    digitalWrite(3,HIGH);
 }
  if(Recepcion=='2'){
    digitalWrite(3,LOW);
 }
  if(Serial.available()){
    BT.write(Serial.read());
  
  
     }
   }
 }

 void IRS_Temperatura()
 {
  Termometro.requestTemperatures();
  float Temperatura_C = Termometro.getTempCByIndex(0);
  BT.println(Temperatura_C);
  Serial.println(Temperatura_C);
}
   
