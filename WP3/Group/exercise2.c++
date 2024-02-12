// C++ code
//

int tempPin = A0;
int lightPin = A1;

int redLEDPin = 13;
int yellowLEDPin = 12;
int greenLEDPin = 11;

long interval = 2500;
long previousMillis = 0;


void setup(){
  Serial.begin(9600);
  
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  
  digitalWrite(redLEDPin, LOW);
  digitalWrite(yellowLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);
}

void loop(){
  
  long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    
    float voltage = analogRead(tempPin)* 5.0/1023.0;
    float temperatureInCelcius = (voltage - 0.5)*100;
    
    int light = analogRead(lightPin);
    float lightPercentage = (light/1023.0)* 100;
    
    Serial.print("Temperature: ");
    Serial.print(temperatureInCelcius);
    Serial.print(" C, Light intensirty: ");
    Serial.print(lightPercentage);
    Serial.print("%");
    Serial.print("\n");
    
    checkIfValid(temperatureInCelcius, lightPercentage);
  }
 
}
  
void checkIfValid (float temp, float light){
 
  digitalWrite(redLEDPin, LOW);
  digitalWrite(yellowLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);
  
  if((temp < -12 && light == 0) ||
      (temp >= -12 && temp < 0 && light >= 1 && light <= 20) ||
      (temp >= 0 && temp < 20 && light >= 21 && light <= 60) ||
      (temp >= 21 && light >= 61)) {
    digitalWrite(greenLEDPin, HIGH);
  }else if(temp >= 21 && light <61){
    digitalWrite(redLEDPin, HIGH);
  }else {
    digitalWrite(yellowLEDPin,HIGH);
  }
}
  
  
  
  
  
  
  
  
  
  