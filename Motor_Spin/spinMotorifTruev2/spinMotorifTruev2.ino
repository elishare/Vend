int motorPin = 9;
int LedPin = 13;
char spot[4];
int Letter, Number;

void setup() {
  Serial.begin(9600);
   pinMode(motorPin, OUTPUT);
   pinMode(LedPin, OUTPUT);
Serial.println("Live and working");
}

void loop() {
 while (Serial.available())  {
  delay (30);
  if (Serial.available()<5){
     int Bytes = Serial.available();
     
     for (int i=0; i<Bytes; i++)
     {
      spot[i] = Serial.read();
      Serial.print(spot[i]);
      //Serial.println(Bytes);
        if (spot[i] == 'x'){
          //Serial.println("moto");
          
          //int one = spot[0];
          //int two = spot[1];
          //int three = spot[2];
          
          //Serial.println(one);
          //Serial.println(two);
          //Serial.println(three);
          
          Letter = spot[0];
          Number = spot[1];
          
          motor(Letter, Number); 

      }
     }
  }
}

}


void motor(int row, int column){
  //Serial.println("void");
  //Serial.println(row);
  char letter = row;
  //Serial.println(letter);
  char number = column;
  if (letter == 'A' && number== '1'){
  //Serial.println("location");
  digitalWrite(motorPin, HIGH);
  digitalWrite (LedPin, HIGH);
  delay(10000); 
  digitalWrite(motorPin, LOW);
  digitalWrite (LedPin, LOW);
  delay(10000);
  flushMySerial();
  }
  
  else
  {
    digitalWrite (LedPin, HIGH);
    delay(1000);
    digitalWrite (LedPin, LOW);
    delay(1000);
    flushMySerial();
}
}

void flushMySerial(){
  while(Serial.available())
  Serial.read();
}

