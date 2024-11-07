#include <Arduino.h>
#include <DRV8835MotorShield.h>

DRV8835MotorShield drv;

const int PWMA = 26;    // Motor 1 PWM (connect to GPIO 26)
const int PWMB = 27;    // Motor 2 PWM (connect to GPIO 27)
const int AIN1 = 14;    // Motor 1 direction control pin (connect to GPIO 14)
const int AIN2 = 12;    // Motor 1 direction control pin (connect to GPIO 12)
const int STBY = 13;    // Standby control pin (connect to GPIO 13)

// LEDC channel settings for ESP32 PWM
const int freq = 170;           // PWM frequency
const int resolution = 8;       // PWM resolution (8-bit)
const int channelA = 26;//0;         // PWM channel for Motor 1
const int channelB = 27;//1;         // PWM channel for Motor 2

void setup() {
  Serial.begin(115200);
  // Set up motor control pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  // Enable the motor driver by setting STBY HIGH
  digitalWrite(STBY, HIGH);

  // Configure LEDC channels for PWM on the ESP32
  ledcAttach(PWMA, freq, resolution);
  //ledcAttachPin(PWMA, channelA);

  ledcAttach(PWMB, freq, resolution);
  //ledcAttachPin(PWMB, channelB);
}

void loop() {
  int a = 0;
  int b = 0;
  // Set directions for Motor 1 and Motor 2
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);   // Set direction for Motor 1
  Serial.println(a);
  Serial.println(b);

  // Control Motor 1 speed at 80% duty cycle
  a = ledcWrite(channelA, 0.8 * 255); // Motor 1 at 80% speed
  delay(2000);
  Serial.println(a);
  Serial.println(b);
  // Control Motor 2 speed at 50% duty cycle
  b = ledcWrite(channelB, 0.5 * 255); // Motor 2 at 50% speed
  delay(2000);
  Serial.println(a);
  Serial.println(b);

  // Alternate Motor 1 and Motor 2 speeds
  a = ledcWrite(channelA, 0.3 * 255); // Motor 1 at 30% speed
  b = ledcWrite(channelB, 0.7 * 255); // Motor 2 at 70% speed
  delay(2000);
  Serial.println(a);
  Serial.println(b);

  // Stop both motors
  a = ledcWrite(channelA, 0);
  b = ledcWrite(channelB, 0);
  delay(1000);
  Serial.println(a);
  Serial.println(b);
}
