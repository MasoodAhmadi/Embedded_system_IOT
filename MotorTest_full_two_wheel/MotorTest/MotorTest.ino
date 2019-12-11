int motorSpeedA = 0;
int motorSpeedB = 0;

void setup(){
  pinMode(9, OUTPUT);   //speedA
  pinMode(7, OUTPUT);   //directionA
  pinMode(10, OUTPUT);  //speedB
  pinMode(8, OUTPUT);   //directionB
}

void loop(){

float inputX = analogRead(A8);  //X potentiometer
//float inputY = analogRead(A9);

  if (inputX < 500)  //small tolerance added to 512
  {
    // 1)Convert joystick position to motor direction
    
    //Set Motor A backward
    digitalWrite(7, HIGH);
    digitalWrite(9, LOW);

    //Set Motor B backward
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);

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

  analogWrite(9, motorSpeedA);
  analogWrite(10, motorSpeedB);
    
}
