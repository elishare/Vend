//Define the mapping of each of the motors and digital pins

//Row A
int motorPinA1 = 2;
int motorPinA3 = 3;
int motorPinA5 = 4;
int motorPinA7 = 5;

//Row B
int motorPinB1 = 6;
int motorPinB3 = 7;
int motorPinB5 = 8;
int motorPinB7 = 9;

//Row C
int motorPinC1 = 10;
int motorPinC3 = 11;
int motorPinC5 = 12;
int motorPinC7 = 22;

//Row D
int motorPinD1 = 23;
int motorPinD3 = 24;
int motorPinD5 = 25;
int motorPinD7 = 26;

//Row E
int motorPinE1 = 27;
int motorPinE2 = 28;
int motorPinE3 = 29;
int motorPinE4 = 30;
int motorPinE5 = 31;
int motorPinE6 = 32;
int motorPinE7 = 33;
int motorPinE8 = 34;

//Row F
int motorPinF1 = 35;
int motorPinF3 = 36;
int motorPinF5 = 37;
int motorPinF7 = 38;

//Row G
int motorPinG1 = 39;
int motorPinG2 = 40;
int motorPinG3 = 41;
int motorPinG4 = 42;

//Define debug LED pin
int LedPin = 13;
char spot[4]; //array for serial write buffer

int Letter, Number; 

void setup() {
  Serial.begin(9600);

//Set digital pins as output for low end pins 2-12
int pinNumLow = 12;

 for(int i=2; i<=pinNumLow; i++)
{
  pinMode(i, OUTPUT);
}
  
//Set digital pins as output for high end pins 22-42  
int pinNumHigh = 42;
 
 for(int i=22; i<=pinNumHigh; i++)
{
  pinMode(i, OUTPUT);
}
   pinMode(LedPin, OUTPUT); //LED pin as output
   
  Serial.println("Live and working"); //debug Arduino booted
}

void loop() {
 while (Serial.available())  { //wait for serial connection to establish
  delay (30); // delay for buffer to fill with all location information
  if (Serial.available()<5){ //wait for serial buffer to have less than 5 bytes of information
     int Bytes = Serial.available(); //assign Bytes to number of serial bytes available
     
     for (int i=0; i<Bytes; i++) // with total bytes, assign an array with each byte in the serial command
      {
        spot[i] = Serial.read();
        Serial.print(spot[i]); //debug print each time a byte is written to the array
        //Serial.println(Bytes); //debug print number of Bytes
          if (spot[i] == 'x'){ //look for termination byte 'x' to stop writing to array and jump into motor spin function
          
            //Serial.println("moto"); //debug line to check if entered 'x' call

            /* Debug commands to read array
            int one = spot[0];
            int two = spot[1];
            int three = spot[2];
          
            Serial.println(one);
            Serial.println(two);
            Serial.println(three);
            */
          
            Letter = spot[0];  //assign int Letter to location row in array
            Number = spot[1];  //assign int Number to location column in array
          
           motor(Letter, Number); //call motor spin function. 

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
    digitalWrite(motorPinA1, HIGH);
    digitalWrite (LedPin, HIGH);
    delay(2000); //spin motor for 2 seconds

    //Stop motor spin
    digitalWrite(motorPinA1, LOW);
    digitalWrite (LedPin, LOW);
    delay(100); //
    
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
