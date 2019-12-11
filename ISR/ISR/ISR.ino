#include<LiquidCrystal.h>
LiquidCrystal lcd (16, 17,18,19,20,21);
 int digitalpin=A15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 /// DDRD =B11111111;
  DDRA =B11111111;
}
void loop() {
  // put your main code here, to run repeatedly:
int Button=digitalRead(A15);
  
  if (Button==1)
  {
   Serial.println(" PRESSED");
   Serial.print(HIGH);
  }
  else {
    Serial.println(" NOT PRESSED");
    Serial.print(LOW);
  }
 };
