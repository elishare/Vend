import serial
import time
import sys

ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(2)
ser.write(str(sys.argv[1]))
time.sleep(3)

serial_line=ser.read(ser.inWaiting())
print serial_line
