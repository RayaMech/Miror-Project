#include<Servo.h>

Servo actuator1;
//Servo actuator2;

void loop(){
  actuator1.attach(9);
  //actuator2.attach(10);
  actuator1.writeMicroseconds(2000);
  //actuator2.writeMicroseconds(2000);
  delay(3000);
}

void setup(){
  actuator1.writeMicroseconds(1000);
  //actuator2.writeMicroseconds(1000);
  delay(3000);
  actuator1.writeMicroseconds(2000);
  //actuator2.writeMicroseconds(1000);
  delay(3000);
}
