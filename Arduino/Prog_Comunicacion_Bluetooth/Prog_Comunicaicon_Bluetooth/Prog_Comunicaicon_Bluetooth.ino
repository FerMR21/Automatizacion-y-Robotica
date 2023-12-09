#include <SoftwareSerial.h>

SoftwareSerial bt(11,12);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

}

void loop() {
  if(Serial.availabe()>0)
  {
    bt.write(Serial.read());    
  }

  if(bt.available()>0)
  {
    Serial.write(bt.read());
  }

}
