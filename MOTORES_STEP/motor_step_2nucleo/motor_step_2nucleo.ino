// CNC Shield Stepper Control Demo with Speed Control
// Superb Tech
// www.youtube.com/superbtech



const int StepX = 12;
const int DirX = 14;
const int potPin = 34; // Pin del potenciómetro

const int numero_pasos = 200;
int speed = 0;

TaskHandle_t Tarea2; //Creacion del segundo loop


void setup() {


  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);


  Serial.begin(115200);

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
int potenciometro= analogRead(potPin);
delayMicroseconds(10);
//speed = map(potenciometro, 0, 4095, 3000, 100); // Lee el valor del potenciómetro y mapea la velocidad
speed= 800;
  
digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

/*float RPM = (1.8*60/(2*speed*0.000001*360));
Serial.print("RPM: ");
Serial.println(RPM);
Serial.print("SPEED: ");*/
Serial.println(speed);
//Serial.println(potenciometro);



  
}


//LOOP 2
//////////////////////loop() nucleo0
//Se encarga de accionar los perisféricos
void loop_nucleo_2(void * pvParameters){
digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
while(1){


//Serial.println("Entro al loop");


 for(int x = 0; x<200; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(speed);
 }

  //Serial.println("salgo del loop");

}
}

