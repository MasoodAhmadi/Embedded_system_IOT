#include <Wire.h>
#define CMPS14_address 0x60

long ReadCompass ();
long offset;

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  pinMode(9, OUTPUT);   //speedA
  pinMode(7, OUTPUT);   //directionA
  pinMode(10, OUTPUT);  //speedB
  pinMode(8, OUTPUT);   //directionB

  Wire.begin();

  offset = ReadCompass();
  Serial.begin(9600);
  Serial.print("Offset = ");
  Serial.println((long)offset);
}

void loop() {

 long input = analogRead(A14);  // potentiometer
 long joystick = analogRead(A8); // joystick X direction

 long directionGoal = map(input, 0, 1023, 0, 359);

 long lowerBorder = directionGoal - 8;
 long upperBorder = directionGoal + 8;

 Serial.print("Goal= ");
 Serial.println(directionGoal);

 /*if(input < 500)
  {
    int value = map(input, 500, 0, 0, 255);

    motorSpeedA = motorSpeedA - value; //decrease A-speed
    motorSpeedB = motorSpeedB + value; //increase B-speed

    if (motorSpeedA < 0)    // check limitations
    {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255)
    {
      motorSpeedB = 255;
    }
  }

    if(input > 524)
  {
    int value = map(input, 524, 1023, 0, 255);

    motorSpeedA = motorSpeedA + value; //increase A-speed
    motorSpeedB = motorSpeedB - value; //decrease B-speed

    if (motorSpeedB < 0)    // check limitations
    {
      motorSpeedB = 0;
    }
    if (motorSpeedA > 255)
    {
      motorSpeedA = 255;
    }
  }*/

  long currentDirection = ReadCompass();
  currentDirection -= offset;

  if (currentDirection < 0)
  {
    currentDirection += 360;
  }

  Serial.print("Direction = ");
  Serial.println(currentDirection);

  if(currentDirection < lowerBorder && joystick < 500)
  {
    motorSpeedA = 0; //decrease A-speed
    motorSpeedB = 128; //increase B-speed
  } 
  
  else if (currentDirection > upperBorder && joystick < 500)
  {
    motorSpeedA = 128; //increase A-speed
    motorSpeedB = 0; //decrease B-speed
  }

  else
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB);
    delay(300);
  
}


long ReadCompass ()
{
  Wire.beginTransmission(CMPS14_address);

  Wire.write(1);

  Wire.endTransmission(false);

  Wire.requestFrom(CMPS14_address, 1, true);

  if ( Wire.available() >= 1 )
  {
  long raw = Wire.read();

  long compassValue = raw * 360;
  compassValue = compassValue/255;
  
  return compassValue;
  }
}
