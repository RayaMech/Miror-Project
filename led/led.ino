void setup(){
  Serial.begin(9600);
  pinMode(A9,OUTPUT);
}

void loop(){
  digitalWrite(A9,HIGH); 
  delay(1000);
  digitalWrite(A9,LOW);
  delay(1000);
}

/*
???
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_getsync(): timeout communicating with programmer
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_ReceiveMessage(): timeout
avrdude: stk500v2_getsync(): timeout communicating with programmer
*/
