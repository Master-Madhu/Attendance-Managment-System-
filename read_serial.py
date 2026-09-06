import serial
import time

try:
    print("Opening serial port COM5...")
    ser = serial.Serial('COM5', 115200, timeout=1)
    
    print("--- SENDING COMMANDS TO ESP32 ---")
    
    # Send '3' to select Option 3
    print("Selecting Option 3 (View Template)...")
    ser.write(b"3\n")
    time.sleep(1)
    
    # Send '1' to select ID 1
    print("Requesting Template for ID #1...")
    ser.write(b"1\n")
    
    print("\n--- RECEIVING DATA ---")
    
    start_time = time.time()
    while time.time() - start_time < 5:
        if ser.in_waiting > 0:
            raw_data = ser.read(ser.in_waiting)
            try:
                print(raw_data.decode('utf-8', errors='ignore'), end='')
            except Exception:
                pass
        time.sleep(0.1)
        
    ser.close()
    print("\n--- FINISHED ---")
except Exception as e:
    print(f"Failed to connect: {e}\n(Make sure the Arduino IDE Serial Monitor is CLOSED!)")
