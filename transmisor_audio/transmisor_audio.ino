#include <WiFi.h>
#include <WiFiUdp.h>


//const char *ssid = "fourier";
//const char *password = "12345678";
const int udpPort = 4002;



WiFiUDP Udp;
const int micPin = 34; // Pin conectado al micrófono

float promedioMicrofono = 0; // Variable para almacenar el valor promedio del micrófono



void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi connected");

  Udp.begin(udpPort);

  calcularPromedioMicrofono(); // Calcular el valor promedio del micrófono
}

void loop() {
  Udp.beginPacket("192.168.0.100", 4002);

  for(int i=0; i<1024;i++){
    int old=micros();

    float analog = analogRead(34);

    analog = ((analog /1) + 127 - promedioMicrofono);
    if (analog > 255){
      analog = 255;
    }
    else if (analog < 0){
      analog = 0;
    }     
    Udp.write(byte(analog));
    while(micros()-old<87); // 90uSec = 1Sec/11111Hz - 3uSec para los otros procesos
  }
  Udp.endPacket();
  delay(5);
}



void calcularPromedioMicrofono() {
  unsigned long startTime = millis();
  unsigned long endTime = startTime + 10000; // 10 segundos

  int sum = 0;
  int count = 0;
  
  while (millis() < endTime) {
    sum += analogRead(micPin);
    count++;
    delay(1); // Pequeña pausa para evitar sobrecarga del loop
  }

  promedioMicrofono = sum / (float)count;
  Serial.print("Promedio es:");
  Serial.println(promedioMicrofono);
}
