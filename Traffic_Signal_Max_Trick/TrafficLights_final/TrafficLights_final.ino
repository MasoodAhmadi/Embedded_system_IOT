void setup() {
  // set up all the LEDs as OUTPUT
  DDRA=B11111111;
}

void loop() {

  PORTA |= (1 << 3);  //red
  PORTA |= (1 << 2);  //green
  delay(5000);  // wait 5 seconds 
  //PORTA |= (1 << 3);  //red
  //PORTA |= (1 << 2);  //green
  //PORTA |= (1 << 6);  //green for right turning only
  //delay(3000);
  PORTA &= ~(1 << 3);
  PORTA &= ~(1 << 2);
  //PORTA &= ~(1 << 6);
  
  // turn the yellow LED on and the other LEDs off

  PORTA |= (1 << 4);  //both yellow
  PORTA |= (1 << 1);
  delay(2000);   // wait 2 seconds
  PORTA &= ~(1 << 4);
  PORTA &= ~(1 << 1);
  
  // turn the red LED on and the other LEDs off

  PORTA |= (1 << 5);  //green
  PORTA |= (1 << 0);  //red
  delay(2000);    // wait 5 seconds
  PORTA |= (1 << 5);  //green
  PORTA |= (1 << 0);  //red
  PORTA |= (1 << 6);  //green for right turning only
  delay(3000);
  PORTA &= ~(1 << 5); 
  PORTA &= ~(1 << 0);
  PORTA &= ~(1 << 6);
  
  // turn the yellow LED on and the other LEDs off

  PORTA |= (1 << 4);  //both yellow
  PORTA |= (1 << 1);
  delay(2000);   // wait 2 seconds
  PORTA &= ~(1 << 4);
  PORTA &= ~(1 << 1);       
}
