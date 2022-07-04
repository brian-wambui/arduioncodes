//Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDirection = "";
unsigned long lastButtonPress = 0;

void setup(){
  //Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  
   //Set up a serial monitor
   Serial.begin(9600);
    //Read the initial state of CLK
    lastStateCLK = digitalRead(CLK);
}
void loop() {
  
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
      currentDirection = " Counter Clockwise Direction";
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
    //Read the button state
    int buttonState = digitalRead(SW);

    //If we detect a LOW signal, Bbutton is prressed 
    if(buttonState = LOW){
      //If 50 miliseconds have passed since the last LOW pulse, it means that the 
      //the button has been pressed,released and pressed again.
      if (millis() - lastButtonPress > 50){
        Serial.print("Button pressed!");
      }
      //Remember last button press event
      lastButtonPress = millis(); 
    }
    //Put as slight delay to help debounce the reading
    delay(1);
}
      



  
  
   
    

      
