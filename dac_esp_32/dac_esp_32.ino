#include "esp32-hal-dac.h"

#define DAC1 25

const uint8_t sinetable[] = {
  128, 140, 152, 165, 177, 189, 200, 212, 223, 233, 243, 252, 255, 255, 255, 252,
  243, 233, 223, 212, 200, 189, 177, 165, 152, 140, 128, 116, 104, 91, 79, 67, 56,
  44, 33, 23, 13, 4, 0, 0, 0, 4, 13, 23, 33, 44, 56, 67, 79, 91, 104, 116
};

void setup() {
  Serial.begin(115200);
  //dac_output_enable(DAC1);
}

void loop() { // Generate a Sine wave
  for (int i = 0; i < sizeof(sinetable); i++) {
    dacWrite(DAC1, sinetable[i]);
    //delayMicroseconds(10);
  }
}
