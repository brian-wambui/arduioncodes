//Rotary Encoder using interrupts
//Rotary Encoder Inputs
#define CLK 2
#define DT 3


int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDirection = "";


void setup(){
  //Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  
   //Set up a serial monitor
   Serial.begin(9600);
    //Read the initial state of CLK
    lastStateCLK = digitalRead(CLK);

    //Read theh intial state of CLK
    lastStateCLK = digitalRead(CLK);
    //Call the updateEncoder() when any high or low
    //change is seen on interrupt0(pin2) or interrupt1(pin3) 
    attachInterrupt(0, updateEncoder, CHANGE);
    attachInterrupt(1, updateEncoder, CHANGE);

}
void loop() {
  //Do some useful staff here.
}
 void updateEncoder(){ 
  //Read the current state of teh CLK.
  currentStateCLK = digitalRead(CLK);

  //If the last and first current state of CLK are different,
  //then pulse occured
  //React to only one state change to avoid double count
  if(currentStateCLK != lastStateCLK && currentStateCLK == 1){
    //If the DT state is different from the CLK state then 
    //the encoder is rotated Counter clockwise direction hence we decrement.
    if(digitalRead(DT) != currentStateCLK){
      counter --;
      currentDirection = " Counter Clockwise";
    }else{
      //Encoder is rotating on the clockwise direction.
      counter ++;
      currentDirection = "Clockwise Direction";
    }

    Serial.print("Direction: ");
    Serial.println(currentDirection);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  
 }
    //Remember the last CLK state 
    lastStateCLK = currentStateCLK;
}

  
  
   
    

      
