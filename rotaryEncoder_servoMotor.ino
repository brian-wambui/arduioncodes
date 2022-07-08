//Include the servo library
#include <Servo.h>

//Rotary Encoder inputs
#define CLK 2
#define DT 3

Servo servo;
int counter = 0;
int currentStateCLK;
int lastStateCLK;

void setup(){
  //Setup Encoder pins as input
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  //Setup the serial monitor
  Serial.begin(9600);

  //Attach the servo to pin 9
  servo.attach(9);
  servo.write(counter);

  //Rad the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}
void loop(){
  //Read the current state of CLK.
  currentStateCLK = digitalRead(CLK);
  //If the last and the current CLK are different then ,a pulse occured.
  //React to only one state to avoid double count.
if(currentStateCLK != lastStateCLK && currentStateCLK == 1){
  //If the Dt is different from the currentStateCLK the the encoder is rotating counter clockwise
  if(digitalRead(DT) != currentStateCLK){
    counter --;
    if (counter < 0);
    counter = 0;
  }
 else{
  //The encoder is rotating clockwise hence increment.
  counter ++;
  if (counter > 179);
  counter = 179;
 }
 //Move the servo
 servo.write(counter);
 Serial.print("POSITION:");
 Serial.println(counter);
 }
 //Remember the lsat CLK state
 lastStateCLK = currentStateCLK;
}
