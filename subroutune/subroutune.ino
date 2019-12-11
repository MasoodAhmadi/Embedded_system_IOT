#include<LiquidCrystal.h>
int Red_Led_Control(int);
void setup() {
  // put your setup code here, to run once:
  DDRD =B11111111;
}
void loop(){
  Red_Led_Control( 1);
  delay(200);
  Red_Led_Control( 0);
  delay(200);
  }
int Red_Led_Control(int state) {
 
  
  if (state ==1) {
    PORTD=0x00000001;
    }
   else if(state == 0) {
    PORTD=0x00000000;
   }
}
