const byte ledPinIn = 13; //the input of led
const byte ledPinOut = 3; //the output led
const byte interruptPin = 5;// the output of potentiometre
int state = CHANGE;
int val;
int incomingByte = 0;   // for incoming serial data

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    pinMode(ledPinIn, INPUT); // input pin of led
    pinMode(ledPinOut, OUTPUT); 
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(interruptPin, blink, RISING); //give a function to the led
}

void loop() {
  val = Serial.read();  

  switch(val){                          

  case 'I':      //keybord instruction to switch off the led            
    digitalWrite(13, HIGH); //led is on
  break;

  case 'i':         //keybord instruction to switch off the led           
    digitalWrite(13, LOW); //the led is off
  break;
 
  if(state==1){
    digitalWrite(7, HIGH); // sets the digital pin 13 on
    delay(200);            // waits for a second
    digitalWrite(7, LOW);  // sets the digital pin 13 off
    delay(200);            // waits for a second
  }
  else{
    digitalWrite(7, HIGH); //led is on
  }
 
    Serial.println(state);
  }

void blink() {
    state = !state;
}

