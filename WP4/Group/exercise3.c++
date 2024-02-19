
// C++ code
//

#include <Adafruit_NeoPixel.h> // import neopixel library

#define neoPin 6 // define neopixel inpuut pin to 6
#define neoNum 12 // define amount of neopixel lights to 12
#define redLED 9 // define red LED to pin 9
#define tempPin A0 // define analog pin for the temperature sensor TMP

Adafruit_NeoPixel strip(neoNum, neoPin, NEO_GRB + NEO_KHZ800); // create neopixel object with grb color khz800

unsigned long previousMillis = 0; // variable that keeps track of last time the LEDs were updated
const long interval = 1000; // interval in milliseconds that determines how often to update LEDs


void setup()// setup section of the code
{
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate for debugging and monitoring output
  strip.begin(); // start neopixel strip
  strip.show(); // clear LEDs of the strip if any were on before
  pinMode(redLED, OUTPUT); // set the red LED to output
  
}



void loop()// loop section of the program
{
  static unsigned long lastUpdateTime = 0; // variable that keeps track of times since last update, static so that it retains its value between loop calls, its only 0 once.
  
  if(millis() - lastUpdateTime > interval){ // if current time minus time of last update is greater than interval (1sec)
  	lastUpdateTime = millis(); // set lastupdatetime to current time with millis ()
    float temp = readTemp(); // set temperature variable with function call to readTemp
    updateRingLight(temp); // update the LEDs on the ringlight with function call to updateRingLight with the now read temperature
  }
}

float readTemp() { // function that returns a temperature by reading tmp sensor
  float voltage = analogRead(tempPin) * 5.0 / 1023.0; // voltage conversion by taking the output of tempPin
  float temperature = (voltage - 0.5) * 100; // Convert voltage to temperature
  Serial.print("Temperature: ");
  Serial.println(temperature);
  return temperature; // return the converted temperature
}

void updateRingLight(float temp){ // function that takes temperature as arg and updates the states of the LEDs
  int ledToLight = map(temp, -15, 40, 0, neoNum); // map the temperature to a number of LEDs to light up, set threshold between -15celcius and 40 celcius
  ledToLight = min(ledToLight, neoNum); // ensure ledTolight does not go over number of LEDs (neoNum)
  
  for(int i=0; i<neoNum; i++){ // for loop that iterates over the number of LEDs in the ring
    if(i < ledToLight) { // if i less than ledToLight
    	strip.setPixelColor(i, strip.Color(0, 150, 0)); // light up LED i with green color if within ledToLight count
    } else { // in all other cases..
    	strip.setPixelColor(i, strip.Color(0, 0, 0)); // turn off the LED i 
    }
  }
  strip.show(); // update neo ring with new settings
  
  
  digitalWrite(redLED, ledToLight >= neoNum ? HIGH : LOW); // turn on redLED if ledToLight has reached neoNum
 
}














