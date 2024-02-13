// C++ code
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 3
// Exercise 2_2 (actually 3, but mislabeled I believe, in the instructions)
// Submission code: 285521


int tempPin = A0; // declare and initialize analog A0 to read temperature
int lightPin = A1; // declare and initialize analog A1 to read light level

int redLEDPin = 13; // declare and initialize red LED to pin 13
int yellowLEDPin = 12; // declare and initialize yellow LED to pin 12
int greenLEDPin = 11; // declare and initialize green LED to pin 11

long interval = 500; // declare and initialize interval to 0.5 sec
long previousMillis = 0; // store last time was read, set to 0


void setup(){	// setup part of the program
  Serial.begin(9600); // start communication with computer, set baud to 9600
  
  pinMode(redLEDPin, OUTPUT); // set red LED pin to output
  pinMode(yellowLEDPin, OUTPUT); // set yellow LED pin to output
  pinMode(greenLEDPin, OUTPUT); // set green LED pin to output
  
  digitalWrite(redLEDPin, LOW); // set the component red LED to off (LOW)
  digitalWrite(yellowLEDPin, LOW); // set the component yellow LED to off (LOW)
  digitalWrite(greenLEDPin, LOW); // set the component green LED to off (LOW)
}

void loop(){ // loop section of the program that cintinuously runs
  
  long currentMillis = millis(); // get current time and set to variable
  if(currentMillis - previousMillis >= interval){ // determine if its time to read the sensor
    previousMillis = currentMillis; // update last read time
    
    float voltage = analogRead(tempPin)* 5000.0/1023.0; // read and convert temperature sensor value to mV
    float temperatureInCelcius = (voltage - 500.0)/10; // convert voltage to temp in Celcius
    
    int light = analogRead(lightPin); // read light sensor value 
    float lightPercentage = (light/1023.0)* 100; // convert light sensor value to %
    
    // prints
    Serial.print("Temperature: ");  
    Serial.print(temperatureInCelcius); 
    Serial.print(" C, Light intensirty: ");
    Serial.print(lightPercentage);
    Serial.print("%");
    Serial.print("\n");
    
    checkIfValid(temperatureInCelcius, lightPercentage); // call method to check if the combination of light and temp are allowed
  }
 
}
  
void checkIfValid (float temp, float light){ // method that takes temperature and light values as arguments and determines if the combined value of these are allowed
 
  digitalWrite(redLEDPin, LOW); // set red LED to off
  digitalWrite(yellowLEDPin, LOW); // set yellow LED to off
  digitalWrite(greenLEDPin, LOW); // set green LED to off
  
  if((temp < -12 && light == 0) || // if that checks allowed values for temp and light combo
      (temp >= -12 && temp < 0 && light >= 1 && light <= 20) || // if that checks allowed values for temp and light combo
      (temp >= 0 && temp < 20 && light >= 21 && light <= 60) || // if that checks allowed values for temp and light combo
      (temp >= 21 && light >= 61)) { // if that checks allowed values for temp and light combo
    digitalWrite(greenLEDPin, HIGH); // set green LED to on
  }else if(temp >= 21 && light <61){ // if that checks allowed values for temp and light combo
    digitalWrite(redLEDPin, HIGH); // set red LED to on
  }else { // in all other cases go here
    digitalWrite(yellowLEDPin,HIGH); // set yellow LED to on
  }
}
  
  
  
  
  
  
  
  
  
  