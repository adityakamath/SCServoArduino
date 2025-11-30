
/**
 * @file Broadcast.ino
 * @brief Arduino Example: Broadcast command to all servos
 *
 * Demonstrates usage of SCServo library functions for Feetech serial servos in Arduino IDE.
 *
 * Usage:
 *   - Upload to your Arduino/ESP32 board
 *   - Open Serial Monitor at 115200 baud
 *   - Connect servos to the configured serial port
 */



#include <Arduino.h>
#include "SCServo.h"

SMS_STS sm_st;

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for Serial Monitor
  sm_st.begin(115200, &Serial); // Use hardware serial
  Serial.println("SCServo Broadcast Example");
}

void loop() {
  sm_st.WritePosEx(0xfe, 4095, 2400, 50); // Move all servos to position 4095
  Serial.println("pos = 4095");
  delay(2187); // Wait for movement

  sm_st.WritePosEx(0xfe, 0, 2400, 50); // Move all servos to position 0
  Serial.println("pos = 0");
  delay(2187); // Wait for movement
}

