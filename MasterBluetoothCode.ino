#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
boolean DEBUG = true;
void setup()
{
 pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
 digitalWrite(9, HIGH);
 Serial.begin(9600);

 Serial.println("Enter AT commands:");
 BTSerial.begin(38400);  // HC-05 default speed in AT command more
}

void loop()
{

 // Keep reading from HC-05 and send to Arduino Serial Monitor
 if (BTSerial.available())
   Serial.write(BTSerial.read());
   BTSerial.print("prendido");
    if (DEBUG) {Serial.println("LEDON command sent");}    
    delay (3000);
 
    BTSerial.print("apagado");
    if (DEBUG) {Serial.println("LEDOFF command sent");}      
    delay (1000);
   

 // Keep reading from Arduino Serial Monitor and send to HC-05
 if (Serial.available())
   BTSerial.write(Serial.read());
}
