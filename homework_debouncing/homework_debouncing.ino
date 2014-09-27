/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
 //Pin 13 has an LED connected on most Arduino boards
 //give it a name:
int led = 13;

//define the button
int buttonPin = 2;
//define the state of the button
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  //start the serial connection from Arduino back to computer (serial is like console.log in Javascript)
  Serial.begin(9600);
  
  // initialize digital pin 13 (defined as led) as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //read the button (gets the state of the button pin (on or off)
  buttonState = digitalRead(buttonPin);
    //perform different actions depending on state of button:
    if(buttonState == HIGH){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("LED is On");
    delay(1000);              // wait for a second
  } else {
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("LED is Off");
    delay(1000);     // wait for a second
  }
}
