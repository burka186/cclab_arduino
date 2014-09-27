const int buttonPin = 2;    // the number of the button pin
const int ledPin = 13;      // the number of the LED pin

//these variables will change
int ledState = HIGH;         // the current state of the output (LED) pin
int buttonState;             // the current reading from the input (button) pin
int lastButtonState = LOW;   // the previous reading from the input (button) pin

//set debounce:
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time (to avoid flickering/noise)

void setup() {
  //set button as input and LED as output:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // make the current state of the switch (LOW or HIGH) into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH), and that you've waited for longer than the lastDebounceTime:  

  // If the switch changed:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    //take the actual current state of the button:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  
  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
