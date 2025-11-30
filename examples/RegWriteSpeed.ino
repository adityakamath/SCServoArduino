/**
 * @file RegWriteSpeed.ino
 * @brief Arduino Example: Register write speed for synchronized execution
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
int16_t Zero[3] = {0, 0, 0};
int16_t Speed1[3] = {-3400, -3400, -3400}; // forward
int16_t Speed2[3] = {3400, 3400, 3400}; // reverse
uint8_t Acc[3] = {254, 254, 254}; // 0 to 254

void setup() {
  Serial.begin(1000000);
  while (!Serial); // Wait for Serial Monitor
  sm_st.begin(1000000, &Serial); // Use hardware serial
  Serial.println("SCServo RegWriteSpeed Example");
  for (uint8_t i = 0; i < 3; i++) {
    sm_st.Mode(ID[i], 1); // closed loop wheel mode
  }
}

void loop() {
  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWriteSpe(ID[i], Speed1[i], Acc[i]); // ID, Speed=2000 steps/s, Acc=50*100 steps/s^2
  }
  sm_st.RegWriteAction();
  Serial.println("Speed = 50%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWriteSpe(ID[i], Zero[i], Acc[i]); // ID, Speed=0 steps/s, Acc=50*100 steps/s^2
  }
  sm_st.RegWriteAction();
  Serial.println("Speed = 0%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWriteSpe(ID[i], Speed2[i], Acc[i]); // ID, Speed=-2000 steps/s, Acc=50*100 steps/s^2
  }
  sm_st.RegWriteAction();
  Serial.println("Speed = -50%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWriteSpe(ID[i], Zero[i], Acc[i]); // ID, Speed=0 steps/s, Acc=50*100 steps/s^2
  }
  sm_st.RegWriteAction();
  Serial.println("Speed = 0%");
  delay(2000);
}
		std::cout<<"Speed = "<<0<<"%"<<std::endl;
		sleep(2);
	}
	sm_st.end();
	return 1;
}

