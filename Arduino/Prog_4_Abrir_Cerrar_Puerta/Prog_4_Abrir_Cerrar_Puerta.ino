// Librería necesaria para la comunicación serie
#include <SoftwareSerial.h>

// Configuración del puerto serie (9600 baudios)
SoftwareSerial mySerial(10, 11); // RX, TX

// Pin del motor o servomotor
const int motorPin = 9;

// Función para abrir la puerta
void abrirPuerta() {
  // Abre la puerta
  digitalWrite(motorPin, HIGH);
}

// Función para cerrar la puerta
void cerrarPuerta() {
  // Cierra la puerta
  digitalWrite(motorPin, LOW);
}

void setup() {
 // Inicializa el puerto serie
