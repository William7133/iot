// testing sketch for various DHT humidity/temperature sensors

#include "DHT.h"
#define DHTPIN 9     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // initialize data between the arduino and components
  Serial.println(F("Capteur DHT11 !")); // print the text in the bracket
  dht.begin(); //
}

void loop() {
  delay(2000); // Wait a few seconds between measurements.
  int val; // value of the humidity sensor
  pinMode(3, OUTPUT); // sets the digital pin 3 as output
  val = analogRead(0); //connect sensor to Analog 0
  Serial.print(val); //print the value to serial port
  delay(100); // waits for a second

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity(); // Read temperature as Celsius (the default)
  float t = dht.readTemperature(); // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true); // Check if any reads failed and exit early (to try again).
  
  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!")); // at least what the program will do if the sensor doesn't work
    return;
  }
  float hif = dht.computeHeatIndex(f, h); // Compute heat index in Fahrenheit (the default)
  float hic = dht.computeHeatIndex(t, h, false); // Compute heat index in Celsius (isFahreheit = false)
  Serial.print(F("Humidity: ")); //print the text in the bracket on the monitor
  Serial.print(h); // print the value of the humidity on the monitor
  Serial.print(F("%  Temperature: ")); //print the text in the bracket on the monitor
  Serial.print(t);// print the value of the temperature on the monitor
  Serial.print(F("°C ")); //print the text in the bracket on the monitor
  Serial.print(f);// print the value of the celcius value on the monitor
  Serial.print(F("°F  Heat index: ")); //print the text in the bracket on the monitor
  Serial.print(hic);// print the value of the fareinet value on the monitor
  Serial.print(F("°C ")); //print the text in the bracket on the monitor
  Serial.print(hif);// print the value of the humidity on the monitor
  Serial.println(F("°F")); //print the text in the bracket on the monitor
  
  if (h < 30 || t > 30) {   // if h < 30% or t > 30 °C blink red LED
    pinMode(3, OUTPUT);    // sets the digital pin 3 as output
    digitalWrite(3, HIGH); // sets the digital pin 3 on
    delay(200);            // waits for a second
    digitalWrite(3, LOW);  // sets the digital pin 3 off
    delay(200);            // waits for a second
    return;
  }
  else if (val > 480) {
    pinMode(3, OUTPUT);    // sets the digital pin 3 as output
    pinMode(5, OUTPUT);    // sets the digital pin 5 as output
    digitalWrite(3, HIGH); // sets the digital pin 3 on
    digitalWrite(5, HIGH); // sets the digital pin 5 on
    return;
  }
  else {
    pinMode(5, OUTPUT); // sets the digital pin 5 as output
    digitalWrite(5, HIGH); // sets the digital pin 5 on
    return;
  }
}