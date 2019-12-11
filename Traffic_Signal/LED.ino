#include<LiquidCrystal.h>

LiquidCrystal lcd (16,17,18,19,20,21);

void setup() {
  // put your setup code here, to run once:
DDRD =B11111111;

  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
}
void loop() {
  digitalWrite(21, HIGH);
  digitalWrite(20, LOW);
  digitalWrite(19, LOW);
  digitalWrite(18,HIGH);
  digitalWrite(17,LOW);
  digitalWrite(16,LOW);
  delay(5000);
  digitalWrite(20,HIGH);
  digitalWrite(17,LOW);
  delay(1000);
  digitalWrite(19,HIGH);
  digitalWrite(18,LOW);
  digitalWrite(17,LOW);
  digitalWrite(21,LOW);
  digitalWrite(20,LOW);
  digitalWrite(16,HIGH);
  delay(5000);
  digitalWrite(20,LOW);
  digitalWrite(17,HIGH);
  delay(1000);
  digitalWrite(21, HIGH);
  digitalWrite(20, LOW);
  digitalWrite(19, LOW);
  digitalWrite(18,HIGH);
  digitalWrite(17,LOW);
  digitalWrite(16,LOW);
  delay(5000);
  
  

 



}
