/*
#define SER 9

void setup(){
  Serial.begin(9600);
  pinMode(SER,OUTPUT);
}

void loop(){
  digitalWrite(SER,HIGH);
  Serial.println("SERVO DEBOUT");
  delay(2000);
  digitalWrite(SER,LOW);
  Serial.println("SERVO ASSIS");
  delay(2000);
}




//Déclaration des constantes
#define UPDATE_TIME 20
//Déclaration des paramètres
int servoPin = 9;
int pulse = 1500;
void setup() {
// Code d'initialisation
pinMode(servoPin,OUTPUT);
Serial.begin(9600);
}
void loop() {
// Code principal
digitalWrite(servoPin,HIGH);
delayMicroseconds(pulse);
digitalWrite(servoPin,LOW);
delay(UPDATE_TIME);
}

*/
// /*


#include <Servo.h>

Servo actuator13;
Servo actuator14;
Servo actuator15;
Servo actuator16;// create a servo object named "actuator"
//Servo actuator2;
//Servo actuator3;
//int value;
#define hauteur13 +5
#define hauteur14 +5
#define hauteur15 +5
#define hauteur16 +5

int time13;
int time14;
int time15;
int time16;

void setup(){
  //pinMode(A9,INPUT);
 // Serial.begin(9600);
  actuator13.attach(A6);
  actuator14.attach(A7);
  actuator15.attach(A8);
  actuator16.attach(A9);//attach the actuator to Arduino pin9
  //actuator2.attach(A8); //attach the actuator to Arduino pin6
  //actuator3.attach(A8);
  
   int time13 = -(50*hauteur13) + 1500;
  int time14 = -(50*hauteur14) + 1500;
  int time15 = -(50*hauteur15) + 1500;
  int time16 = -(50*hauteur16) + 1500;
  
  actuator13.writeMicroseconds(1500); //give the actuator a 2ms pulse to retract the arm (1000us=1ms)
  actuator14.writeMicroseconds(1500);//delay(3000);
  actuator15.writeMicroseconds(1500);//actuator2.writeMicroseconds(2000);
  actuator16.writeMicroseconds(1500); //actuator3.writeMicroseconds(2000);
  delay(3000); //delay a few seconds to give the arm time to retract
    
}

void loop(){
   //Extend and retract the actuator arm on a 5 second interval
   
   actuator13.writeMicroseconds(time13);
   actuator14.writeMicroseconds(time14);
   actuator15.writeMicroseconds(time15);
   actuator16.writeMicroseconds(time16);
   
   actuator13.writeMicroseconds(1100);
   actuator14.writeMicroseconds(1100);
   actuator15.writeMicroseconds(1100);
   actuator16.writeMicroseconds(1100); //1ms pulse to extend the arm 
 
   //int value1=actuator1.read();
   //Serial.println(value1);
   //delay(10000);
   //actuator2.writeMicroseconds(1000);
   //delay(6000);
   //actuator3.writeMicroseconds(1000);
   //Serial.println("SERVO DEBOUT");
   //Serial.println(value1);
   
   //delay(2000);
   //int valeur1 = analogRead(A9);  // lecture du port analogique A0
   //int valeur2 = analogRead(A8);
   //Serial.println(valeur1);      // affichage de la valeur via le port série
   //Serial.println("SERVO1 DEBOUT");
   //Serial.println(valeur2);      // affichage de la valeur via le port série
   //Serial.println("SERVO2 DEBOUT");
   
   delay(3000); // the actuator takes>2s to extend/retract when loaded - give it plenty of time
  // exit(0);
   
   //actuator1.writeMicroseconds(2000); //2ms pulse to retract the arm
   //actuator2.writeMicroseconds(2000);
   //delay(2000);
   //Serial.println(valeur1);      // affichage de la valeur via le port série
   //Serial.println("SERVO1 ASSIS");
   //Serial.println(valeur2);      // affichage de la valeur via le port série
   //Serial.println("SERVO2 ASSIS");
   
   //int value2=actuator1.read();
   //Serial.println(value2);
   //delay(10000);
   
  // Serial.println("SERVO ASSIS");
   //Serial.println(value2);
   //delay(6000);
   //actuator3.writeMicroseconds(2000);
   
   //delay(3000);
}


