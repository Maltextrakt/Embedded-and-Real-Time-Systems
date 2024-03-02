// C++ code
//
// (C)_Isaac Lindegren Ternbom, Karl Eriksson, Malte Bengtsson, group 20 (2024)
// Work package 6
// Exercise 1
// Submission code: 271070

// WP 6 Exercise 1 Template DIT 632
// Task 2 and 3


#define ENCA 2 // set ENCA pin to 2
#define ENCB 3 // set ENCB pin to 3 
#define PWM1 5 // set PWM1 pin to 5
#define PWM2 6 // set PWM2 pin to 6
 
int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal


void setup() { // setup section of the program
 
  Serial.begin(9600); // initialize baud to 9600 so we can use Serial. ...
  pinMode(ENCA,INPUT_PULLUP); // set ENCA to input pullup, ENCA is encoder signal A, send ticks when motor rotates
  pinMode(ENCB,INPUT_PULLUP); // set ENCB to input pullup, ENCB is encoder signal B, sends ticks when motor rotates
  pinMode(PWM1,OUTPUT); // set PWM1 to output, pwm1 and 2 controls direction and speed of motor
  pinMode(PWM2,OUTPUT);  // set PWM2 to output
  
   
  /*
  ==> TO DO TO DO TO DO
  ATTACH INTERRUPT HERE.
  */
  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING); // attach interrupt to ENCA, when rising edge detected, execute ISR function 
 
  
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); // set PWM2 to low signal, giving just a little motor movement
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10); // set PWM1 to low signal, giving just a little motor movement
}

void loop() { // loop section of the program 
  
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10); // set PWM1 to low signal, giving just a little motor movement
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10); // set PWM2 to low signal, giving just a little motor movement
  
  // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){ // motor encode has 2300 ticks/full rotation, therefore check if pos is over one whole lap
      deg = deg - 359; // reset the counter, essentially doing modulo
      pos = pos - 2299; // reset the counter for pos, essentially doing modulo
    }
    if (pos < 0){ // if pos less than 0, negative
      deg = 359 + deg; // reset the counter so that it is positive
  	  pos = 2299 + pos; // reset the counter pos so that it is positive
    }
  

  // Print current position
  Serial.print("The current position is: ");
  Serial.print(deg);
  Serial.print("\n");
   
  
  // Get input 
  degtarget = getInput();
  
  // Calculate initial error
  e = degtarget - deg;
    
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    deg = map(pos,0,2299,0,359);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){ // if speed is greater or equal to 0
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100; // set speed to 100
      analogWrite(PWM2, speed); // analogWrite PWM2 to speed
      analogWrite(PWM1, 0); // set speed (analogwrite) of PWM1 to 0
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; // set speed to negative 100
      analogWrite(PWM1, -speed); // analogwrite PWM1 pin to negative speed
      analogWrite(PWM2, 0);  // set speed (analogwrite) of PWM2 to 0
    }
	
    // Calculate new error
  	e = degtarget - deg; // calculate new error by subtracting degrees from target degress
    
  }
}



int getInput(){ // function for receiving input from user of the program
  
  int ready = 0; // create flag to check if input is received
  char buf[3]; // create buffer that stores input of size 3
  int input = -1; // initialize input to -1, indiciating to input received yet
  
  Serial.print("Please enter the desired position: \n");
  
  while(!ready){ // loop until ready is true, ready is set to 1
    ready = Serial.readBytes(buf,3); // read up to 3 bytes into buf, then set ready
    input = atoi(&buf[0]); // convert ascii input to integer, store in inout 
  }
 
  return input; // return the input
}  

int getAction(int error){ // method that calculates motor action based on error
  /*
  ==> TO DO TO DO TO DO
  Calculate u_out as function of the error and the kp (tuning parameter).
  */
  
  
  u_out = error * kp; // calculate control signal u_out from error times kp
  
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255; // return 255
  }
  else if (u_out < -254){ //...or less than -254
    return -255; // return -255
  }  
  else // if u_out is within bounds
     return u_out; // return u_out
}

void ISR_readEncoder(){ // interrupt service routine that reads encoder vaklue
/*
  ==> TO DO TO DO TO DO
  READ THE ENCODER SIGNAL HERE.
  Read the encoder signals and increase or decrease pos accordingly.
  */
  b = digitalRead(ENCB); // read current state of encoder pin b ENCB
  
  if(b == HIGH){ // if b signal is HIGH it indicates forward movement
    pos++; // increment pos count to show forward movement
  } else { // if b LOW, indicates backwards movement
    pos--; // decerement pos to show backward movement
  }
  
  
  
}
     
    
         
         
