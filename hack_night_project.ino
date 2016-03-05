#include <Servo.h>

//master delay
const int DELAY = 250;
//speed
const int speedPwr = 100;
const int speedPwrHalf = 50;
//motor A
const int motorA_dir = 12;
const int motorA_pwm = 3;
const int motorA_brk = 9;
const int motorA_cs = A0;

//motor B
const int motorB_dir = 13;
const int motorB_pwm = 11;
const int motorB_brk = 8;
const int motorB_cs = A1;


//Servos
Servo firstServo; //base 
Servo secondServo; //
Servo thridServo; //
Servo fourthServo; //
Servo fithServo; //wrist
Servo sixthServo; //grip


void setup(){
  Serial.begin(9600);
  Serial1.begin(115200);
  Serial1.println("starting the robot");
  pinMode(motorA_dir, OUTPUT);
  pinMode(motorB_dir, OUTPUT);
  pinMode(motorA_pwm, OUTPUT);
  pinMode(motorB_pwm, OUTPUT);
}

void loop() {
  
  if (Serial1.available())
  {
    char c = Serial1.read();
    Serial.println(c);
  switch(c){
    case 'f':
      forward();
      
      break;
    case 'b':
      backward();
      
      break;
    case 'r':
      turnRight();
      
      break;
    case 'l':
      turnLeft();
      
      break;
    case 's':
      brake();
      
      break;
    default:
      brake();
      
      break;
    }
  }else{
    
    delay(DELAY);
  }
}

void forward(){
  digitalWrite(motorA_pwm, speedPwr);
  digitalWrite(motorB_pwm, speedPwr);
  digitalWrite(motorA_dir, speedPwr);
  digitalWrite(motorB_dir, speedPwr);
  int motor_A_read = analogRead(motorA_cs);
  Serial.println(motor_A_read);
  int motor_B_read = analogRead(motorB_cs);
  Serial.println(motor_B_read);
  Serial.println("forward");
}

void backward(){
  digitalWrite(motorA_pwm, speedPwr);
  digitalWrite(motorB_pwm, speedPwr);
  digitalWrite(motorA_dir, LOW);
  digitalWrite(motorB_dir, LOW);
  int motor_A_read = analogRead(motorA_cs);
  Serial.println(motor_A_read);
  int motor_B_read = analogRead(motorB_cs);
  Serial.println(motor_B_read);
  Serial.println("backward");
}

void turnRight(){
  digitalWrite(motorA_pwm, speedPwrHalf);
  digitalWrite(motorB_pwm, speedPwrHalf);
  digitalWrite(motorA_dir, speedPwrHalf);
  digitalWrite(motorB_dir, LOW);
  int motor_A_read = analogRead(motorA_cs);
  Serial.println(motor_A_read);
  int motor_B_read = analogRead(motorB_cs);
  Serial.println(motor_B_read);
  Serial.println("Turn Right");
}

void turnLeft(){
  digitalWrite(motorA_pwm, speedPwrHalf);
  digitalWrite(motorB_pwm, speedPwrHalf);
  digitalWrite(motorA_dir, LOW);
  digitalWrite(motorB_dir, speedPwrHalf);
  int motor_A_read = analogRead(motorA_cs);
  Serial.println(motor_A_read);
  int motor_B_read = analogRead(motorB_cs);
  Serial.println(motor_B_read);
  Serial.println("Turn Left");
}

void brake(){
  digitalWrite(motorA_pwm, LOW);
  digitalWrite(motorB_pwm, LOW);
  digitalWrite(motorA_dir, LOW);
  digitalWrite(motorB_dir, LOW);
  int motor_A_read = analogRead(motorA_cs);
  Serial.println(motor_A_read);
  int motor_B_read = analogRead(motorB_cs);
  Serial.println(motor_B_read);
  Serial.println("BRAKE");
}
