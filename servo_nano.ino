#include <Servo.h>

int servoPin = 7;

Servo servo1;

void setup(){
  servo1.attach(servoPin);
  servo1.writeMicroseconds(2000);
  delay(3000);
}

void loop(){
  servo1.writeMicroseconds(1000);
  delay(3000);
  servo1.writeMicroseconds(2000);
  delay(3000);
}
