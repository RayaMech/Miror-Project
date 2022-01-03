#include <Wire.h>
#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define servoMIN 150
#define servoMAX 600
#define servo1 0
#define servo2 1
//#define servo3 2
//#define servo4 3

#define servo5 4
#define servo6 5
//#define servo7 6
//#define servo8 7

#define servo9 8
#define servo10 9
//#define servo11 0
//#define servo12 11

//#define servo13 12
//#define servo14 13
#define servo15 14
#define servo16 15

#define hauteur1 +4.5874
#define hauteur2 +4.5874
//#define hauteur3 +4.5874
//#define hauteur4 +4.5874

#define hauteur5 +4.5874
#define hauteur6 +4.5874
//#define hauteur7 +4.5874
//#define hauteur8 +4.5874

#define hauteur9 +4.5874
#define hauteur10 +4.5874
//#define hauteur11 +4.5874
//#define hauteur12 +4.5874

//#define hauteur13 +4.5874
//#define hauteur14 +4.5874
#define hauteur15 +4.5874
#define hauteur16 +4.5874


uint8_t servonum = 0;

void setup(){
  Serial.begin(9600);
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
//Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60); //Analog servos run at ~60 Hz
  pwm.writeMicroseconds(servo1, 1500);
  pwm.writeMicroseconds(servo2, 1500);
  //pwm.writeMicroseconds(servo3, 1500);
  //pwm.writeMicroseconds(servo4, 1500);
  
  pwm.writeMicroseconds(servo5, 1500);
  pwm.writeMicroseconds(servo6, 1500);
  pwm.writeMicroseconds(servo7, 1500);
  pwm.writeMicroseconds(servo8, 1500);
  
  pwm.writeMicroseconds(servo9, 1500);
  pwm.writeMicroseconds(servo10, 1500);
  pwm.writeMicroseconds(servo11, 1500);
  pwm.writeMicroseconds(servo12, 1500);
  
  pwm.writeMicroseconds(servo13, 1500);
  pwm.writeMicroseconds(servo14, 1500);
  pwm.writeMicroseconds(servo15, 1500);
  pwm.writeMicroseconds(servo16, 1500);
  delay(3000);
  //yield();
}

void loop(){
  int time1 = -(50*hauteur1) + 1500;
  int time2 = -(50*hauteur2) + 1500;
  int time3 = -(50*hauteur3) + 1500;
  int time4 = -(50*hauteur4) + 1500;
  
  int time5 = -(50*hauteur5) + 1500;
  int time6 = -(50*hauteur6) + 1500;
  int time7 = -(50*hauteur7) + 1500;
  int time8 = -(50*hauteur8) + 1500;
  
  int time9 = -(50*hauteur9) + 1500;
  int time10 = -(50*hauteur10) + 1500;
  int time11 = -(50*hauteur11) + 1500;
  int time12 = -(50*hauteur12) + 1500;
  
  int time13 = -(50*hauteur13) + 1500;
  int time14 = -(50*hauteur14) + 1500;
  int time15 = -(50*hauteur15) + 1500;
  int time16 = -(50*hauteur16) + 1500;
  
  pwm.writeMicroseconds(servo1, time1);
  pwm.writeMicroseconds(servo2, time2);
  pwm.writeMicroseconds(servo3, time3);
  pwm.writeMicroseconds(servo4, time4);
  
  pwm.writeMicroseconds(servo5, time5);
  pwm.writeMicroseconds(servo6, time6);
  pwm.writeMicroseconds(servo7, time7);
  pwm.writeMicroseconds(servo8, time8);
  
  pwm.writeMicroseconds(servo9, time9);
  pwm.writeMicroseconds(servo10, time10);
  pwm.writeMicroseconds(servo11, time11);
  pwm.writeMicroseconds(servo12, time12);
  
  pwm.writeMicroseconds(servo13, time13);
  pwm.writeMicroseconds(servo14, time14);
  pwm.writeMicroseconds(servo15, time15);
  pwm.writeMicroseconds(servo16, time16);
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


