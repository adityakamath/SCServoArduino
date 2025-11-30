
/**
 * @file ProgramEprom.ino
 * @brief Arduino Example: Program EEPROM parameters
 *
 * Demonstrates usage of SCServo library functions for Feetech serial servos in Arduino IDE.
 *
 * Usage:
 *   - Upload to your Arduino/ESP32 board
 *   - Open Serial Monitor at 115200 baud
 *   - Connect servos to the configured serial port
 */

#include "SCServo.h"

SMS_STS sm_st;

void setup() {
	Serial.begin(115200);
	while (!Serial); // Wait for Serial Monitor
	sm_st.begin(115200, &Serial); // Use hardware serial
	Serial.println("SCServo Program EEPROM Example");
	sm_st.unLockEprom(1); // Enable EPROM save function
	Serial.println("unLock Eprom");
	sm_st.writeByte(1, SMSBL_ID, 2); // Change ID to 2
	Serial.println("write ID: 2");
	sm_st.LockEprom(2); // Disable EPROM save function
	Serial.println("Lock Eprom");
	sm_st.end();
}

void loop() {
	// No repeated actions needed
}

