const PROGMEM uint8_t memory_rom[30000] = {0xFF};
      uint8_t memory_ram[2048]  = {0};


int freeRam()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int) __brkval);
}

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  Serial.println(freeRam());
}

// the loop function runs over and over again forever
void loop()
{
  for (uint32_t j = 0; j < 12; j++)
  {
    memcpy(memory_ram, memory_rom + j * 2048, 3);
  }
  
  Serial.println(freeRam());

  delay(1000);
}
