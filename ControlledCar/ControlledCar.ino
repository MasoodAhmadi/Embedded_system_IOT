#include <Wire.h>
#include <math.h>
#include <string.h>
#define CMPS14_address 0x60
#define encA 23
#define encB 3

long ReadCompass ();
void GoStraight();
void HoldOn();
void TurnRight(long currentDirection, long number);
void valueChangedDown();
void valueChangedUp();

long offset;

volatile int valueA;
volatile int valueB;
int count = 0;
float distance;

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

  pinMode (encA, INPUT);   //second encoder value for direction 
  pinMode (encB, INPUT);   //getting input values from the encoder

  attachInterrupt(1, valueChangedDown, FALLING);
  attachInterrupt(1, valueChangedUp, RISING);
}

void loop() {

  distance = count *0.05;
  long currentDirection = ReadCompass();
  currentDirection -= offset;
  currentDirection += 4;      // to make sure we don't get 359, 358 ...

  if (currentDirection < 0)
  {
    currentDirection += 360;
  }

  Serial.print("Direction = ");
  Serial.println(currentDirection);

  String input;

  if (Serial.available() ) 
  {
    input = Serial.readStringUntil('\n');

    Serial.println(input);

    int position1 = input.indexOf(':');
    Serial.print("Position: ");
    Serial.println(position1);

    String command = input.substring(0, position1);
    String value = input.substring(position1);

    long number = value.toInt();

    Serial.println(number);
    
    if (command == "Move")
    {
      if ( distance <= number)
      {
        GoStraight();
      }
      else if (distance > number)
      {
        HoldOn();
        count = 0;
      }
    }
    else if (command == "Turn")
    {
      HoldOn();
      delay(200);
      TurnRight(currentDirection, number);
      count = 0;
    }
  }
}  


//=======================================================================

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

void GoStraight()
{
  motorSpeedA = 60;
  motorSpeedB = 60;

  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);  

  analogWrite(9, motorSpeedA);
  analogWrite(10, motorSpeedB);  
}

void HoldOn()
{
  motorSpeedA = 0;
  motorSpeedB = 0;

  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);  

  analogWrite(9, motorSpeedA);
  analogWrite(10, motorSpeedB);   
}

void TurnRight(long currentDirection, long number)
{
  long startDirection = currentDirection;
  long endDirection = startDirection - number;

  Serial.print("StartDirection = ");
  Serial.println(startDirection);
  
  Serial.print("Enddirection: ");
  Serial.println(endDirection);
  
  while(currentDirection > endDirection || currentDirection <= 10)  //small tolerance
  {
    motorSpeedA = 60;
    motorSpeedB = 60;

    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);  

    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB);

     currentDirection = ReadCompass();
     currentDirection -= offset;
     currentDirection += 4;

     if (currentDirection < 0)
     {
       currentDirection += 360;
     }

     if (currentDirection == 0 && endDirection == 0)
     {
      break;
     }

     Serial.print("Direction = ");
     Serial.println(currentDirection);
     Serial.print("DirectionGoal = ");
     Serial.println(endDirection);     
  }   
}

void valueChangedUp()
{   
  valueA = digitalRead(23);
  
  if (valueA == 0)
  { 
      count--;
  }
  else
  {
    count++;
  }
}

void valueChangedDown()
{
  valueA = digitalRead(23);
  
   if (valueA == 1)
  { 
      count--;
  }
  else
  {
    count++;
  } 
}
