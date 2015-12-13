int echoPin = 9; 
int trigPin = 8; 
int modePin = 3;
int loopLimitPin = 4;

unsigned char loopCounter = 0;
double avgCm = 0.0;

int loopLimit = 5;

void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(modePin, INPUT);
  pinMode(loopLimitPin, INPUT);
} 

void loop() { 
  int duration;
  double cm; 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  cm = duration / 5.8;
  //Serial.println(cm); 
  //Serial.println(" cm"); 
  
  if (digitalRead(modePin) == 1)
    delay(500);
  else
    delay(100);

  if (digitalRead(loopLimitPin) == 1)
    loopLimit = 9;
  else
    loopLimit = 4;

  
  if (loopCounter == loopLimit)
  {
     Serial.print(avgCm / loopLimit); //Serial.print(" "); Serial.println(micros());
     avgCm = 0;
     loopCounter = 0; 
  }
  else
  {
    avgCm += cm;
    loopCounter++;
  }    
}
