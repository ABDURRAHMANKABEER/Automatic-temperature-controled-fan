# Day 6: Integrating Temperature Control with MOSFET and DC Fan

## Objective

Integrate the temperature sensor, Arduino control logic, MOSFET switching circuit, and DC motor to build an automatic temperature-controlled fan system.

The goal was to make the fan switch ON and OFF automatically based on the measured temperature, using hysteresis to prevent unnecessary switching.

## System Overview

The system consists of four main stages:

1. **Temperature sensing:** The TMP36 sensor measures the surrounding temperature.
2. **Signal processing:** The Arduino reads the sensor's analog output and converts it into degrees Celsius.
3. **Decision-making:** The Arduino applies hysteresis control logic to determine whether the fan should be ON or OFF.
4. **Actuation:** The Arduino controls an N-channel MOSFET, which switches the DC motor representing the fan.

### System Block Diagram

Temperature Sensor (TMP36) → Arduino Uno → Hysteresis Control Logic → MOSFET → DC Motor (Fan)

## Components Used

- Arduino Uno
- TMP36 temperature sensor
- N-channel MOSFET (NMOSFET)
- DC motor representing the fan
- 9V battery for the external motor supply
- Flyback diode for motor protection
- 10 kΩ gate pull-down resistor
- Breadboard and jumper wires
- Tinkercad Circuits for simulation

## Circuit Configuration

The temperature sensor was connected to analog pin A5 of the Arduino. The Arduino read the sensor output and used the measured temperature to control the MOSFET through digital pin D10.

The DC motor was powered by a separate 9V battery, while the Arduino continued to provide 5V for the low-voltage components.

The MOSFET acted as a low-side electronic switch, controlling the current flowing through the motor. A flyback diode was connected across the motor to provide a path for inductive current when the MOSFET switched OFF.

A common ground was established between the Arduino and the external motor power supply to provide a common voltage reference for the control signal.

**Important:** The actual motor voltage and current must be within the motor's and MOSFET's ratings. The MOSFET must also be suitable for switching fully ON with the Arduino's gate voltage.

## Control Logic: Hysteresis

The system uses two temperature thresholds:

- **Fan ON:** Temperature reaches or exceeds 30°C.
- **Fan OFF:** Temperature falls to or below 28°C.
- **Between 28°C and 30°C:** The fan maintains its previous state.

The difference between the ON and OFF thresholds is 2°C. This is known as the hysteresis band.

The control logic prevents the fan from switching repeatedly when the temperature fluctuates around 30°C.

Unlike the Day 5 simulation, where the fan state was observed through the Serial Monitor, Day 6 connects the decision logic to the MOSFET switching stage so that the motor responds to the temperature automatically.

## Arduino Code

```cpp
float readTemperature()
{
    float rawReading = analogRead(A5);
    float vIn = (rawReading / 1023.0) * 5.0;
    float temp = (vIn - 0.5) / 0.01;

    return temp;
}

const int mosfetGate = 10;

void setup()
{
    Serial.begin(9600);
    pinMode(mosfetGate, OUTPUT);
}

void loop()
{
    float temp = readTemperature();

    if (temp >= 30.0) {
        digitalWrite(mosfetGate, HIGH);
    }
    else if (temp <= 28.0) {
        digitalWrite(mosfetGate, LOW);
    }

    Serial.print("Temp:");
    Serial.println(temp);

    delay(500);
}
```

## How the Code Works

### 1. Temperature Measurement

The `readTemperature()` function reads the analog signal from pin A5.

The raw ADC reading is converted into voltage using:

`vIn = (rawReading / 1023.0) * 5.0`

The TMP36 temperature conversion is then performed using:

`temp = (vIn - 0.5) / 0.01`

The function returns the calculated temperature in degrees Celsius.

### 2. Temperature-Based Decision

The Arduino checks the measured temperature against the two thresholds.

- At 30°C or above, pin D10 is set HIGH, turning the MOSFET ON.
- At 28°C or below, pin D10 is set LOW, turning the MOSFET OFF.
- Between the two thresholds, neither condition changes the output, so the previous fan state is retained.

### 3. Motor Switching

When D10 is HIGH, the MOSFET switches ON and allows current to flow through the motor.

When D10 is LOW, the MOSFET switches OFF and interrupts the motor's current path.

### 4. Serial Monitoring

The temperature is printed to the Serial Monitor every 500 milliseconds. This makes it possible to observe temperature changes and compare them with the fan's behaviour.

## Test Results

| Test | Expected behaviour | Observed result |
|---|---|---|
| Temperature below 30°C, with the fan initially OFF | Fan remains OFF | Working |
| Temperature rises to or above 30°C | Fan turns ON | Working |
| Temperature decreases but remains above 28°C | Fan remains ON | Working |
| Temperature falls to or below 28°C | Fan turns OFF | Working |
| Temperature changes around the thresholds | Previous state is maintained within the hysteresis band | Working |
| Temperature sensor, Arduino, MOSFET, and motor operate together | Automatic temperature-based fan control | Successful in Tinkercad |

*Note: The results describe the observed simulation behaviour. Individual test readings can be added later if more detailed experimental records are required.*

## Engineering Concepts Learned

- Integration of sensors, control logic, and actuators.
- Conversion of analog sensor readings into physical temperature values.
- Hysteresis-based ON/OFF control.
- Using an Arduino output to control a MOSFET rather than powering a motor directly.
- External power supplies for loads requiring more current than a microcontroller pin can provide.
- Common grounding between control and load circuits.
- Flyback diode protection for inductive loads.
- Serial debugging and system-level testing.

## Challenges and Observations

The main task was integrating the previously tested temperature-control logic with the MOSFET and motor circuit.

The system successfully combined temperature measurement, decision-making, and motor switching in one simulation. The external 9V battery supplied the motor, while the Arduino supplied the control signal and 5V for the smaller components.

The project demonstrated how software and electronics work together to create an automatic control system.

## Project Status

**Completed:** The integrated temperature-controlled fan system was tested successfully in Tinkercad.

The temperature sensor, Arduino, hysteresis logic, MOSFET switching stage, external motor supply, and DC motor operated together as intended in the simulation.

**Not yet verified:** Physical operation using the actual hardware. The motor's voltage and current ratings, MOSFET gate-drive requirements, diode rating, and wiring should be checked before physical implementation.

## Next Steps

1. Review the complete circuit and explain the function of each component.
2. Record additional temperature readings and verify the ON/OFF thresholds.
3. Check the circuit connections and component ratings before physical implementation.
4. Improve the code by explicitly tracking the fan state if needed for clearer debugging.
5. Document the final circuit, code, test results, and lessons learned on GitHub.

## Conclusion

Day 6 successfully combined the sensing, decision-making, and actuation stages into a working automatic temperature-controlled fan simulation.

The project demonstrates a fundamental embedded control system: a sensor measures a physical quantity, a microcontroller processes the measurement and applies control logic, and an electronic switching device controls an actuator in response.

This milestone provides a foundation for future projects involving embedded systems, automation, and control engineering.