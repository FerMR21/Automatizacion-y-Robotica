import speech_recognition as sr
import serial

# Inicializa el reconocimiento de voz
r = sr.Recognizer()

# Configura el puerto serie para la comunicación con Arduino
ser = serial.Serial('COMX', 9600)  # Reemplaza 'COMX' con el puerto COM correcto


def recognize_speech():
    with sr.Microphone() as source:
        print("Di un comando de voz:")
        audio = r.listen(source)

    try:
        # Reconoce el comando de voz
        command = r.recognize_google(audio, language="es-MX")
        print("Comando reconocido:", command)
        return command
    except sr.UnknownValueError:
        print("No se entendió el comando")
        return None
    except sr.RequestError as e:
        print("Error en la solicitud:", e)
        return None


while True:
    # Escucha el comando de voz
    command = recognize_speech()

    if command:
        # Si el comando contiene "enciende la luz", envía "encender" a Arduino
        if "enciende la luz del cuarto" in command.lower():
            ser.write("encender\n".encode())
        # Si el comando contiene "apaga la luz", envía "apagar" a Arduino
        elif "apaga la luz" in command.lower():
            ser.write("apagar\n".encode())
        else:
            print("Comando no reconocido")
