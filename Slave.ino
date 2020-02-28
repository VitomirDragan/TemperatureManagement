#include <SoftwareSerial.h>

SoftwareSerial hc06(0,1);

int x;
void setup(){
  x = 0;
  //Initialize Serial Monitor
  Serial.begin(38400);
  Serial.println("ENTER AT Commands:");
  //Initialize Bluetooth Serial Port
  hc06.begin(38400);
}

void loop(){
    if(Serial.available() ) {
      x = Serial.read();
      Serial.write(x);
  }
}
