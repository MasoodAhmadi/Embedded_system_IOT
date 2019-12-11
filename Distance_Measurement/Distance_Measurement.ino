#include<LiquidCrystal.h>
#include <math.h>
LiquidCrystal lcd (16,17,18,19,20,21);

volatile int encoderValue = 0;
int count = 0;

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup(){
  pinMode(9, OUTPUT);   //speedA
  pinMode(7, OUTPUT);   //directionA
  pinMode(10, OUTPUT);  //speedB
  pinMode(8, OUTPUT);   //directionB

  pinMode (3, INPUT);   //getting input values from the encoder
  pinMode (23, INPUT);  
  pinMode (24, OUTPUT);   //output values for display
  pinMode (25, OUTPUT);

  attachInterrupt(1, valueChanged, FALLING);
}

void loop(){

float inputX = analogRead(A8);  //X potentiometer
float inputY = analogRead(A9);  //Y potentiometer

  if (inputX < 500)  //small tolerance added to 512
  {
    // 1)Convert joystick position to motor direction
    
    //Set Motor A backward
    digitalWrite(7, HIGH);
    //digitalWrite(9, LOW);

    //Set Motor B backward
    digitalWrite(8, HIGH);
    //digitalWrite(10, LOW);

    // 2)Convert joystick position to motor speed
    motorSpeedA = map(inputX, 500, 0, 0, 255);
    motorSpeedB = map(inputX, 500, 0, 0, 255);
  }

  else if (inputX > 524)
  {
    // 1)Convert joystick position to motor direction
    
    //Set Motor A forward
    digitalWrite(7, LOW);
    //digitalWrite(9, HIGH);

    //Set Motor B forward
    digitalWrite(8, LOW);
    //digitalWrite(10, HIGH);

    // 2)Convert joystick position to motor speed
    motorSpeedA = map(inputX, 524, 1023, 0, 255);
    motorSpeedB = map(inputX, 524, 1023, 0, 255);
  }

  else  //if joystick position is in the middle
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  if(inputY < 500)
  {
    int yValue = map(inputY, 500, 0, 0, 255);

    motorSpeedA = motorSpeedA - yValue; //decrease A-speed
    motorSpeedB = motorSpeedB + yValue; //increase B-speed

    if (motorSpeedA < 0)    // check limitations
    {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255)
    {
      motorSpeedB = 255;
    }
  }

    if(inputY > 524)
  {
    int yValue = map(inputY, 524, 1023, 0, 255);

    motorSpeedA = motorSpeedA + yValue; //increase A-speed
    motorSpeedB = motorSpeedB - yValue; //decrease B-speed

    if (motorSpeedB < 0)    // check limitations
    {
      motorSpeedB = 0;
    }
    if (motorSpeedA > 255)
    {
      motorSpeedA = 255;
    }
  }

  analogWrite(9, motorSpeedA);
  analogWrite(10, motorSpeedB);   

  encoderValue = digitalRead(3);

  lcd.setCursor(1,0);
  lcd.print("Distance = ");

  lcd.setCursor(13,0);
  lcd.print(count*0.0987);

  lcd.setCursor(33,0);
  lcd.print(count);
}

void valueChanged()
{
    if (encoderValue == 0)
  {
    encoderValue = 1;  //ON
  }
  else
  {
    encoderValue = 0;  //OFF
  }

  count++;
}
