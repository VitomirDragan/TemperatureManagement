#include <dht11.h>
#include <SoftwareSerial.h>

#define dht_apin A0 // Analog Pin sensor is connected to
 
SoftwareSerial hc06(0,1);

dht11 DHT;
int x;

void setup(){
  x = 0;
  Serial.begin(38400);
}

void loop(){

    DHT.read(dht_apin);
    Serial.write(DHT.temperature); 

    delay(2000);//Wait 2 seconds before accessing sensor again.
}
