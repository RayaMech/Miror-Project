import serial
ser = serial.Serial('/dev/ttyUSB1',9600)

import time
file = open('valeurs.csv')
while 1:
   line = file.readline()
   if not line:
         break
   ser.write(line)
   time.sleep(3)
	
file.close