import speech_recognition as sr
r = sr.Recognizer()

audio_file = sr.AudioFile('Audios/audio_file_3.wav')

try:
    with audio_file as source:
        audio = r.record(source)

    var = r.recognize_google(audio,language="es-MX", show_all=True)
    print("Mensaje: ")
    print(var)

except sr.UnknownValueError as e:
    print("Unknown Value Error", e)
except sr.RequestError as e:
    print("Request error: ".format(e))
except Exception as ex:
    print(ex)