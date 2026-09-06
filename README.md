# ESP32 Attendance System

This project is a comprehensive ESP32-based biometric attendance system. It features fingerprint scanning, an OLED display interface, local SD card storage, Wi-Fi connectivity with a local web server for retrieving logs, and BLE capabilities for data transfer. 

## Key Features
- **Biometric Authentication:** Uses a fingerprint scanner for user enrollment and verification.
- **OLED Display:** Real-time feedback and menu system using an Adafruit SH1106G 128x64 display.
- **Keypad Input:** 4x4 matrix keypad to navigate menus and input IDs.
- **SD Card Logging:** Saves fingerprint templates and daily attendance logs in CSV format.
- **Web Server:** Connects to Wi-Fi and hosts a local webpage where you can download attendance CSV files.
- **BLE Connectivity:** Supports Nordic UART Service (NUS) to list and download files wirelessly over Bluetooth.
- **NTP Time Sync:** Automatically syncs the time to ensure logs are time-stamped correctly.

## Hardware Components & Wiring

| Component | Pin / Interface | ESP32 Pin |
|-----------|----------------|-----------|
| **OLED Display** | I2C SDA | GPIO 21 |
| | I2C SCL | GPIO 22 |
| **SD Card Module** | SPI CS | GPIO 5 |
| | SPI MOSI | GPIO 23 |
| | SPI MISO | GPIO 19 |
| | SPI SCK | GPIO 18 |
| **Fingerprint Scanner** | Serial TX | GPIO 16 (RX2) |
| | Serial RX | GPIO 17 (TX2) |
| **4x4 Keypad** | Row 1, 2, 3, 4 | GPIO 13, 12, 14, 27 |
| | Col 1, 2, 3, 4 | GPIO 26, 25, 33, 32 |
| **Bi-Color / Status LEDs**| RED LED | GPIO 15 |
| | GREEN LED | GPIO 4 |

## System Modes
1. **Enrollment Mode:** Register a new user ID (1-1000) and scan their fingerprint twice to generate a robust template.
2. **Attendance Mode:** Actively scans for fingerprints and logs verified matches to the SD card, triggering the Green LED.
3. **View Raw Template:** Output the raw hex data of a fingerprint template over the Serial Monitor.
4. **Clear Database:** Wipes all saved fingerprints from the sensor and the SD card backup.

## Python Utility
A `read_serial.py` script is included to interface with the ESP32 via serial. It automatically connects and can programmatically request fingerprint templates without needing the Arduino IDE Serial Monitor.
