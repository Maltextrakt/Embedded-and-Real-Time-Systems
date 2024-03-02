// C++ code
//
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 4
// Exercise 2
// Submission code: 2014617
// Lines 28-41 are inspired by a guide: https://www.instructables.com/Arduino-Timer-Interrupts/

#include <Servo.h> // import servo library


volatile boolean updateFlag = false; //set the flag that determines whether or not its time to read the flag again, set to false

Servo servo; // declare servo object from class Servo
int servoPin = 9; // set servopin to 9 (which uses pwm, essentially analog)

int seconds = 1; // set seconds to 1

void setup()// setup section of the code
{
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate for debugging and monitoring output
  
  servo.attach(servoPin); // connect the servoPin to the servo object
  
  // this section configures Timer2 to periodically trigger an interrupt 
  cli(); // clear/ stop interrupts to ensure that the following code is ran without potential interrupt, crucial code
  
  TCCR2A = 0; // reset the Timer2 Control Register A to default state
  TCCR2B = 0; // reset TImer2 Control Register B to default state
  TCNT2 = 0; // initialize Timer2 counter to 0 to start counting from the beginning
  
  OCR2A = 249; // set output compare register for Timer2 to 249 for 1HZ interrupt
  
  // uses prescaler value 32
  TCCR2A |= (1 << WGM21); // set timer2 to "Clear Timer on Compare Match" mode
  TCCR2B |= (1 << CS21) | (1 << CS20); // set Timer2 prescaler to 32 to slow down the counting
  TIMSK2 |= (1 << OCIE2A); // enable Timer2 Output COmpare A Match Interrupt
  
  sei(); // set/ allow interrupts again
  
}

ISR(TIMER2_COMPA_vect) { // Timer2 Compare Match A, create ISR (Interrupt Service Routine) 
  static int tickCount = 0; // declare and initialize tickCount to 0
  tickCount++; // increment tickCount
  if(tickCount >= 2000){ // if tickCount is equal or greater than 2000...
    tickCount = 0; // reset tickCount
    updateFlag = true; // set the flag to true that indicates that it is time to read temp again
  }
}

void loop()// loop section of the program
{
  if(updateFlag) { // if updateFlag is set to true..
  updateFlag = false; // reset the flag again
    
  int angle = (seconds % 60) * (180/60); // calculate the angle, using the servos abiltiy for 180 rotation and then reset
  servo.write(angle); // provide the angle to the servo component
    
  Serial.print("Time: ");
  Serial.print(seconds);
  Serial.print("\n");
    
  seconds++; // increment seconds    
  }
}