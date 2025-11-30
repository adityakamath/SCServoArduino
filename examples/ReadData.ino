
/**
 * @file ReadData.ino
 * @brief Arduino Example: Read data from servo registers
 *
 * Demonstrates usage of SCServo library functions for Feetech serial servos in Arduino IDE.
 *
 * Usage:
 *   - Upload to your Arduino/ESP32 board
 *   - Open Serial Monitor at 1000000 baud
 *   - Connect servos to the configured serial port
 */

#include "SCServo.h"
#include <math.h>

SMS_STS sm_st;
uint8_t ID[3] = {7, 8, 9};

void setup() {
	Serial.begin(1000000);
	while (!Serial); // Wait for Serial Monitor
	sm_st.begin(1000000, &Serial); // Use hardware serial
	Serial.println("SCServo Read Data Example");
}

void loop() {
	float Pos[3];
	float Speed[3];
	float Load[3];
	float Voltage[3];
	float Temper[3];
	float Move[3];
	float Current[3];

	for (uint8_t i = 0; i < 3; i++) {
		if (sm_st.FeedBack(ID[i]) != -1) {
			Pos[i] = sm_st.ReadPos(ID[i]) * 2 * PI / 4096.0;
			Speed[i] = sm_st.ReadSpeed(ID[i]) * 2 * PI / 4096.0;
			Load[i] = sm_st.ReadLoad(ID[i]) / 10.0;
			Move[i] = sm_st.ReadMove(ID[i]);
			Temper[i] = sm_st.ReadTemper(ID[i]);
			Voltage[i] = sm_st.ReadVoltage(ID[i]) / 10.0;
			Current[i] = sm_st.ReadCurrent(ID[i]) * 6.5;
			Serial.print("Motor="); Serial.print(ID[i]);
			Serial.print(" Pos="); Serial.print(Pos[i]); Serial.print("rad ");
			Serial.print("Speed="); Serial.print(Speed[i]); Serial.print("rad/sec ");
			Serial.print("PWM="); Serial.print(Load[i]); Serial.print("% ");
			Serial.print("Move="); Serial.print(Move[i]); Serial.print(" ");
			Serial.print("Temperature="); Serial.print(Temper[i]); Serial.print("deg ");
			Serial.print("Voltage="); Serial.print(Voltage[i]); Serial.print("V ");
			Serial.print("Current="); Serial.print(Current[i]); Serial.println("mA ");
		} else {
			Serial.print("Motor="); Serial.print(ID[i]); Serial.println(" read err");
		}
	}
	Serial.println("------------------------------------------------------");
	delay(1000);
}

