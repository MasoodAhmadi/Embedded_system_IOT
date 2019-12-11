#include <LiquidCrystal.h>;
LiquidCrystal lcd(16, 17, 18, 19, 20, 21);

volatile int buttonState = 0;

void setup() {
  Serial.begin(9600);
  DDRA = B11111111;
  pinMode(2, INPUT);
  attachInterrupt(0, buttonPressed, FALLING);
}

void loop() {
  
  lcd.setCursor(1,0);
  lcd.print("Motor = ");
      lcd.print("    ");


  if( buttonState == 0)
  {
  lcd.print("OFF");
  delay(500);
  }
  else
  {
  lcd.print("ON    ");
  delay(500);
  }
}


void buttonPressed(){

  if (buttonState == 0)
  {
    buttonState = 1;  //ON
  }
  else
  {
    buttonState = 0;  //OFF
  }
}
