const byte ledPinIn = 13; //the input of led
const byte ledPinOut = 3; //the output led
const byte interruptPin = 5;// the output of potentiometre
int state = CHANGE;
int incomingByte = 0;   // for incoming serial data

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    pinMode(ledPinIn, INPUT);
    pinMode(ledPinOut, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(interruptPin, blink, RISING);
}

void loop() {
  if(state==1){
    digitalWrite(7, HIGH); // sets the digital pin 13 on
    delay(200);            // waits for a second
    digitalWrite(7, LOW);  // sets the digital pin 13 off
    delay(200);            // waits for a second
  }
 else{
    digitalWrite(7, HIGH);
 }
 
    Serial.println(state);
}

void blink() {
    state = !state;
}


