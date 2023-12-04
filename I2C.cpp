#include "i2c.h"

void I2CStart() {
  digitalWrite(SDA_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(SCL_PIN, HIGH); 
  delayMicroseconds(5);
  digitalWrite(SDA_PIN, LOW); 
  delayMicroseconds(5); 
  digitalWrite(SCL_PIN, LOW);  
  delayMicroseconds(5);
}

void I2CStop() {
  digitalWrite(SDA_PIN, LOW);
  delayMicroseconds(5);  
  digitalWrite(SCL_PIN, HIGH); 
  delayMicroseconds(5);
  digitalWrite(SDA_PIN, HIGH); 
  delayMicroseconds(5); 
}

void I2CWriteByte(uint8_t data) {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(SDA_PIN, (data & 0x80) ? HIGH : LOW);  
    delayMicroseconds(5);
    digitalWrite(SCL_PIN, HIGH); 
    delayMicroseconds(5);
    digitalWrite(SCL_PIN, LOW); 
    delayMicroseconds(5);
    data <<= 1;  
  }
  if(digitalRead(SDA_PIN)==LOW)
    Serial.println("get ack_data");
  else
    Serial.println("Error");
  digitalWrite(SCL_PIN, HIGH); 
  delayMicroseconds(5);
  digitalWrite(SCL_PIN, LOW); 
  delayMicroseconds(5);
}

void I2CAddress(int address)
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(SDA_PIN, (address & 0x80) ? HIGH : LOW); 
    address <<= 1; 
    digitalWrite(SCL_PIN, HIGH);  
    delayMicroseconds(5);
    digitalWrite(SCL_PIN, LOW);  
    delayMicroseconds(5);
  }
  digitalWrite(SDA_PIN, LOW);  
  delayMicroseconds(5);
  digitalWrite(SCL_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(SCL_PIN, LOW);  
  delayMicroseconds(5);
  if(digitalRead(SDA_PIN)==LOW)
    Serial.println("get ack_address");
  else
    Serial.println("Error");
  digitalWrite(SCL_PIN, HIGH);  
  delayMicroseconds(5);
  digitalWrite(SCL_PIN, LOW);  
  delayMicroseconds(5);
}
