#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

#define servoMIN 150
#define servoMAX 600
//#define servo1 0
//#define servo2 13
//#define servo3 14
//#define servo4 15


uint8_t servonum = 0;

void setup(){
  Serial.begin(9600);
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
//Serial.println("16 channel Servo test!");
  pwm1.begin();
  pwm2.begin();
 // pwm1.setPWMFreq(60); //Analog servos run at ~60 Hz
 // pwm2.setPWMFreq(60);
  pwm1.writeMicroseconds(0, 1900);
  //pwm.writeMicroseconds(servo2, 1900);
  //pwm.writeMicroseconds(servo3, 1900);
  //pwm.writeMicroseconds(servo4, 1900);
  delay(3000);
  //yield();
}

void loop(){
  pwm1.writeMicroseconds(0, 1100);
  //pwm.writeMicroseconds(servo2, 1100);
  //pwm.writeMicroseconds(servo3, 1100);
  //pwm.writeMicroseconds(servo4, 1100);
  delay(3000);
  /*
  pwm.writeMicroseconds(servo, 1500);
  delay(3000);
  
  pwm.writeMicroseconds(servo, 1250);
  delay(3000);
  
  pwm.writeMicroseconds(servo, 1100);
  delay(3000);
  */
  exit(0);
 /* 
  //Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
  //for (int servo = 0; servo < 4; servo++){
    pwm.setPWM(1, 0, 0);
    //Serial.println(servo);
    delay(500);
  //}
  
  pwm.setPWM(4, 0, 200);
    //Serial.println(servo);
  delay(500);
  
  pwm.setPWM(1, 0, 400);
    //Serial.println(servo);
  delay(500);
  
  pwm.setPWM(2, 0, 600);
    //Serial.println(servo);
  delay(500);
  */
  
  
  //pwm.writeMicroseconds(0, 1900);
  //delay(3000);
 
}


