// C++ code

int ledState = LOW;              // state of the output pin initialized to LOW (off)
long previousMillis = 0;         // will store last time LED was updated
const long interval = 1000;      // interval at which to blink in milliseconds (1 secondh here)

void setup() {	// setup section, runs once
  pinMode(8, OUTPUT); // initialize the LED at 8 and set it to output
  pinMode(7, OUTPUT); // initialize the LED which depends on button (7)
  pinMode(2, INPUT_PULLUP); // set the button pin to 2 with internal pull up
}

void loop() {	// loop part of the code, runs continuously
  unsigned long currentMillis = millis();	// initialize variable that keeps track of how many milliseconds ahve passed

  if (currentMillis - previousMillis >= interval) {	// if statement that checks if the time specified by interval has elapsed
    previousMillis = currentMillis;	// save the last time the LED blinked

    if (ledState == LOW) {	// if that checks if the ledState is LOW
      ledState = HIGH;	// if so, set it to HIGH
    } else {	// if the ledState is HIGH..
      ledState = LOW;	// set it to LOW
    }

    digitalWrite(8, ledState);	// set the LED state to what ledState is currently
  }

  // Check the button state and set the second LED
  int buttonState = digitalRead(2);	// declare and initialize variable that reads from pin 2
  if (buttonState == LOW) { // if the button is pressed (LOW)
    digitalWrite(7, LOW);  // turn off the LED connected to pin 7
  } else {	// if the buttonstate is HIGH
    digitalWrite(7, HIGH);   // turn on the LED connected to 7
  }
}
