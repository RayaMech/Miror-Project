Python 3.8.10 (default, Sep 28 2021, 16:10:42) 
[GCC 9.3.0] on linux
Type "help", "copyright", "credits" or "license()" for more information.
>>> import serial
>>> import time
>>> ser = serial.Serial('/dev/ttyUSB0',9600)
>>> file = open('valeurs.csv')
while 1:
   line = file.readline()
   if not line:
         break
   ser.write(line)
   time.sleep(3)
	
file.close