import speech_recognition as sr
r = sr.Recognizer()

print("Inicia:")
with sr.Microphone() as source:
    audio = r.listen(source)


print("Registro generado!")

try:
    cadena = r.recognize_google(audio, language="es-MX")
    print("Mensaje: " + cadena)
except sr.UnknownValueError:
    print("Unknown Value Error")
except sr.RequestError as e:
    print("Request error: ".format(e))
except Exception as ex:
    print("Error: ".format(ex))