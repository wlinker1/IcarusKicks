/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
int state = 0;
int switchPin = 2;
int speakPin = 4;
Servo blade;

int pos = 0;

void setup() {
  pinMode(switchPin, INPUT);
  blade.attach(9);
}

void loop() {
  state = digitalRead(switchPin);
  servoSweep(0, 100);
}

void servoSweep(int min, int max){
  tone(speakPin, random(300,2000), 500);
  for (pos = min; pos <= max; pos += 1){
    // in steps of 1 degree
    blade.write(pos);
    delay(2);
  }
  tone(speakPin, random(300,2000), 500);
  for (pos = max; pos >= min; pos -= 1) {
    blade.write(pos);
    delay(5);
  }
}

