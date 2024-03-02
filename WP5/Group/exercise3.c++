// C++ code
//
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 5
// Exercise 3
// Submission code: 994475

int tempPin = A0; // declare and initialize analog A0
int lightPin = A1; // declare and initialize analog 

int redLEDPin = 13; // declare and initialize red LED to pin 13
int yellowLEDPin = 12; // declare and initialize yellow LED to pin 12
int greenLEDPin = 11; // declare and initialize green LED to pin 11

long interval = 2500; // declare and initialize interval to 2500, 2,5seconds, interval determines time between update
long previousMillis = 0; // declare and initialize previous millis to 0


void setup(){ // setup part of the program
  Serial.begin(9600); // set baud to 9600, Serial.begin in order to be able to use Serial commands
  
  pinMode(redLEDPin, OUTPUT); // set red LED to output
  pinMode(yellowLEDPin, OUTPUT); // set yellow LED to output
  pinMode(greenLEDPin, OUTPUT); // se green LED to output
  
  digitalWrite(redLEDPin, LOW); // set red LED to LOW (off)
  digitalWrite(yellowLEDPin, LOW); // set yellow led to LOW (off)
  digitalWrite(greenLEDPin, LOW); // set green led to LOW (off)
}

void loop(){ // loop part of the program
  
  long currentMillis = millis(); // declare and intialize currentmillis, set to current time with millis();
  if(currentMillis - previousMillis >= interval){ // check to se if interval amount of tiime has elapsed
    previousMillis = currentMillis; // if so, set previousmillis to cucrrent millis
    
    float voltage = analogRead(tempPin)* 5.0/1023.0; // declare and initalize voltage to the value read from temperature pin * 5/1023 to get voltage
    float temperatureInCelcius = (voltage - 0.5)*100; // declare and initialize voltage -0.5 * 100 to convert to celcius
    
    int light = analogRead(lightPin); // declare and initalize light variable to value read from lightpin
    float lightPercentage = (light/1023.0)* 100; // declare and initialize light value in percentage 
    
    // print statements
    Serial.print("Temperature: ");
    Serial.print(temperatureInCelcius);
    Serial.print(" C, Light intensirty: ");
    Serial.print(lightPercentage);
    Serial.print("%");
    Serial.print("\n");
    
    checkIfValid(temperatureInCelcius, lightPercentage); // method call with celcius and light percentage that sets LEDs to HIGH (on) for cerain thresholds
  }
}
  
void checkIfValid (float temp, float light){ // method that sets LEDs to HIGH depending on valid thresholds for temp and light
 
  digitalWrite(redLEDPin, LOW); // "reset" red LED to LOW
  digitalWrite(yellowLEDPin, LOW); // "reset" yellow LED to LOW
  digitalWrite(greenLEDPin, LOW); // "reset" green LED to LOW
  
  if((temp < -12 && light == 0) || //
      (temp >= -12 && temp < 0 && light >= 1 && light <= 20) || //
      (temp >= 0 && temp < 20 && light >= 21 && light <= 60) || //
      (temp >= 21 && light >= 61)) { // valid intervals for green LED for temp and light
    digitalWrite(greenLEDPin, HIGH); // set green LED to on
  }else if(temp >= 21 && light <61){ // valid thresholds for red LED for temp and light
    digitalWrite(redLEDPin, HIGH); // set red LED to HIGH
  }else { // in all other intervals, go here
    digitalWrite(yellowLEDPin,HIGH); // set yellow LED to HIGH
  }
}
  
  
  
  
  
  
  
  
  
  