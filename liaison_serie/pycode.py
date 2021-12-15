Python 2.7.18 (default, Mar  8 2021, 13:02:45) 
[GCC 9.3.0] on linux2
Type "help", "copyright", "credits" or "license()" for more information.
>>> import serial
ser = serial.Serial('/dev/ttyUSB1',9600)

ser.write('110,')

import time
file = open('valeurs.csv')
while 1:
   line = file.readline()
   if not line:
         break
   ser.write(line)
   time.sleep(3)
	
file.close


Traceback (most recent call last):
  File "<pyshell#0>", line 1, in <module>
    import serial
ImportError: No module named serial
>>> 
