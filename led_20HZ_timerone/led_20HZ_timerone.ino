#include <TimerOne.h>;
volatile int buttonState = 0;
void setup() {
  Timer1.initialize(25000);
  Serial.begin(9600);
  DDRA = B11111111;
  pinMode(2, OUTPUT);
  Timer1.attachInterrupt(Timer_led);

}
void loop () {

}
void Timer_led(){
 if (buttonState == 0)
  {
    buttonState = 1;  //ON
    digitalWrite(2, HIGH);
  }
  else
  {
    buttonState = 0;  //OFF
    digitalWrite(2,LOW);
  }
  
}
