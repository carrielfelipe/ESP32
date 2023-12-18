// CNC Shield Stepper Control Demo with Speed Control
// Superb Tech
// www.youtube.com/superbtech



const int StepX = 12;
const int DirX = 14;
const int potPin = 34; // Pin del potenciómetro

const int numero_pasos = 200;


void setup() {


  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);


  Serial.begin(115200);
}

void loop() {
  //int speed = map(analogRead(potPin), 0, 1023, 2000, 100); // Lee el valor del potenciómetro y mapea la velocidad
  int speed= 600;
  
 digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

 
 for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(speed);
 }


  float RPM = (1.8*60/(2*speed*0.000001*360));
  Serial.print("RPM: ");
  Serial.println(RPM);


  
}

