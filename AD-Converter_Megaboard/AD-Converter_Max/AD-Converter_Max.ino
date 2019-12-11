#include<LiquidCrystal.h>
#include <math.h>
LiquidCrystal lcd (16,17,18,19,20,21);

float analogPin = A5; // potentiometer wiper (middle terminal) connected to analog pin 3 // outside leads to ground and +5V
int analogPin2 = A3; // 3.3V level
float Value=0;
float val=0;
float mega=0;
float val2 = 0;

void setup() {
  Serial.begin(9600);           //  setup serial
}
void loop() {
   Value=analogRead(A5);
   mega=analogRead(A3);

   val = Value * 4.99 / 1023.0; // see text
   val2= mega *4.99 /1023.0;
   
    lcd.setCursor(1,0);
    lcd.print("Pot.meter=");
    lcd.setCursor(12,0);
    lcd.print(val);
    lcd.setCursor(17,0);
    lcd.print("V");
    lcd.setCursor(21,0);
    lcd.print("3.3 level = ");
    lcd.setCursor(33,0);
    lcd.print(val2);
    lcd.setCursor(37,0);
    lcd.print(" V");

}
