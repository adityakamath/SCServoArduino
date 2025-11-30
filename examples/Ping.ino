
/**
 * @file Ping.ino
 * @brief Arduino Example: Ping servo to check connectivity
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
	Serial.println("SCServo Ping Example");
	int ID = sm_st.Ping(1);
	if (ID != -1) {
		Serial.print("ID: ");
		Serial.println(ID);
	} else {
		Serial.println("Ping servo ID error!");
	}
	sm_st.end();
}

void loop() {
	// No repeated actions needed
}
