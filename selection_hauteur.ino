/*
MAX=1000us
MIN=2000us

1000 us = +10.0 mm
1100 us = +8.00 mm
1200 us = +6.00 mm
1300 us = +4.00 mm
1400 us = +2.00 mm
1500 us =  0.00 mm
1600 us = -2.00 mm
1700 us = -4.00 mm
1800 us = -6.00 mm
1900 us = -8.00 mm
2000 us = -10.0 mm

f(X) = -(50*X) + 1500
X   : en millimetre (mm)
f(X): en microsecondes (us)

X = (1500 - Y)/50

Pour Y=
1000 : X = (1500-1000)/50 = +10.0 mm
1001 : X = (1500-1001)/50 = +9.98 mm
1002 : X = (1500-1002)/50 = +9.96 mm
...
1134 : X = (1500-1134)/50 = +7.32 mm
1135 : X = (1500-1135)/50 = +7.30 mm
...
1199 : X = (1500-1199)/50 = +6.02 mm
1200 : X = (1500-1200)/50 = +6.00 mm
...
1799 : X = (1500-1799)/50 = -4.02 mm
1800 : X = (1500-1800)/50 = -4.00 mm
1801 : X = (1500-1801)/50 = -3.98 mm
*/

#include <Servo.h>

Servo actuator;
#define hauteur +4.5874
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
void setup(){
  actuator.attach(A8);
  actuator.writeMicroseconds(1500.45789);
  delay(3000);
}

void loop(){
  int time = -(50*hauteur) + 1500;
  actuator.writeMicroseconds(time);
  delay(3000);
  exit(0);
}

