#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor electrovalva(1);

int x, desired_temperature, pos,number;
void setup(){
  x = 0;
  pos=1;
  desired_temperature = 26;
  Serial.begin(38400);
}

void loop(){
      if(Serial.available() ) 
      {
        x = Serial.read();

        if(pos%2!=0)
        {
          number = x*10;
        }
        else
        {
          number = number+x;
        }
        Serial.write(number);

        if(pos%2==0)
        {
          //Serial.write(number);
       
          if(number > desired_temperature)
          {
              electrovalva.setSpeed(255); //inchide electrovalva
              electrovalva.run(FORWARD);      
          }
          else
          {
              electrovalva.setSpeed(0); //deschide electrovalva
              electrovalva.run(FORWARD); 
          }
           number = 0;
        }

        pos = pos+1;
    }
}
