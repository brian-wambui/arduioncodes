void setup() {
  // initializing the digital pin LED_BUILTIN as an output 
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   //Turn on the LED
  delay(100);                      //wait for a 1000 milisecond
  digitalWrite(LED_BUILTIN, LOW);   //Turn of the LED
  delay(100);                      //wait for a 1000 milisecond
                                        
}
