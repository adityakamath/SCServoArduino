s16 Pwm1[3] = {500, 500, 500};
s16 Pwm2[3] = {-500, -500, -500};

/**
 * @file SyncWritePWM.ino
 * @brief Arduino Example: Synchronized PWM write to multiple servos
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
  Serial.println("SCServo SyncWritePWM Example");
  for (uint8_t i = 0; i < 3; i++) {
    sm_st.writeByte(ID[i], SMS_STS_MODE, 2); // Set open-loop mode
    delay(100);
    sm_st.EnableTorque(ID[i], 1);
    delay(100);
  }
  delay(500);
}

void loop() {
  sm_st.SyncWritePwm(ID, 3, Pwm1); // ID, PWM=500 (50%, forward)
  Serial.println("PWM = 50%");
  delay(2000);

  sm_st.SyncWritePwm(ID, 3, Zero); // ID, PWM=0 (0%, stop)
  Serial.println("PWM = 0%");
  delay(2000);

  sm_st.SyncWritePwm(ID, 3, Pwm2); // ID, PWM=-500 (50%, reverse)
  Serial.println("PWM = -50%");
  delay(2000);

  sm_st.SyncWritePwm(ID, 3, Zero); // ID, PWM=0 (0%, stop)
  Serial.println("PWM = 0%");
  delay(2000);
}

