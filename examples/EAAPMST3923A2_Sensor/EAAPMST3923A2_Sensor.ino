/*
  Basic demo for PI4IOE5V96248 I2C IO expander
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 13th, 2021
  License: BSD 3 Clause
  This example shows most options available on the EAAPMST3923A2 light and proximity sensor
*/
#include <Wire.h>
#include <EAAPMST3923A2.h>

EAAPMST3923A2 light_sense; // Object for communicating with the light and proximity sensor
const byte EAAPMST3923A2_ADDRESS = 0x44;  // EAAPMST3923A2 has a fixed 0x44 address

void setup() {
  Serial.begin(115200);
  Wire.begin(25, 23); //Join I2C bus, set SDA and SCL pins respectively (tested on ESP32, remove pins if using another chip)
  Wire.setClock(400000); //Set speed to 400Khz, chip supports up to 1Mhz

  delay(100); //give system chance to stabilize, likely not needed.

  // Call light_sense.begin(<address>) to initialize the EAAPMST3923A2. Successfully communication = return 1.
  // NOTE: Requires Wire.begin to already have been called.
  if (!light_sense.begin(EAAPMST3923A2_ADDRESS))
  {
    Serial.println("Failed to init EAAPMST3923A2 :(");
    while (1); //loop forever
  }
  Serial.println("EAAPMST3923A2 found! :)");
  light_sense.writeByte(CONFIGURE, 0xB4); // configure for continuous reading on both sensors, 100mA drive current
}


void loop() {
  delay(200);
  Serial.print("ALS ");
  Serial.println(light_sense.als());
  Serial.print("PS ");
  Serial.println(light_sense.ps());
}
