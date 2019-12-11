#include<LiquidCrystal.h>           //library for LCD
#include <math.h>
LiquidCrystal lcd (16,17,18,19,20,21);  // pin definition for LCD
#include <string.h>



void setup() {
  Serial.begin(9600);

  Serial.println("Hello");
  lcd.setCursor(1,0);
  lcd.write("Received: ");

  pinMode (24, OUTPUT);
}

void loop() {

  String input;

   /* lcd.setCursor(12,0);    
    lcd.print(testData);

    Serial.println(testData);

    int position1 = testData.indexOf('H');
    Serial.print("Position: ");
    Serial.println(position1);
    delay(5000);*/
  
  if (Serial.available() ) 
  {
    input = Serial.readStringUntil('\n');
    
    lcd.setCursor(12,0);    
    lcd.print(input);

    Serial.println(input);

    int position1 = input.indexOf('O');
    Serial.print("Position: ");
    Serial.println(position1);

    String decision = input.substring(position1);

    int position2 = position1 + 1;

    if (decision == "ON")
    {
      digitalWrite(24, HIGH);
      Serial.println("LED is ON");
      delay(3000);
    }
    else if (decision == "OFF")
    {
      digitalWrite(24, LOW);
      Serial.println("LED is OFF");
      delay(3000);
    }
    
  }
}
