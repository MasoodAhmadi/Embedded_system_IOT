#include <Wire.h>
#define CMPS14_address 0x60


void setup() {

  Wire.begin();

  Serial.begin(9600);
  
  Serial.println("Test");

}

void loop() {

Wire.beginTransmission(CMPS14_address);
//Serial.println("1");

Wire.write(1);
//Serial.println("2");

Wire.endTransmission(false);
//Serial.println("3");

Wire.requestFrom(CMPS14_address, 1, true);
//Serial.println("4");

if ( Wire.available() >= 1 )
{
  long raw = Wire.read();

  long value = raw * 360;

value = value/255;

  //byte value = map(raw, 255, 0, 360, 0);

  Serial.print("Degree value: ");

  Serial.println((long)value);

  delay(100);
}

}
