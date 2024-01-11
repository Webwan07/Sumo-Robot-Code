#include <NewPing.h>
#define MAX_DISTANCE 200

const short sensor1Trig = 8;
const short sensor1Echo = 9;
const short sensor2Trig = 10;
const short sensor2Echo = 11;

NewPing sonar1(sensor1Trig, sensor1Echo, MAX_DISTANCE);
NewPing sonar2(sensor2Trig, sensor2Echo, MAX_DISTANCE);

const short outPin1 = 12; 
const short outPin2 = 13; 

void setup() {
  pinMode(outPin1, INPUT);
  pinMode(outPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned short distance1 = sonar1.ping_cm();
  unsigned short distance2 = sonar2.ping_cm();

  unsigned short irVal1 = digitalRead(outPin1);
  unsigned short irVal2 = digitalRead(outPin2);

  if(irVal1 == 0 || irVal2 == 0){
    Serial.println("Stopping...");
  }else{
    if(distance1 > 0 && distance1 < 60 || distance2 > 0 && distance2 < 60){
      Serial.println("Moving Forward...");
    }else{
      Serial.println("Rotating...");
    }
  }

  delay(100);
}