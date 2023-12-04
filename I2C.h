#ifndef I2C_HELPER_H
#define I2C_HELPER_H

#include <Arduino.h>

#define SDA_PIN A4 
#define SCL_PIN A5  
#define I2C_ADDRESS 3 

void I2CStart();
void I2CStop();
void I2CWriteByte(uint8_t data);
void I2CAddress(int address);

#endif
