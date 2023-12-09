import speech_recognition as sr
import serial

# Puerto serie del Arduino
ser = serial.Serial("/dev/ttyACM0", 9600)

# Reconocedor de voz
recognizer = sr.Recognizer()

# Función para mover el servomotor
def mover_servo(angulo):
    # Envia el comando al Arduino
    ser.write("mover " + str(angulo) + "\n")

# Bucle principal
while True:
    # Escucha el comando de voz
    audio = recognizer.listen()

    # Intenta reconocer el comando
    try:
        # Si el comando es "mover", mueve el servomotor al ángulo especificado
        if recognizer.recognize_google(audio) == "mover":
            # Lee el ángulo del comando
            angulo = recognizer.recognize_google(audio).split(" ")[1]
            # Mueve el servomotor
            mover_servo(int(angulo))
    except sr.UnknownValueError:
        # Si el comando no se reconoce, no hace nada
        pass
