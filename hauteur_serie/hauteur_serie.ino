#include <Servo.h>

Servo actuator;
//#define hauteur +5

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
      Serial.println(ch);
      if(index < MaxChars && isDigit(ch)) { 
            strValue[index++] = ch; 
      } else { 
            strValue[index] = 0; 
            float hauteur = atoi(strValue); 
            Serial.println(hauteur);
            newPulse = -(50*hauteur) + 1500;
            Serial.println(newPulse);
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
