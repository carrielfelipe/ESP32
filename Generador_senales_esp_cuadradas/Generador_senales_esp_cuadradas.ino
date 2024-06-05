const int speakerPin = 25; // Pin del altavoz
const int potPin = 34; // Pin del potenciómetro

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  float potValue = analogRead(potPin) / 1023.0; // Lee el valor del potenciómetro y lo convierte a un rango de 0.0 a 1.0
  int freq = (int)(potValue * 5000.0 + 100.0); // Calcula la frecuencia ajustada por el potenciómetro (entre 100Hz y 2100Hz)
  
  tone(speakerPin, freq); // Genera la señal de tono en el pin del altavoz con la frecuencia calculada
  
  delay(10); // Espera un corto tiempo antes de cambiar la frecuencia
}