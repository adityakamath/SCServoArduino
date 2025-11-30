
/**
 * @file Calibration.ino
 * @brief Arduino Example: Midpoint calibration utility
 *
 * Demonstrates usage of SCServo library functions for Feetech serial servos in Arduino IDE.
 *
 * Usage:
 *   - Upload to your Arduino/ESP32 board
 *   - Open Serial Monitor at 1000000 baud
 *   - Connect servos to the configured serial port
 */

#include "SCServo.h"

SMS_STS sm_st;
uint8_t ID[3] = {7, 8, 9};

void setup() {
    Serial.begin(1000000);
    while (!Serial); // Wait for Serial Monitor
    sm_st.begin(1000000, &Serial); // Use hardware serial
    Serial.println("SCServo Calibration Example");
    for (uint8_t i = 0; i < 3; i++) {
        sm_st.Mode(ID[i], 0); // set to servo mode
        sm_st.CalibrationOfs(ID[i]); // set starting position as midpoint: 2048 (=Pi radians)
    }
    Serial.println("Calibration complete!");
}

void loop() {
    // No repeated actions needed
}

