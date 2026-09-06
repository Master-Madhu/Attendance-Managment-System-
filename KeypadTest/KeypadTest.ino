// =====================================================
//   4x4 KEYPAD RAW HARDWARE TEST - No library needed
//   Upload this sketch, open Serial Monitor at 115200
//   Press and HOLD any key - it will print which pins connect
// =====================================================

const int PINS[] = {13, 12, 14, 27, 26, 25, 33, 32};
const int PIN_COUNT = 8;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n================================");
  Serial.println("  4x4 KEYPAD RAW HARDWARE TEST");
  Serial.println("================================");
  Serial.println("Press and HOLD any key on your keypad.");
  Serial.println("We will print which pin pair activates.");
  Serial.println("================================\n");
}

void loop() {
  for (int r = 0; r < PIN_COUNT; r++) {
    // Set all pins as INPUT_PULLUP first
    for (int i = 0; i < PIN_COUNT; i++) {
      pinMode(PINS[i], INPUT_PULLUP);
    }

    // Drive this pin LOW (simulate a row scan)
    pinMode(PINS[r], OUTPUT);
    digitalWrite(PINS[r], LOW);
    delayMicroseconds(100);

    // Check all other pins for LOW
    for (int c = 0; c < PIN_COUNT; c++) {
      if (c == r) continue;
      if (digitalRead(PINS[c]) == LOW) {
        Serial.print("KEY! ROW=GPIO");
        Serial.print(PINS[r]);
        Serial.print("  COL=GPIO");
        Serial.println(PINS[c]);
        delay(300);
      }
    }
  }
}
