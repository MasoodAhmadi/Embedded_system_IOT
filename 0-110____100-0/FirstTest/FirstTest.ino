#include<LiquidCrystal.h>
#include <math.h>
LiquidCrystal lcd (16,17,18,19,20,21);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=0; i<99; i++)
  {
    //clear zeroes from number
    lcd.setCursor(2,0);
    lcd.print("  ");
    lcd.setCursor(2,0);
    lcd.print(i);
    delay(100);

    lcd.setCursor(20,0);
    lcd.print("  ");
    lcd.setCursor(20,0);
    lcd.print(pow(i,1.4), 3);
    delay(100);
    
    lcd.setCursor(12,0);
    lcd.print("   ");
    lcd.setCursor(12,0);
    lcd.print(99-i);
    delay(100);

    lcd.setCursor(30,0);
    lcd.print("   ");
    lcd.setCursor(30,0);
    lcd.print(-pow(i,1.4), 1);
    delay(100);
  }

}
