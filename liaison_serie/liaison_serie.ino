#include<Servo.h>


Servo myservo;
int pulse = 0;
int newPulse = 0;
const int MaxChars = 5;
char strValue[MaxChars+1];
int index = 0;


void setup()
{
 Serial.begin(9600);
 myservo.attach(A9);
 pulse = 1500;
}


void loop()
{}


void serialEvent()
{
   while(Serial.available()) 
   {
      char ch = Serial.read();
      Serial.write(ch);
      if(index < MaxChars && isDigit(ch)) { 
            strValue[index++] = ch; 
      } else { 
            strValue[index] = 0; 
            newPulse = atoi(strValue); 
            if(newPulse > 1000 && newPulse < 2000){
                   if(newPulse < pulse) 
                       for(; pulse > newPulse; pulse -= 1) {
                             myservo.writeMicroseconds(pulse);
                       }  
                    else 
                       for(; pulse < newPulse; pulse += 1){
                          myservo.writeMicroseconds(pulse);
                    } 
            }
            index = 0;
            pulse = newPulse;
      }  
   }
}



