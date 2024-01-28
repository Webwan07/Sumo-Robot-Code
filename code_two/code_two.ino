#include <NewPing.h>
#include <Arduino.h>
#define MAX_DISTANCE 50
// Hulom's Group
const int PWMA = 5;
const int PWMB = 5;
const int AIN1 = 4;
const int AIN2 = 6;
const int BIN1 = 3;
const int BIN2 = 2;

const int moveForwardSpeed = 255;
const int moveBackwardSpeed = 255;
const int motorTurnSpeed = 255;

const int left_Trig = 8;
const int left_Echo = 9;
const int right_Trig = 10;
const int right_Echo = 11;

const int left_IR = 12; 
const int Right_IR = 13; 
const int back_IR = 7;

NewPing sonar1(left_Trig, left_Echo, MAX_DISTANCE);
NewPing sonar2(right_Trig, right_Echo, MAX_DISTANCE);

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(left_IR, INPUT);
  pinMode(Right_IR, INPUT);
  pinMode(back_IR, INPUT);

  delay(5000);
}

void moveForward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, moveForwardSpeed);
  analogWrite(PWMB, moveForwardSpeed);
}

void moveBackward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, moveBackwardSpeed);
  analogWrite(PWMB, moveBackwardSpeed);
}

void stopMotors() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void leftTurn() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, motorTurnSpeed);
  analogWrite(PWMB, motorTurnSpeed);
}

void rightTurn() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, motorTurnSpeed);
  analogWrite(PWMB, motorTurnSpeed);
}

void loop() {
  unsigned int leftSensor = sonar1.ping_cm();
  unsigned int rightSensor = sonar2.ping_cm();
  unsigned int leftIR = digitalRead(left_IR);
  unsigned int rightIR = digitalRead(Right_IR);
  unsigned int backIR = digitalRead(back_IR);

  if (leftIR == 1 || rightIR == 1 || backIR == 1) {
    if (leftIR == 1 || rightIR == 1) {
      moveBackward();
      delay(1000); 
      stopMotors();
      rightTurn();
    }
    else if (backIR == 1) {
      moveForward();
      delay(1000);
      stopMotors();
      rightTurn();
    }
  } else {
    if (leftSensor <= MAX_DISTANCE && leftSensor != 0|| rightSensor <= MAX_DISTANCE && rightSensor != 0) {
      moveForward();
    } else {
      stopMotors();
      rightTurn();
    }
  }
  delay(1);
}
