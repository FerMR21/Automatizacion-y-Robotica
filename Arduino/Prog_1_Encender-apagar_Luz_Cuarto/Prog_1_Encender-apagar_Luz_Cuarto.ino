// Librería necesaria para la comunicación serie
#include <SoftwareSerial.h>

// Configuración del puerto serie (9600 baudios)
SoftwareSerial mySerial(10, 11); // RX, TX

// Pin del LED
const int ledPin = 13;

void setup() {
  // Inicializa el puerto serie
  mySerial.begin(9600);
  // Inicializa el pin del LED como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serie
  if (mySerial.available() > 0) {
    // Lee el comando desde Python
    String command = mySerial.readStringUntil('\n');
    
    // Compara el comando recibido
    if (command == "encender") {
      digitalWrite(ledPin, HIGH); // Enciende el LED
      mySerial.println("LED encendido");
    } else if (command == "apagar") {
      digitalWrite(ledPin, LOW); // Apaga el LED
      mySerial.println("LED apagado");
    }
  }
}
