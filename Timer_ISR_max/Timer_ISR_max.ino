#include <LiquidCrystal.h>
LiquidCrystal lcd (16,17,18,19,20,21);
#include <TimerOne.h>

/*int sec_var;
int min_var;
int hour_var;*/

int sec_count = 00;
int min_count = 00;
int hour_count = 00;

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Timer_int_routine);
}

void loop() {
  
lcd.setCursor(1,0);
lcd.print("T = ");

//lcd.setCursor(4,0);       
lcd.print(hour_count);  //hours

//lcd.setCursor(6,0);
lcd.print(" :");       //minutes
lcd.print(min_count);

//lcd.setCursor(9,0);
lcd.print(" :");       //seconds
lcd.print(sec_count);
lcd.print("   "); 
}

void Timer_int_routine()
{
  //sec_var++;
  sec_count++;

  if(sec_count == 60 && sec_count < 61)
  {
    //min_var++;
    min_count++;
    sec_count = 0;
  }

    if(min_count == 60 && min_count < 61)
  {
    //hour_var++;
    hour_count++;
    min_count = 0;
  }
}
