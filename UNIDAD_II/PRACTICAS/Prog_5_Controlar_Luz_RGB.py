import speech_recognition as sr
import serial

# Puerto serie del Arduino
ser = serial.Serial("/dev/ttyACM0", 9600)

# Reconocedor de voz
recognizer = sr.Recognizer()

# Funciones para establecer el color de la luz RGB
def set_color_rojo():
    # Envia el comando al Arduino
    ser.write("rojo\n")

def set_color_verde():
    # Envia el comando al Arduino
    ser.write("verde\n")

def set_color_azul():
    # Envia el comando al Arduino
    ser.write("azul\n")

# Bucle principal
while True:
    # Escucha el comando de voz
    audio = recognizer.listen()

    # Intenta reconocer el comando
    try:
        # Si el comando es "rojo", establece el color de la luz en rojo
        if recognizer.recognize_google(audio) == "rojo":
            set_color_rojo()
        # Si el comando es "verde", establece el color de la luz en verde
        elif recognizer.recognize_google(audio) == "verde":
            set_color_verde()
        # Si el comando es "azul", establece el color de la luz en azul
        elif recognizer.recognize_google(audio) == "azul":
            set_color_azul()
    except sr.UnknownValueError:
        # Si el comando no se reconoce, no hace nada
        pass
