#include <Wire.h>
#include <Adafruit_MPRLS.h>

#define TCA_ADDR 0x70 // I2C address of TCA9548A
#define RESET_PIN  -1  // not using reset pin
#define EOC_PIN    -1  // not using EOC pin

Adafruit_MPRLS mpr = Adafruit_MPRLS(RESET_PIN, EOC_PIN);

void tcaSelect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << i);  // Select channel i
  Wire.endTransmission();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello world!");
  
  Wire.begin(21, 22);
  Serial.println("I2C Initialized.");
  
  for (int i = 5; i < 8; i++) {
    tcaSelect(i);
    if (!mpr.begin()) {
      Serial.print("Sensor on channel "); Serial.print(i); 
      Serial.println(" not found.");
    } else {
      Serial.print("Sensor on channel "); Serial.print(i); 
      Serial.println(" found.");
    }
  }
}

void loop() {
  unsigned long startTime = millis();
  for (int i = 5; i < 8; i++) {
    tcaSelect(i);
    float pressure_hPa = mpr.readPressure();
    Serial.print("C "); Serial.print(i); Serial.print(" (hPa): ");
    Serial.println(pressure_hPa);
  }
  unsigned long endTime = millis();
  Serial.println("(ms): ");
  Serial.println(startTime);
  Serial.println(endTime);
  
}
