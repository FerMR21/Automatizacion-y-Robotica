#include <SoftwareSerial.h>
SoftwareSerial BT(11,12);
String estado[5] = {
  "Avanzar",
  "Retroceder",
  "Derecha",
  "Izquierda",
  "Detener"
};

int matrizDireccion [5][4] = {
 {0, 1, 1, 0},
 {1, 0, 0, 1},
 {0, 1, 0, 1},
 {1, 0, 1, 0},
 {0, 0, 0, 0}  
};

int matrizVelocidad [5][2] = {
 {255, 255},
 {255, 255},
 {255, 127},
 {127, 255},
 {0, 0}  
};

int inputs[4] = {2,3,4,5}; //int1, int2, int3....
int enables[2] = {9,6}; //pines para pwm
int i,j;
int command;

 void setDireccion(int estado)
 {
    for( i = 0; i<4; i++)
    {
      digitalWrite
      (inputs[i],matrizDireccion[estado][i]);
      Serial.print(String
      (matrizDireccion[estado][i]) + " ");
    }
    Serial.print(" -- ");
    for( i = 0; i<2; i++)
    {
      analogWrite(enables[i],matrizVelocidad[estado][i]);
      Serial.print(String
      (matrizVelocidad[estado][i])+ " ");
    }
    Serial.println();
 }

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  BT.begin(9600);

  for(int i = 0 ; i < 4 ; i++)
  {
    pinMode(inputs[i], OUTPUT);    
  }

}

void loop() {
 if (Serial.available() > 0) {
    int val = Serial.readString().toInt();
    setDireccion(val);
    Serial.println("Estado aplicado: " + estado[val]);
    BT.write(val);
  }

  if (BT.available() > 0) {
    command = BT.read() - 48; // Restar 48 para convertir el carácter numérico a un entero

    Serial.println("Estado aplicado: " + estado[command]);
    setDireccion(command);
    }
  }





