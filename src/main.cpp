// I Philip Pateman, 000778803 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else.

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  // configure the USB serial monitor 
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
  double voltage;
  String temp = "Cold!";
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  voltage = map(iVal, 9.0, 1023.0, 0.0, 5000); 
  voltage = voltage / 100;
  if(voltage < 10){
    temp = "Cold!";
  }
  else if(voltage < 15){
    temp = "Cool";
  }
  else if(voltage < 25){
    temp = "Perfect";
  }
  else if(voltage < 30){
    temp = "Warm";
  }
  else if(voltage < 35){
    temp = "Hot";
  }
  else{
    temp = "Too Hot!";
  }
  // print value to the USB port 
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + voltage + " C which is " + temp); 
 
  // wait 0.5 seconds (500 ms) 
  delay(2000);
}