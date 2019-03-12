const byte ledPin_in = 3;
const byte ledPin_out = 7;
const byte interruptPin = 5;
int state = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin_in, INPUT);
  pinMode(ledPin_out, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(interruptPin, blink, RISING);
}

void loop() {
  if(state==1)
  {
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