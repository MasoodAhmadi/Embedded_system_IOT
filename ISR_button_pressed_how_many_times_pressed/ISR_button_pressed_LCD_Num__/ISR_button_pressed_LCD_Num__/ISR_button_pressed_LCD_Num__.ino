#include <LiquidCrystal.h>
LiquidCrystal lcd(16,17,18,19,20,21);
int sum=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRA =B11111111;
  pinMode(2, INPUT);
  attachInterrupt(0, buttonPressed, FALLING);
}
void loop () {
}
void buttonPressed () {
  lcd.setCursor(1,0);
  lcd.print("Pressed = "); 
  lcd.print(sum++);
  lcd.println(" times");
}
