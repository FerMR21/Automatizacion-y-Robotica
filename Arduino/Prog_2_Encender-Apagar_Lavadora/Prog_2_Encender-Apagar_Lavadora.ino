// Librería necesaria para la comunicación serie
#include <SoftwareSerial.h>

// Configuración del puerto serie (9600 baudios)
SoftwareSerial mySerial(10, 11); // RX, TX

// Pines de los LEDs
const int ledPin1 = 13;
const int ledPin2 = 12;

void setup() {
  // Inicializa el puerto serie
  mySerial.begin(9600);
  // Inicializa los pines de los LEDs como salida
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serie
  if (mySerial.available() > 0) {
    // Lee el comando desde Python
    String command = mySerial.readStringUntil('\n');
    
    // Compara el comando recibido
    if (command == "encender") {
      digitalWrite(ledPin1, HIGH); // Enciende el primer LED
      digitalWrite(ledPin2, HIGH); // Enciende el segundo LED
      mySerial.println("Lavadora encendida");
    } else if (command == "apagar") {
      digitalWrite(ledPin1, LOW); // Apaga el primer LED
      digitalWrite(ledPin2, LOW); // Apaga el segundo LED
      mySerial.println("Lavadora apagada");
    }
  }
}
