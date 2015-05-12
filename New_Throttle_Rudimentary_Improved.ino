#include <Servo.h>

Servo myservo;
int pos = 90;
int desV = 0;
int desV1 = 4;
int desV2 = 2;
int del = 100;
int time;
int time1 = 5000;
int time2 = 10000;
int endtime = 15000;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(5);
}

void loop() {
  time = millis(); //define time in ms
   if (time < time1) {
     desV = desV1;
   }
   else {
     desV = desV2;
   }
   int sensorValue = analogRead(A0); //read pin from pot
   float involtage = sensorValue * (5.0 / 1023.0); //convert to usable voltage
   Serial.println(involtage); //print involtage value
    if (involtage < desV) {
      ++pos; //increment position
      myservo.write(pos);
    }
    else {
      --pos; //decrement position
      myservo.write(pos);
    }
   delay(del);
 }
