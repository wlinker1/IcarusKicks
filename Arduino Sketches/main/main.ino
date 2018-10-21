/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int speakPin = 6;
Servo blade;

int pos = 0;

void setup() {
  blade.attach(9);
}

void loop() {
    servoSweep(0,120);
}

void servoSweep(int min, int max){
  for (pos = min; pos <= max; pos += 1){
    // in steps of 1 degree
    blade.write(pos);
    delay(2);
  }
  for (pos = max; pos >= min; pos -= 1) {
    blade.write(pos);
    delay(5);
  }
}

