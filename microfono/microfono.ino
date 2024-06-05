const int pinSensor = A0;  // Conecta la salida analógica del sensor al pin 34 (ADC1_CH6) de ESP32
//const int pinDAC = 25;     // Conecta el pin de salida del DAC al pin 25 de ESP32

//CONFIGURACION DAC
#include "esp32-hal-dac.h"
#define DAC1 25
int valorSensor;
TaskHandle_t Tarea2; //Creacion del segundo loop

void setup() {
  Serial.begin(115200);  // Inicia la comunicación serial a 115200 bps
  //pinMode(pinDAC, OUTPUT);  // Configura el pin DAC como salida

  //CREACION DE SEGUNDO NUCLEO
  xTaskCreatePinnedToCore(
      loop_nucleo_2, /* Funcion de la tarea1 */
      "Tarea2", /* Nombre de la tarea */
      10000,  /* Tamaño de la pila */
      NULL,  /* Parametros de entrada */
      0,  /* Prioridad de la tarea */
      &Tarea2,  /* objeto TaskHandle_t. */
      0); /* Nucleo donde se correra */
}


void loop() {
  valorSensor = analogRead(pinSensor)/16;  // Lee el valor analógico del sensor
  Serial.println(valorSensor);  // Muestra el valor en el Monitor Serial

  // Puedes agregar lógica adicional basada en el valor del sensor
  // Por ejemplo, puedes encender un LED o realizar otras acciones según el nivel de sonido.

  //delay(500);  // Espera medio segundo antes de leer el sensor nuevamente
}


//LOOP 2
//////////////////////loop() nucleo0
//Se encarga de accionar los perisféricos
void loop_nucleo_2(void * pvParameters)
{
  delay(1000);
  Serial.print("Tarea2 se corre en el nucleo: ");
  Serial.println(xPortGetCoreID());
  Serial.println(xPortGetCoreID());
  

  while(1){
    // Escribe el valor leído en el DAC
  dacWrite(DAC1, valorSensor );  // Ajusta el valor según la resolución del DAC (por ejemplo, 8 bits)

  }
}