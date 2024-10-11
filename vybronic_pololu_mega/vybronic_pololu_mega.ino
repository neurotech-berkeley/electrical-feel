#include <DRV8835MotorShield.h>

// Create an instance of the motor shield
DRV8835MotorShield drv;

void setup() {
  // There's no need for the init() function in this library
  // Set the PWM frequency for motor 1 to 170 Hz (resonant frequency of the LRA)
  // Adjust Timer1 frequency manually:
  TCCR1B = TCCR1B & B11111000 | B00000100;  // Set Timer1 frequency to ~170 Hz
}

void loop() {
  // Set motor speed using PWM (value from -400 to 400, where 400 is 100% duty cycle)
  // Adjust the speed (duty cycle) to ensure the motor operates within safe voltage limits.
  
  // Set the speed for VG1040003D at full voltage (~2.5V)
  drv.setM1Speed(320);  // Motor 1 at 80% speed (approximately 2.5 Vac RMS)
  delay(2000);          // Run for 2 seconds

  // Set the motor to operate at a lower voltage (~1.5V)
  drv.setM1Speed(200);  // Motor 1 at 50% speed (~1.5 Vac RMS)
  delay(2000);          // Run for 2 seconds

  // Set the motor to minimum operating voltage (~0.5V)
  drv.setM1Speed(50);   // Motor 1 at 12.5% speed (~0.5 Vac RMS)
  delay(2000);          // Run for 2 seconds
xs
  // Stop the motor
  drv.setM1Speed(0);    // Stop the motor
  delay(1000);          // Wait for 1 second
}
