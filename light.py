import serial
from time import sleep

ser = serial.Serial('/dev/ttyACM0', 9600)
ser.write(b"\x30")
sleep(1)
ser.write(b"\x31")
sleep(1)
