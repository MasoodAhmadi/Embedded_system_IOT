#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  // can be replaced by DDRA = B11111111 and usage of A port 
 pinMode(enA, OUTPUT); 
 pinMode(enB, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 pinMode(in3, OUTPUT);
 pinMode(in4, OUTPUT);
}

void loop() {
  int xAxis = analogRead(A0);   //Joystick connection
  int yAxis = analogRead(A1);   // y-Axis = Up/Down = Forward/Backward

  // Y-Axis controls movement direction

  if (yAxis < 500)  //small tolerance added to 512
  {
    // 1)Convert joystick position to motor direction
    
    //Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    //Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    // 2)Convert joystick position to motor speed
    motorSpeedA = map(yAxis, 500, 0, 0, 255);
    motorSpeedB = map(yAxis, 500, 0, 0, 255);
  }

  else if (yAxis > 524)
  {
    // 1)Convert joystick position to motor direction
    
    //Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    //Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);

    // 2)Convert joystick position to motor speed
    motorSpeedA = map(yAxis, 524, 1023, 0, 255);
    motorSpeedB = map(yAxis, 524, 1023, 0, 255);
  }

  else  //if joystick position is in the middle
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  // X-Axis controls left/right turns

  if(xAxis < 500)
  {
    int xMapped = map(xAxis, 500, 0, 0, 255);

    motorSpeedA = motorSpeedA - xMapped;  //decrease A-Speed
    motorSpeedB = motorSpeedB + xMapped;  //increase B-Speed

    if (motorSpeedA < 0)    // check limitations
    {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255)
    {
      motorSpeedB = 255;
    }
  }

    if(xAxis > 524)
  {
    int xMapped = map(xAxis, 524, 1023, 0, 255);

    motorSpeedA = motorSpeedA + xMapped;  //decrease A-Speed
    motorSpeedB = motorSpeedB - xMapped;  //increase B-Speed

    if (motorSpeedB < 0)    // check limitations
    {
      motorSpeedB = 0;
    }
    if (motorSpeedA > 255)
    {
      motorSpeedA = 255;
    }
  }

// Prevent buzzing at low speeds, maybe has to be adjusted

  if (motorSpeedA < 70)
  {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70)
  {
    motorSpeedB = 0;
  }

  //Send PWM signals to motors

  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);

}
