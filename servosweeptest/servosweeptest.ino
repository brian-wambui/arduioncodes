/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int angle = 0;    // variable to store the servo position

void setup() {
    servo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(angle);              // tell servo to go to angle in variable 'angle'
    delay(15);                       // waits 15 ms for the servo to reach the angle
  }
  for (angle = 180; angle >= 0; angle -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(angle);              // tell servo to go to angle in variable 'angle'
    delay(15);                       // waits 15 ms for the servo to reach the angle
    
  }
}
