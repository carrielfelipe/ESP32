#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

int Player_state = 13;


// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 26; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 27; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {
 pinMode(Player_state, INPUT_PULLUP);

  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);
  Serial.println("Connecting to DFplayer");
  delay(500);

  // Start communication with DFPlayer Mini
  /*if (player.begin(softwareSerial)) {
   Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(20);
    // Play the first MP3 file on the SD card
    player.play(1);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }*/
  
  while (!player.begin(softwareSerial))

  {

      Serial.print(".");

      delay(1000);

  }

  Serial.println(" DFplayer connected!");

  delay(500);

  player.volume(20); // Set volume to maximum (0 to 30).
  player.play(1);

  
}

void loop() {
/*
if (digitalRead(Player_state) == LOW)
  {
      Serial.println("audio is playing");
  }
  else
  {
      Serial.println("audio is not playing");
  }*/
  
 
   }
