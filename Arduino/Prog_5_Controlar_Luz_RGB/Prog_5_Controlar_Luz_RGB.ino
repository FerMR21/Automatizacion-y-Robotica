// Librería necesaria para la comunicación serie
#include <SoftwareSerial.h>

// Configuración del puerto serie (9600 baudios)
SoftwareSerial mySerial(10, 11); // RX, TX

// Pins de la luz RGB
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Función para controlar la luz RGB
void setColor(int red, int green, int blue) {
  // Establece el color de la luz RGB
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
 // Inicializa el puerto serie
 mySerial.begin(9600);
 // Inicializa los pines de la luz RGB como salida
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}

void loop() {
 // Verifica si hay datos disponibles en el puerto serie
 if (mySerial.available() > 0) {
  // Lee el comando desde Python
  String comando = mySerial.readStringUntil('\n');
   
  // Si el comando es "rojo", establece el color de la luz en rojo
  if (comando == "rojo") {
   setColor(255, 0, 0);
  }
  // Si el comando es "verde", establece el color de la luz en verde
  else if (comando == "verde") {
   setColor(0, 255, 0);
  }
  // Si el comando es "azul", establece el color de la luz en azul
  else if (comando == "azul") {
   setColor(0, 0, 255);
  }
 }
}
