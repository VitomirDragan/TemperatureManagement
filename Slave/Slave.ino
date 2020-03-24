#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial hc05(11, 10); //Tx,Rx from the bluetooth module

const int motorA1 = 6;
const int motorA2 = 7;
const int motorB1 = 8;
const int motorB2 = 9;

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

int potPin = 0;
int x;
int desired_temperature;

void setup()
{
  Serial.begin(38400);
  hc05.begin(38400);  // baud rate for the bluetooth module
  lcd.begin(16, 2);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}

void loop()
{ 
  //Bluetooth for mobile app (Good luck, Harris!)
   // Feed any data from bluetooth to Terminal.
   /* if (hc05.available())
    Serial.write(hc05.read());*/
    
    hc05.write("Verificam transmiterea de date!");
    delay(50);

    
  //set temperature
  desired_temperature = analogRead(potPin);
  desired_temperature = map(desired_temperature, 0, 1023, 35, 15);
  lcd.setCursor(0, 0);
  lcd.print("Temp. set: ");
  lcd.print(desired_temperature);  

 //turn on/off solenoid and the pump
 if(Serial.available()) 
  {  
      x = Serial.read();

      lcd.setCursor(0, 1);
      lcd.print("Temp. cam2: ");
      lcd.print(x);
      
      if(x > desired_temperature)
      {
         digitalWrite(motorA1, HIGH); //close the solenoid
         digitalWrite(motorA2, LOW);
         digitalWrite(motorB1, LOW); //stop the pump
         digitalWrite(motorB2, LOW);
       }
       else
       {
         digitalWrite(motorA1, LOW); //open the solenoid
         digitalWrite(motorA2, LOW);
         digitalWrite(motorB1, HIGH);
         digitalWrite(motorB2, LOW); //start the pump
       }
    }
}
