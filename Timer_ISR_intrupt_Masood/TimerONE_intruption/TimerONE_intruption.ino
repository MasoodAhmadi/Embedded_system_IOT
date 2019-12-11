#include<LiquidCrystal.h>
#include<TimerOne.h>
LiquidCrystal lcd(16, 17, 18, 19, 20, 21);

//int time;
int seconds=00;
int minutes=00;
int hrs=00;
 
void setup() {
  // put your setup code here, to run once:
Timer1.initialize(1000000);
Timer1.attachInterrupt(my_timer_int_routine);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(1,0);
  lcd.print("Clock ");
  lcd.print(hrs);       //hours 
  
  lcd.print(" : ");     // minute
  lcd.print(minutes);
  
  lcd.print(" : ");     //seconds
  lcd.print(seconds);
  lcd.print("    ");
}
void my_timer_int_routine(){
      seconds++;
      if (seconds==60 && seconds <61){
          minutes++;
          seconds=0;
      }
         
     if  (minutes==60 && minutes <61){
          hrs++;
          minutes=0;
          }
}
