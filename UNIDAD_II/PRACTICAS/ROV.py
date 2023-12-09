import serial
import time as s

arduino = serial.Serial("COM4", baudrate=9600, timeout=1)

while True:
    cadena = input("Ingresa la cadena: ")

    arduino.write(cadena.encode())
    print(cadena)