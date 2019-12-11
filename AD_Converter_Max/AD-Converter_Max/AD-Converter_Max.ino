#include<LiquidCrystal.h>
#include <math.h>
LiquidCrystal lcd (16,17,18,19,20,21);

float analogPin = A5; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int analogPin2 = A3; // 3.3V level
float Value=0;
float val=0;
//double val = (sensorValue * 4.46) / 1024.0; // see text  // variable to store the value read
float val2 = 0;

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
   Value=analogRead(A5);
   val = Value * 4.46 / 1023.0; // see text
    //val = analogRead(sensorValue);  // read the input pin
   // Serial.println(val);          // debug value
    lcd.setCursor(1,0);
    lcd.print("Pot.meter=");
    lcd.setCursor(12,0);
    lcd.print(val);
    lcd.setCursor(17,0);
    lcd.print("V");

    //delay(3000);

    lcd.setCursor(21,0);
    lcd.print("3.3 level = ");
    lcd.setCursor(33,0);
    lcd.print(val2);
    
    //delay(3000);
}
