int motorSpeedA = 0;
int motorSpeedB = 0;

void setup(){
  pinMode(9, OUTPUT);   //speedA
  pinMode(7, OUTPUT);   //directionA
  pinMode(10, OUTPUT);  //speedB
  pinMode(8, OUTPUT);   //directionB
}

void loop()
  {

    // 2 sec forward 25%/25%
    // 1)motor direction
    
    //Set Motor A forward
    digitalWrite(7, HIGH);
    
    //Set Motor B forward
    digitalWrite(8, HIGH);
    
    // 2)motor speed
    motorSpeedA = 255 * 0.25;
    motorSpeedB = 255 * 0.25;
    
    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB); 
    delay(2000); 


    //Pause
    analogWrite(9, 0);
    analogWrite(10, 0);
    delay(500);

    // 3 sec forward 25%/50%
    // 1)motor direction
    
    //Set Motor A forward
    digitalWrite(7, HIGH);
    
    //Set Motor B forward
    digitalWrite(8, HIGH);
    
    // 2)motor speed
    motorSpeedA = 255 * 0.5;
    motorSpeedB = 255 * 0.25;
    
    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB);
    delay(3000);   

    //Pause
    analogWrite(9, 0);
    analogWrite(10, 0);
    delay(500);

    // 3 sec backward 50%/25%
    // 1)motor direction
    
    //Set Motor A backward
    digitalWrite(7, LOW);
    
    //Set Motor B backward
    digitalWrite(8, LOW);
    
    // 2)motor speed
    motorSpeedA = 255 * 0.25;
    motorSpeedB = 255 * 0.5;

    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB);
    delay(3000);

    //Pause
    analogWrite(9, 0);
    analogWrite(10, 0);
    delay(500);

    // 2 sec backward 25%/25%
    // 1)motor direction
    
    //Set Motor A backward
    digitalWrite(7, LOW);
    
    //Set Motor B backward
    digitalWrite(8, LOW);
    
    // 2)motor speed
    motorSpeedA = 255 * 0.25;
    motorSpeedB = 255 * 0.25;

    analogWrite(9, motorSpeedA);
    analogWrite(10, motorSpeedB);
    delay(2000);

    //stop
    analogWrite(9, 0);
    analogWrite(10, 0);    
  }
