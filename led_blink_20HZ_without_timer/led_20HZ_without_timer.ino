
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 // DDRA =B11111111;
  pinMode(2, OUTPUT);
 //  attachInterrupt(0, buttonPressed, FALLING);
}
void loop () {
  //int sensorValue = analogRead(A0); //sensorValue: 0~1023
  int delay_time =50 ;
  //int delay_time = map(sensorValue, 0, 1023, 5, 1000); 
  //if(500/delay_time==0) Serial.print("0.5");
  //else Serial.print(500/delay_time);                    this comments is for potentiaometer
  Serial.print(1000/delay_time);
  Serial.println(" Hz");
  digitalWrite(2, HIGH);    
  delay(delay_time);               
  digitalWrite(2, LOW);     
  delay(delay_time);     
}
