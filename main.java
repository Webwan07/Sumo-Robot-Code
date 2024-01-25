#include <NewPing.h>
#define MAX_DISTANCE 200
const int PWMA = 5;
const int PWMB = 5;
const int AIN1 = 4;
const int AIN2 = 6;
const int BIN1 = 3;
const int BIN2 = 2;

const int motorSpeed = 255;
const int motorTurnSpeed = 100;

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

  Serial.begin(9600);
}

void moveForward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  analogWrite(PWMA, motorSpeed);
  analogWrite(PWMB, motorSpeed);
}

void moveBackward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);

  analogWrite(PWMA, motorSpeed);
  analogWrite(PWMB, motorSpeed);
}

void stopMotors() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
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
  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();

  // IR == 0 (White)
  // IR == 1 (Black)
  unsigned int leftIR = digitalRead(left_IR);
  unsigned int rightIR = digitalRead(Right_IR);
  unsigned int backIR = digitalRead(back_IR);
}