// C++ code
// Guide used from: https://www.instructables.com/Arduino-Timer-Interrupts/
//
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 5
// Exercise 2
// Submission code: 994475

volatile boolean readTemperatureFlag = false; //set the flag that determines whether or not its time to read the temperature again, set to false


int whiteLED = 13; // declare and initialize led pins for the white LED
int redLED = 12; // declare and initialize led pins for the red LED
int orangeLED = 11; // declare and initialize led pins for the orange LED
int yellowLED = 10; // declare and initialize led pins for the yellow LED
int greenLED = 9; // declare and initialize led pins for the green LED

int tempPin = A0; // declare and initialize analog pin for the temperature sensor TMP


void setup()// setup section of the code
{
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate for debugging and monitoring output
  
  pinMode(whiteLED, OUTPUT); // set white LED to OUTPUT
  pinMode(redLED, OUTPUT); // set red LED to OUTPUT
  pinMode(orangeLED, OUTPUT); // set orange LED to OUTPUT
  pinMode(yellowLED, OUTPUT); // set yellow LED to OUTPUT
  pinMode(greenLED, OUTPUT); // set green LED to OUTPUT
  
  cli(); // clear/ stop interrupts to ensure that the following code is ran without potential interrupt, crucial code
  
  TCCR1A = 0; // reset the Timer1 Control Register A to default state
  TCCR1B = 0; // reset TImer1 Control Register B to default state
  TCNT1 = 0; // initialize Timer1 counter to 0 to start counting from the beginning
  
  OCR1A = 15624; // set output compare register for Timer1 to 15624 for 1HZ interrupt
  
  TCCR1B |= (1 << WGM12); // set timer1 to "Clear Timer on Compare Match" mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // set Timer1 prescaler to 1024 to slow down the counting
  TIMSK1 |= (1 << OCIE1A); // enable Timer1 Output COmpare A Match Interrupt
  
  sei(); // set/ allow interrupts again
  
}

ISR(TIMER1_COMPA_vect) { // Timer1 Compare Match A, create ISR (Interrupt Service Routine) 
	readTemperatureFlag = true; // set the flag to true that indicates that it is time to read temp again
}

void loop()// loop section of the program
{
  if(readTemperatureFlag) { // if readflag is set to true..
  readTemperatureFlag = false; // reset the flag again
    
  float voltage = analogRead(tempPin)* 5.0/1023.0; // voltage variable that reads the temperature pin and converts it to voltage
  float temperatureInCelcius = (voltage - 0.5)*100; // convert voltage value to temperature in celcius
  
    
  Serial.print("Temperature: ");
  Serial.print(temperatureInCelcius);
  Serial.print("\n");
    
  updateLEDs(temperatureInCelcius); // function call to update LEDs that takes the celcius reading as argument
    
  }
  
}

void updateLEDs(float temperature){ // function that takes temperature as arg and updates the states of the LEDs
  digitalWrite(whiteLED, LOW); // set white LED to off (LOW)
  digitalWrite(redLED, LOW); // set red LED to off (LOW)
  digitalWrite(orangeLED, LOW); // set orange LED to off (LOW)
  digitalWrite(yellowLED, LOW); // set yellow LED to off (LOW)
  digitalWrite(greenLED, LOW); // set green LED to off (LOW)
  
  //set the thresholds for the LEDs
  if (temperature > 0 && temperature <= 10) { // if temp between 1 and 10 
    digitalWrite(whiteLED, HIGH); // turn on white LED
  } else if (temperature > 10 && temperature <= 20) { // if temp between 11 and 20
    digitalWrite(whiteLED, HIGH); // turn on white LED
    digitalWrite(redLED, HIGH); // turn on red LED
  } else if (temperature > 20 && temperature <= 30) { // if temp between 21 and 30
    digitalWrite(whiteLED, HIGH); // turn on white LED
    digitalWrite(redLED, HIGH); // turn on red LED
    digitalWrite(orangeLED, HIGH); // turn on orange LED
  } else if (temperature > 30 && temperature <= 40) { // if temp between 31 and 40
    digitalWrite(whiteLED, HIGH); // turn on white LED
    digitalWrite(redLED, HIGH); // turn on red LED
    digitalWrite(orangeLED, HIGH); // turn on orange LED
    digitalWrite(yellowLED, HIGH); // turn on yellow LED
  } else if (temperature > 40) { // if temp over 40
    digitalWrite(whiteLED, HIGH); // turn on white LED
    digitalWrite(redLED, HIGH); // turn on red LED
    digitalWrite(orangeLED, HIGH); // turn on orange LED
    digitalWrite(yellowLED, HIGH); // turn on yellow LED
    digitalWrite(greenLED, HIGH); // turn on green LED
  }
}