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

Servo actuator1; // create a servo object named "actuator"
//Servo actuator2;
//Servo actuator3;
//int value;
int hauteur;

void setup(){
  //pinMode(A9,INPUT);
  Serial.begin(9600);
  actuator1.attach(9); //attach the actuator to Arduino pin9
  //actuator2.attach(A8); //attach the actuator to Arduino pin6
  //actuator3.attach(A8);
  actuator1.writeMicroseconds(1900); //give the actuator a 2ms pulse to retract the arm (1000us=1ms)
  //delay(3000);
  //actuator2.writeMicroseconds(2000);
  //actuator3.writeMicroseconds(2000);
  delay(3000); //delay a few seconds to give the arm time to retract
    
}

void loop(){
   //Extend and retract the actuator arm on a 5 second interval
   
   actuator1.writeMicroseconds(1100); //1ms pulse to extend the arm 
 
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
   
   actuator1.writeMicroseconds(1900); //2ms pulse to retract the arm
   //actuator2.writeMicroseconds(2000);
   delay(3000);
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
   actuator1.writeMicroseconds(1500);
   
   delay(3000);
   exit(0);
}



