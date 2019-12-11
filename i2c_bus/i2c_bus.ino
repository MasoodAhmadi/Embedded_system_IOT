#include<Wire.h>
#define CMPS14_address 0x60
void setup(){
    // request reading from sensor
    Wire.begin();
    Serial.begin(9600);

}
void loop (){
 // delay(50);
 // int compas_oft=read_compas_raw();
 // Serial.println("Compas oft");
 // Serial.println(compas_oft);
 // int read_compase_raw(void) // return +/1 180 degree
  //long dir = 1;
      Wire.beginTransmission(CMPS14_address);
      //Serial.println("test");
      Wire.write(1);
      Wire.endTransmission(false);
      //Serial.println("test_1");
      Wire.requestFrom(CMPS14_address, 1,true); // request 2 bytes from slave device #112
    if(Wire.available() >=1){
    byte raw =Wire.read();
    Serial.println(raw);
    delay(100);
    }
}
