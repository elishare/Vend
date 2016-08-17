int motorPin = 9;
int LedPin = 13;
void setup() {
   
 pinMode(motorPin, OUTPUT);
 pinMode(LedPin, OUTPUT);
 
}
void loop() {
 digitalWrite(motorPin, HIGH);
 digitalWrite (LedPin, HIGH);
 delay(10000); 
 digitalWrite(motorPin, LOW);
 digitalWrite (LedPin, LOW);
 delay(10000);
 
}
