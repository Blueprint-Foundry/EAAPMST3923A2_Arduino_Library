/*
  EAAPMST3923A2.cpp
  EAAPMST3923A2 Light and Proximity Sensor Source File
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 13th, 2021
  License: BSD 3 Clause
*/

#include <Wire.h>
#include "Arduino.h"
#include "EAAPMST3923A2.h"

//init function, fills port value array with 0xFF
EAAPMST3923A2::EAAPMST3923A2()
{
}

// readByte(byte registerAddress)
//  This function reads a single byte located at the registerAddress register.
unsigned int EAAPMST3923A2::readWord(byte registerAddress)
{
  unsigned int readValue;
  unsigned int msb, lsb;
  unsigned int timeout = 1000;

  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (byte) 2);

  while ((Wire.available() < 2) && (timeout != 0))
    timeout--;

  if (timeout == 0)
  {
    Serial.println("Failed");
    return 0;
  }

  msb = (Wire.read() & 0x00FF) << 8;
  lsb = (Wire.read() & 0x00FF);
  readValue = msb | lsb;

  return readValue;
}

// readByte(byte registerAddress)
//  This function reads a single byte located at the registerAddress register.
byte EAAPMST3923A2::readByte(byte registerAddress)
{
  byte readValue;
  unsigned int timeout = 1000;

  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (byte) 1);

  while ((Wire.available() < 1) && (timeout != 0))
    timeout--;

  if (timeout == 0)
  {
    Serial.println("Failed");
    return 0;
  }

  readValue = Wire.read();

  return readValue;
}

void EAAPMST3923A2::writeByte(byte registerAddress, byte writeValue)
{
  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.write(writeValue);
  Wire.endTransmission();
}

//communication check, simply checks if chip responds with Ack and returns product ID
byte EAAPMST3923A2::begin(byte address)
{
  // Store the received parameter into member variables
  deviceAddress =  address;

  Wire.beginTransmission(address);
  if (!Wire.endTransmission()) { // default value to verify communication, a 0 means we got an ack
    if (readByte(PRODUCT_ID) == 0x21)
      return 1; //it worked, we got the correct Product ID
  }
  return 0; // something went wrong
}

// return latest als reading, 12 bit value
unsigned int EAAPMST3923A2::als()
{
  return readWord(ALS_DT1);
}

// return latest ps reading, 8 bit value
byte EAAPMST3923A2::ps()
{
  return readByte(PS_DATA);
}
