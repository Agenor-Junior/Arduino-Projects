# Arduino Project: Screw Threading Machine Control with LCD and Keypad

This project uses an Arduino to control motors and solenoids, display messages on an LCD, and receive inputs from a keypad. The code is modular and easy to customize for industrial applications, home automation, or other microcontroller-based systems. This system was used in an accessory industry for power pole fittings. For real-world applications, do not forget to use passive filters or RFI filters.

## Features
- **Relay Control**: Switches 4 relays on/off using keypad inputs.
- **LED Indicators**: Each relay has a corresponding LED to indicate its state (on/off).
- **LCD Display**: Displays system messages and interactions.
- **Alarm Monitoring**: Monitors digital inputs for alarms and activates an alarm LED when necessary.
- **Analog Input**: Uses analog pins to measure the state of a current sensor.
- **Debugging**: Optional debugging function via Serial Monitor to facilitate diagnostics.

## Technologies Used
- Microcontroller programming: Arduino IDE

## Required Components
### Hardware:
- Arduino (any compatible model, such as Uno or Mega)
- 16x2 LCD Display
- 4x4 Keypad
- Relays (4 units)
- LEDs for state indication
- Resistors (if necessary for LEDs)
- Jumper wires and breadboard
- Power supplies

### Arduino Libraries:
- `LiquidCrystal` (included with Arduino IDE)
- `Keypad`

## System Configuration
### Pins
#### LCD:
- RS: 12
- EN: 11
- D4-D7: 5, 4, 3, 2

#### Keypad:
- Rows: 5, 4, 3, 2
- Columns: 9, 8, 7, 6

#### Relays and LEDs:
- Relays: 14, 15, 16, 17
- LEDs: 31, 33, 35, 37

#### Modes:
- LEDs: 39, 41, 43

#### Alarms:
- Digital inputs: 22, 24, 26, 28
- Alarm LED: 45

#### Analog Inputs:
- Opening Sensor: A0
- Closing Sensor: A1

## How to Use
### Circuit Assembly:
- Connect all components as per the pin configuration listed above.

### Functions:
1. `initializeHardware()`: Configures pins, LCD, and initial states.
2. `displayMessage()`: Updates messages on the LCD.
3. `controlRelays()`: Switches relays and their corresponding LEDs.
4. `checkKeypadInput()`: Interprets keypad inputs.
5. `handleAlarms()`: Monitors alarm inputs and updates the alarm LED.
6. `debug()`: Displays debugging messages in the Serial Monitor.

### Optional Improvements:
- Add support for more relays or sensors.
- Implement control via serial communication or Bluetooth.
- Incorporate relay timing monitoring.

## License
This project is free for personal or educational use. For commercial use, please contact the author
