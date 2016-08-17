int motorPin = 9;
int LedPin = 13;
char spot[3];

void setup() {
  Serial.begin(9600);
   pinMode(motorPin, OUTPUT);
   pinMode(LedPin, OUTPUT);

}

void loop() {
 while (Serial.available())  {
     int Bytes = Serial.available();
     for (int i=0; i<Bytes; i++)
     {
      spot[i] = Serial.read();
      if (Serial.read() == '\n')
      {
        motor(spot[]); 
      }
     }
  }
}

void motor(spot[]){
  for (spot[1] == 'A' && spot[2]== '1'){
 digitalWrite(motorPin, HIGH);
 digitalWrite (LedPin, HIGH);
 delay(10000); 
 digitalWrite(motorPin, LOW);
 digitalWrite (LedPin, LOW);
 delay(10000);
  }
  else
  {
    digitalWrite (LedPin, HIGH);
    delay(1000);
    digitalWrite (LedPin, LOW);
    delay(1000);
}
}
