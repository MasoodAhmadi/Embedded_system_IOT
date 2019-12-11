#include<LiquidCrystal.h>

LiquidCrystal lcd (16,17,18,19,20,21);

void setup() {
  // put your setup code here, to run once:
    DDRD =B11111111;

}

void loop() {
  float inputX=analogRead(A8);
  float inputY=analogRead(A9);

    lcd.setCursor(1,0);
    lcd.print("Xpot Value = ");
    lcd.setCursor(13,0);
    lcd.print(inputX);

    lcd.setCursor(21,0);
    lcd.print("Ypot Value = ");
    lcd.setCursor(33,0);
    lcd.print(inputY);
}
