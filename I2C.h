#ifndef I2C_HELPER_H
#define I2C_HELPER_H

#include <Arduino.h>

#define SDA_PIN A4 
#define SCL_PIN A5  
#define I2C_ADDRESS 3 

void i2cStart();
void i2cStop();
void i2cWriteByte(uint8_t data);
void i2caddress(int address);

#endif