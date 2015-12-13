int echoPin = 9; 
int trigPin = 8; 

unsigned char loopCounter = 0;
double avgCm = 0.0;

void setup() { 
  Serial.begin (9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
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
  delay(100);

  if (loopCounter == 10)
  {
     Serial.println(avgCm / 10);
     avgCm = 0;
     loopCounter = 0; 
  }
  else
  {
    avgCm += cm;
    loopCounter++;
  }    
}
