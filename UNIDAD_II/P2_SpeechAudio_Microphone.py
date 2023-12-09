import speech_recognition as sr
r = sr.Recognizer()

print("Inicia:")
with sr.Microphone() as source:
    audio = r.listen(source)


print("Registro generado!")

with open("Audios/audio_file_3.wav", "wb") as file:
    file.write(audio.get_wav_data())
print("Archivo generado!")