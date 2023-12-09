// Librería necesaria para la comunicación serie
#include <SoftwareSerial.h>

// Configuración del puerto serie (9600 baudios)
SoftwareSerial mySerial(10, 11); // RX, TX

// Pin del servomotor
const int servoPin = 9;

// Función para controlar el servomotor
void moverServo(int angulo) {
  // Define el ángulo del servomotor
  servo.write(angulo);
}

void setup() {
 // Inicializa el puerto serie
 mySerial.begin(9600);
 // Inicializa el pin del servomotor como salida
 pinMode(servoPin, OUTPUT);
}

void loop() {
 // Verifica si hay datos disponibles en el puerto serie
 if (mySerial.available() > 0) {
  // Lee el comando desde Python
  String comando = mySerial.readStringUntil('\n');
   
  // Si el comando es "mover", mueve el servomotor al ángulo especificado
  if (comando == "mover") {
   int angulo = mySerial.parseInt();
   moverServo(angulo);
  }
 }
}
