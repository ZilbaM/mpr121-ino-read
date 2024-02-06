#include <Wire.h>
#include <Adafruit_MPR121.h>

// Create an instance of the Adafruit_MPR121 class
Adafruit_MPR121 cap = Adafruit_MPR121();

// I2C Pins
#define SDA_PIN 6
#define SCL_PIN 5

void setup() {
  Serial.begin(115200);

  // Initialize I2C communication
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize communication with the MPR121
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  // Check and print data for electrode 1
  int electrode = 1;
  if (isTouched(electrode)) {
    Serial.print("Electrode ");
    Serial.print(electrode);
    Serial.println(" is touched");
  }
  
  Serial.print("Raw value for electrode ");
  Serial.print(electrode);
  Serial.print(": ");
  Serial.println(readRawValue(electrode));
  
  Serial.print("Filtered value for electrode ");
  Serial.print(electrode);
  Serial.print(": ");
  Serial.println(readFilteredValue(electrode));

  delay(1000); // Delay for readability
}

// Function to check if a specific electrode is touched
bool isTouched(int electrode) {
  uint16_t touched = cap.touched();
  return touched & (1 << electrode);
}

// Function to read raw data value from a specific electrode
uint16_t readRawValue(int electrode) {
  return cap.baselineData(electrode);
}

// Function to read filtered data value from a specific electrode
uint16_t readFilteredValue(int electrode) {
  return cap.filteredData(electrode);
}
