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

int motorOntime = 2000; //time the motor is on when selection is made 2 secs

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

    switch (letter) {
      case 'A':
      {
        Serial.println("In the A case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinA1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("A1");

            //Stop motor spin
            digitalWrite(motorPinA1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '3':
          {
            digitalWrite(motorPinA3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("A3");

            //Stop motor spin
            digitalWrite(motorPinA3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '5':
          {
            digitalWrite(motorPinA5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("A5");

            //Stop motor spin
            digitalWrite(motorPinA5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '7':
          {
            digitalWrite(motorPinA7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("A7");

            //Stop motor spin
            digitalWrite(motorPinA7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;
      
      case 'B':
      {
        Serial.println("In the B case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinB1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("B1");

            //Stop motor spin
            digitalWrite(motorPinB1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '3':
          {
            digitalWrite(motorPinB3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("B3");

            //Stop motor spin
            digitalWrite(motorPinB3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '5':
          {
            digitalWrite(motorPinB5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("B5");

            //Stop motor spin
            digitalWrite(motorPinB5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '7':
          {
            digitalWrite(motorPinB7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("B7");

            //Stop motor spin
            digitalWrite(motorPinB7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;

case 'C':
      {
        Serial.println("In the C case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinC1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("C1");

            //Stop motor spin
            digitalWrite(motorPinC1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '3':
          {
            digitalWrite(motorPinC3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("C3");

            //Stop motor spin
            digitalWrite(motorPinC3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '5':
          {
            digitalWrite(motorPinC5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("C5");

            //Stop motor spin
            digitalWrite(motorPinC5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '7':
          {
            digitalWrite(motorPinC7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("C7");

            //Stop motor spin
            digitalWrite(motorPinC7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;

case 'D':
      {
        Serial.println("In the D case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinD1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("D1");

            //Stop motor spin
            digitalWrite(motorPinD1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '3':
          {
            digitalWrite(motorPinD3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("D3");

            //Stop motor spin
            digitalWrite(motorPinD3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '5':
          {
            digitalWrite(motorPinD5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("D5");

            //Stop motor spin
            digitalWrite(motorPinD5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '7':
          {
            digitalWrite(motorPinD7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("D7");

            //Stop motor spin
            digitalWrite(motorPinD7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;

case 'E':
      {
        Serial.println("In the E case");
        //Serial.println(number);
        
        switch (number) {
        case '1':
          {
            digitalWrite(motorPinE1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E1");

            //Stop motor spin
            digitalWrite(motorPinE1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
        case '2':
          {
            digitalWrite(motorPinE2, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E2");

            //Stop motor spin
            digitalWrite(motorPinE2, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
        case '3':
          {
            digitalWrite(motorPinE3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E3");

            //Stop motor spin
            digitalWrite(motorPinE3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
        case '4':
          {
            digitalWrite(motorPinE4, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E4");

            //Stop motor spin
            digitalWrite(motorPinE4, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '5':
          {
            digitalWrite(motorPinE5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E5");

            //Stop motor spin
            digitalWrite(motorPinE5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '6':
          {
            digitalWrite(motorPinE6, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E6");

            //Stop motor spin
            digitalWrite(motorPinE6, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '7':
          {
            digitalWrite(motorPinE7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E7");

            //Stop motor spin
            digitalWrite(motorPinE7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '8':
          {
            digitalWrite(motorPinE8, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("E8");

            //Stop motor spin
            digitalWrite(motorPinE8, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;

case 'F':
      {
        Serial.println("In the F case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinF1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("F1");

            //Stop motor spin
            digitalWrite(motorPinF1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '3':
          {
            digitalWrite(motorPinF3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("F3");

            //Stop motor spin
            digitalWrite(motorPinF3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '5':
          {
            digitalWrite(motorPinF5, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("F5");

            //Stop motor spin
            digitalWrite(motorPinF5, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '7':
          {
            digitalWrite(motorPinF7, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("F7");

            //Stop motor spin
            digitalWrite(motorPinF7, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;

case 'G':
      {
        Serial.println("In the G case");
        //Serial.println(number);
        
        switch (number) {
          case '1':
          {
            digitalWrite(motorPinG1, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("G1");

            //Stop motor spin
            digitalWrite(motorPinG1, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
          case '2':
          {
            digitalWrite(motorPinG2, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("G2");

            //Stop motor spin
            digitalWrite(motorPinG2, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          }break;
          
           case '3':
          {
            digitalWrite(motorPinG3, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("G3");

            //Stop motor spin
            digitalWrite(motorPinG3, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial(); 
          }break;

           case '4':
          {
            digitalWrite(motorPinG4, HIGH);
            digitalWrite (LedPin, HIGH);
            delay(motorOntime);

            Serial.println("G4");

            //Stop motor spin
            digitalWrite(motorPinG4, LOW);
            digitalWrite (LedPin, LOW);
            delay(100); //
    
          flushMySerial();
          } break;
          
          default:
          Serial.println("no matching column");
            for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
          break;
        }
      }break;
      
     default:
        Serial.println("no matching row");
        for (int i=0; i<10; i++){
              digitalWrite (LedPin, HIGH);
              delay(1000);
              digitalWrite (LedPin, LOW);
              delay(1000);
            }
     break;
    }
    
    
    /*
    if (letter == 'A' && number== '1'){
    //Serial.println("location");
    digitalWrite(motorPinA1, HIGH);
    digitalWrite (LedPin, HIGH);
    delay(motorOntime); //spin motor for 2 seconds

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
  }*/
}


void flushMySerial(){
  while(Serial.available())
  Serial.read();
}
