
int sum=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRA =B11111111;
  pinMode(2, INPUT);
  attachInterrupt(0, buttonPressed, FALLING);
}
void loop () {
}
void buttonPressed () {
  // digitalWrite (2, HIGH);
   Serial.print("Pressed= ");
     Serial.print(sum++);
     Serial.println (" times");

   
}
