#include<LiquidCrystal.h>
LiquidCrystal lcd(16,17,18,19,20,21);

void setup(){

  DDRA = B11111111;   // decfine Port A aus digital Output for the button
}

void loop(){

float inputX = analogRead(A8);  //X potentiometer
//float inputY = analogRead(A9);

int percentageX = 0;
//int percentageY = 0;

percentageX = (inputX / 1024 -0.5)*200;   //gives percentage value between -100 and +100
//percentageY = (inputY / 1024 -0.5)*200;

int value = 30 + percentageX/10;
   
    lcd.setCursor(0,0);   //set LCD upper row
    lcd.print("-100%");
    lcd.setCursor(10,0);
    lcd.print("0%");
    lcd.setCursor(15,0);
    lcd.print("+100%");

    lcd.setCursor(20,0);
    lcd.print("                      "); //free spaces
    lcd.setCursor(value,0);
    lcd.print("|");

    
}
