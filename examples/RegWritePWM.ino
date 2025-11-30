s16 Pwm1[3] = {500, 500, 500};
s16 Pwm2[3] = {-500, -500, -500};

/**
 * @file RegWritePWM.ino
 * @brief Arduino Example: Register write PWM for synchronized execution
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
int16_t Pwm1[3] = {500, 500, 500};
int16_t Pwm2[3] = {-500, -500, -500};

void setup() {
  Serial.begin(1000000);
  while (!Serial); // Wait for Serial Monitor
  sm_st.begin(1000000, &Serial); // Use hardware serial
  Serial.println("SCServo RegWritePWM Example");
  for (uint8_t i = 0; i < 3; i++) {
    sm_st.Mode(ID[i], 2); // open loop wheel mode
  }
}

void loop() {
  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWritePwm(ID[i], Pwm1[i]); // ID, PWM=500 (50%, forward)
  }
  sm_st.RegWriteAction();
  Serial.println("PWM = 50%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWritePwm(ID[i], Zero[i]); // ID, PWM=0 (0%, stop)
  }
  sm_st.RegWriteAction();
  Serial.println("PWM = 0%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWritePwm(ID[i], Pwm2[i]); // ID, PWM=-500 (50%, reverse)
  }
  sm_st.RegWriteAction();
  Serial.println("PWM = -50%");
  delay(2000);

  for (uint8_t i = 0; i < 3; i++) {
    sm_st.RegWritePwm(ID[i], Zero[i]); // ID, PWM=0 (0%, stop)
  }
  sm_st.RegWriteAction();
  Serial.println("PWM = 0%");
  delay(2000);
}

