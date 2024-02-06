# MPR121 Capacitive Touch Sensor Interface

This Arduino sketch is designed to interface with the MPR121 capacitive touch sensor, focusing specifically on interacting with electrode 1. It allows users to detect touch events and read capacitance values from this electrode.

## What the Code Does

- **Detects Touch**: Identifies if electrode 1 is touched.
- **Reads Capacitance Values**: Retrieves the baseline and filtered capacitance values from electrode 1, which can be used to understand touch intensity and stability.

## Installation

### Required Libraries

- **Wire.h**: Built-in Arduino library for I2C communication.
- **Adafruit_MPR121.h**: Required for MPR121 functionality. Install via the Arduino Library Manager or [Adafruit's GitHub repository](https://github.com/adafruit/Adafruit_MPR121).

### Steps

1. Install the `Adafruit_MPR121` library in your Arduino IDE.
2. Connect the MPR121 sensor to your Arduino following the pin configuration below.
3. Upload the sketch to your Arduino board.
4. Open the Serial Monitor to view the sensor output.

## Pin Configuration

- **SDA**: Connected to GPIO 6 (Customizable based on your setup)
- **SCL**: Connected to GPIO 5 (Customizable based on your setup)

These pins are used for I2C communication with the MPR121 sensor. The sketch specifically targets electrode 1 for touch detection and data reading. This can be adjusted in the code for different electrodes.

- **VIN**: Connected to VIN (5V power output)
- **3.3V**: If not using the VIN, connect this to a 3.3V pin

## Functions

- `bool isTouched(int electrode)`: Returns `true` if the specified electrode is touched.
- `uint16_t readRawValue(int electrode)`: Retrieves the baseline data value for the specified electrode.
- `uint16_t readFilteredValue(int electrode)`: Retrieves the filtered data value for the specified electrode.

## License

This project is open-sourced under the MIT License. Feel free to use, modify, and distribute as per the license terms.
