import speech_recognition as sr
import serial

# Puerto serie del Arduino
ser = serial.Serial("/dev/ttyACM0", 9600)

# Reconocedor de voz
recognizer = sr.Recognizer()

# Funciones para abrir y cerrar la puerta
def abrir_puerta():
    # Envia el comando al Arduino
    ser.write("abrir\n")

def cerrar_puerta():
    # Envia el comando al Arduino
    ser.write("cerrar\n")

# Bucle principal
while True:
    # Escucha el comando de voz
    audio = recognizer.listen()

    # Intenta reconocer el comando
    try:
        # Si el comando es "abrir", abre la puerta
        if recognizer.recognize_google(audio) == "abrir":
            abrir_puerta()
        # Si el comando es "cerrar", cierra la puerta
        elif recognizer.recognize_google(audio) == "cerrar":
            cerrar_puerta()
    except sr.UnknownValueError:
        # Si el comando no se reconoce, no hace nada
        pass