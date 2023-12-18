// CNC Shield Stepper Control Demo with Speed Control
// Superb Tech
// www.youtube.com/superbtech



const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
const int potPin = A0; // Pin del potenciómetro

const int numero_pasos = 200;


void setup() {


  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  pinMode(StepZ,OUTPUT);
  pinMode( DirZ,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int speed = map(analogRead(potPin), 0, 1023, 1000, 100); // Lee el valor del potenciómetro y mapea la velocidad
  
 digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
 digitalWrite(DirY, HIGH);
 digitalWrite(DirZ, HIGH);
 
 for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(speed);
 }


for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepY,LOW); 
  delayMicroseconds(speed);
 }

for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(speed);
 }

 digitalWrite(DirX, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
 digitalWrite(DirY, LOW);
 digitalWrite(DirZ, LOW);
 
 for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepX,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepX,LOW); 
  delayMicroseconds(speed);
 }


for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepY,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepY,LOW); 
  delayMicroseconds(speed);
 }

for(int x = 0; x<100; x++) { // loop for 200 steps
  digitalWrite(StepZ,HIGH);
  delayMicroseconds(speed);
  digitalWrite(StepZ,LOW); 
  delayMicroseconds(speed);
 }


  /*Serial.print("speed: ");
  Serial.println(speed);*/
  float RPM = (1.8*60/(2*speed*0.000001*360));
  Serial.print("RPM: ");
  Serial.println(RPM);

  /*lcd.setCursor(0, 1); // Establecemos el cursor en la segunda fila
  lcd.print("RPM: ");
  lcd.print(RPM);*/ // Mostramos el tiempo transcurrido en segundos
  
}
