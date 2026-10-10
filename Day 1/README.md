# Project 2: Automatic Temperature-Controlled Fan

## Day 1 — Temperature Sensor Fundamentals

### Objective

Begin developing an automatic temperature-controlled fan by learning how a temperature sensor provides information to a microcontroller.

The first stage focuses on reading a TMP36 analog temperature sensor using an Arduino Uno and observing how the sensor reading changes with temperature.

### System Overview

The planned system consists of:

1. Temperature sensor
2. Arduino microcontroller
3. Temperature-based decision logic
4. Transistor or MOSFET switching stage
5. Fan powered by an appropriate external supply

**Day 1 focuses only on the temperature sensor and Arduino.** The fan and control logic will be added in later stages.

### Components and Tools

- Arduino Uno R3
- TMP36 analog temperature sensor
- Breadboard
- Jumper wires
- Tinkercad Circuits simulator
- VS Code
- Git and GitHub

### Circuit Connections

The TMP36 was connected to the Arduino as follows, with the sensor's flat face facing forward and its legs pointing downward:

| TMP36 pin | Arduino connection |
|---|---|
| Left — supply | 5V |
| Middle — output | A0 |
| Right — ground | GND |

### Initial Arduino Code

```cpp
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int temp = analogRead(A0);
    Serial.println(temp);

    delay(500);
}
```

### How the Code Works

- `Serial.begin(9600)` starts serial communication at 9600 baud.
- `analogRead(A0)` reads the analog input voltage and returns a raw digital reading.
- `Serial.println(temp)` prints the reading to the Serial Monitor.
- `delay(500)` pauses execution for 500 milliseconds before the next reading.

**Note:** The variable `temp` currently stores the raw analog reading, not the temperature in degrees Celsius. Temperature conversion will be covered on Day 2.

### Observations

- The Serial Monitor displayed a raw reading of approximately 250 at the observed simulator setting.
- Increasing the simulated temperature increased the raw analog reading.
- Decreasing the simulated temperature decreased the raw analog reading.
- The three sensor connections were checked.

These observations indicate that the Arduino reading responds to changes in the simulated temperature.

### What I Learned

- A temperature sensor converts a physical temperature into an electrical signal.
- The Arduino reads the sensor's analog voltage and converts it into a digital number.
- The raw analog reading is not the same as temperature in degrees Celsius.
- A conversion formula is needed to obtain a meaningful temperature value.
- The Serial Monitor helps observe and debug sensor readings.

### Outstanding Work

- Convert the raw analog reading into voltage.
- Convert the voltage into degrees Celsius.
- Organize the program into small functions.
- Add automatic temperature-based fan control.
- Learn transistor/MOSFET switching and motor protection.
- Implement hysteresis to prevent rapid ON/OFF switching.

### Day 1 Status

**Completed:** Initial TMP36 circuit, analog reading, and temperature-response observation.

**Next:** Day 2 — Sensor Conversion and Embedded C/C++ Functions.
