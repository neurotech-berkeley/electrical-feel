import serial
import csv
import time

# Adjust the serial port and baud rate to match your Arduino settings
serial_port = '/dev/cu.usbserial-0001'  # Change this to the correct port
baud_rate = 115200

try:
    # Initialize serial connection
    ser = serial.Serial(serial_port, baud_rate, timeout=1)
    time.sleep(2)  # Give some time for the serial connection to establish

    # Open the CSV file for writing
    with open('pressure_data.csv', mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Timestamp", "Channel", "Pressure_hPa"])  # Write header

        while True:
            try:
                # Read a line from the serial port
                line = ser.readline().decode('utf-8').strip()
                
                if line:
                    # Split the line into components
                    data = line.split(',')
                    if len(data) == 3:
                        timestamp, channel, pressure_hPa = data
                        writer.writerow([timestamp, channel, pressure_hPa])
                        print(f"Timestamp: {timestamp}, Channel: {channel}, Pressure: {pressure_hPa}")
                        
            except KeyboardInterrupt:
                print("Terminating the script.")
                break
            except Exception as e:
                print(f"Error: {e}")

except serial.serialutil.SerialException as e:
    print(f"Error opening serial port: {e}")

finally:
    # Close the serial connection
    if 'ser' in locals() and ser.is_open:
        ser.close()
