#include "pitches.h"

// constants won't change. They're used here to 
// set pin numbers:
const int sensorPin = 2;     // the number of the sensor pin
const int speakerPin =  8;      // the number of the speaker pin

// variables will change:
int sensorState = HIGH;         // variable for reading the sensor status

int note = NOTE_D7;

int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;

void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
  
  // initialize the speaker pin as an output:
  pinMode(speakerPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(sensorPin, INPUT);
  //initialize LED pin as an output:
  pinMode(LEDpin, OUTPUT);  
}

void loop() {
  // read the state of the pushbutton value:
  sensorState = digitalRead(sensorPin);

  // check if the sensor is impeded
  // if it is, the buttonState is HIGH:
  if (sensorState == LOW) {  
   Serial.println("sensor low");   
    // turn music on   
    tone(speakerPin, note, 10);
    delay(1);    
  } 
  
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("pressure reading = ");
  Serial.println(fsrReading);
 
  // map fsrReading to LED brightness
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);

}
