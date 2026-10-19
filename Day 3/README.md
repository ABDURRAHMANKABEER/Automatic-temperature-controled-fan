## Day 3: Transistor/MOSFET as a Switch

### Objective
Understand how an N-channel MOSFET acts as an electronic switch controlled by an Arduino, and use it to switch a load ON and OFF.

### Components Used
- Arduino Uno
- N-channel MOSFET (NMOSFET)
- LED
- 330-ohm resistor
- 10 kΩ gate pull-down resistor
- DC motor (representing the fan)
- Diode for motor protection
- Tinkercad Circuits

### 1. Why a MOSFET Is Needed

An Arduino output pin provides a control signal, but it should not be used to power a motor directly.

A MOSFET acts as an electronically controlled switch. The Arduino controls the MOSFET through its gate, while the MOSFET controls the current flowing through the load.

The basic arrangement is:

Arduino output → MOSFET gate → Switching action

Power supply → Load → MOSFET → Ground

### 2. MOSFET Terminals

The N-channel MOSFET has three main terminals:

- Gate (G): Receives the control signal from the Arduino.
- Drain (D): Connects to the load's switched-current path.
- Source (S): Connects to ground in the low-side switching arrangement.

When the gate-to-source voltage is sufficient, the MOSFET conducts and allows load current to flow.

When the MOSFET switches OFF, the load-current path is interrupted.

### 3. LED Switching Test

The first test used an LED as a simple load.

The Arduino was programmed to set digital pin D9 HIGH for two seconds and LOW for two seconds.

The LED switched ON for two seconds and OFF for two seconds repeatedly.

**Result:** Successful.

This confirmed that the Arduino control signal could operate the MOSFET as a switch in the simulation.

### 4. DC Motor Switching Test

After the LED test, the LED was replaced with a DC motor representing the fan.

The motor was connected through the MOSFET switching stage. A diode was connected across the motor to provide a path for inductive current when the MOSFET switches OFF.

The Arduino continued to control the MOSFET through digital pin D9.

**Observed behaviour:**
- The motor ran when the Arduino output was HIGH.
- The motor stopped receiving power when the output was LOW.
- The ON/OFF cycle repeated automatically.

**Result:** Successful in Tinkercad.

### 5. Arduino Code

```cpp
const int mosfetGate = 9;

void setup()
{
    pinMode(mosfetGate, OUTPUT);
}

void loop()
{
    digitalWrite(mosfetGate, HIGH);
    delay(2000);

    digitalWrite(mosfetGate, LOW);
    delay(2000);
}