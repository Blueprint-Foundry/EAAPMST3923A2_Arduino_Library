# EAAPMST3923A2_Arduino_Library
Arduino library for EAAPMST3923A2 I2C light and proximity sensor
The library is fairly basic, exclusively using the Wire library. 

## Notes
* This light and proximity sensor has a 0x44 fixed I2C address. If multiple sensors need to be used, an I2C mux or translator is needed.

## Installation:
Download the .zip file from Github, in Arduino go to Sketch -> Include Library -> Add .ZIP Library... and select the downloaded .zip file.  
The library example can then be opened under File -> Examples -> EAAPMST3923A2 Sensor 

Software is licensed under BSD 3 Clause: https://opensource.org/licenses/BSD-3-Clause   
Documentation is licensed under Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0): https://creativecommons.org/licenses/by-sa/2.0/   
All rights reserved by Blueprint Foundry.
