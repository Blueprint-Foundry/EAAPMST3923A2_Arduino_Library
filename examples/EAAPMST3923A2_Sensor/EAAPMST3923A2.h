/*
  EAAPMST3923A2.h
  EAAPMST3923A2 Light and Proximity Sensor Header File
  By: Ilia Baranov
  BLueprint Foundry
  Date: March 13th, 2021
  License: BSD 3 Clause
*/

//Register Definitions
#define PRODUCT_ID  0x00  //Default 0x21
#define CONFIGURE   0x01  //Default 0xBC, See Datasheet Pg 9 
#define INTERRUPT   0x02  //Default 0x8B, See Datasheet Pg 9
#define PS_LT       0x03  //Default 0x00, 8-bit interrupt low threshold for proximity
#define PS_HT       0x04  //Default 0xFF, 8-bit interrupt high threshold for proximity
#define ALS_TH1     0x05  //Default 0x00, Lower 8 bits interrupt low threshold for ALS (light)
#define ALS_TH2     0x06  //Default 0xF0, [7:4] Lower 4 bits (of 12 bits) for ALS high interrupt threshold, [3:0] Upper 4 bits (of 12 bits) for ALS low interrupt threshold
#define ALS_TH3     0x07  //Default 0xFF, Upper 8 bits (of 12 bits) for ALS high interrupt threshold
#define PS_DATA     0x08  //Default 0x00, Result of 8-bit proximity sensor ADC conversion
#define ALS_DT1     0x09  //Default 0x00, Lower 8 bits (of 12 bits) from result of ALS sensor conversion
#define ALS_DT2     0x0A  //Default 0x00, [3:0] Upper 4 bits (of 12 bits) from result of ALS sensor conversion
#define ALS_RNG     0x0B  //Default 0x00, [2:0] Lux range setting for light sensor, see Datasheet Pg 11


#include "Arduino.h"

#ifndef EAAPMST3923A2_H
#define EAAPMST3923A2_H

class EAAPMST3923A2
{
  private:  // These private functions are not available to Arduino sketches.
    byte deviceAddress; // I2C Address of PI4IOE5V96248
    byte readByte(byte registerAddress);
    unsigned readWord(byte registerAddress);

  public:  // These public functions are available to Arduino sketches.
    EAAPMST3923A2();
    byte begin(byte address = 0x44); // EAAPMST3923A2 has a hardware fixed 0x44 address, choice is offered in case of I2C translator or mux
    unsigned int als(); // return latest als reading, 12 bit value
    byte ps(); // return latest ps reading, 8 bit value
    void writeByte(byte registerAddress, byte writeValue);

}; //EAAPMST3923A2 class
#endif  // EAAPMST3923A2_H
