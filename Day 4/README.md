## Day 4: Power Architecture and Flyback Protection

### Objective

Understand the separation between controller power and load power, the purpose of a common ground in a low-side MOSFET switching circuit, and the role of a flyback diode in protecting the switching device.

### 1. Controller Power vs. Load Power

The Arduino provides the control signal to the MOSFET gate, while the motor receives operating current from its power supply through the load-current path.

The two functions are distinct:

- **Controller side:** Arduino digital output controls the MOSFET gate.
- **Load side:** The power supply provides current to the fan through the MOSFET switching stage.

The Arduino I/O pin is not intended to supply the fan's operating current directly.

### 2. Common Ground

In a typical non-isolated, low-side N-channel MOSFET circuit, the Arduino ground, external supply negative terminal, and MOSFET source share a common reference point.

The MOSFET responds to the gate-to-source voltage:

`VGS = VG - VS`

Connecting the grounds establishes the reference needed for the Arduino's control signal to produce the intended gate-to-source voltage.

The common-ground connection is a reference connection; it does not mean the Arduino supplies the fan's load current.

### 3. External Power Supply Selection

The external supply must match the fan's rated voltage and provide sufficient current for normal operation and startup.

Before constructing the physical circuit, the following parameters must be checked:

- Fan rated voltage.
- Fan operating and startup current, where available.
- Power supply output voltage and current capacity.
- MOSFET voltage and current ratings.
- MOSFET gate-drive requirements.
- Wire, connector, and diode ratings.

### 4. Basic Power Calculation

Electrical input power for a DC load can be estimated using:

`P = V × I`

For an example fan rated at 12 V and drawing 0.2 A:

`P = 12 × 0.2 = 2.4 W`

The calculated nominal electrical input power is 2.4 W. The power supply must also have suitable current capacity for startup and operating conditions.

### 5. Flyback Diode Protection

An inductive load stores energy in its magnetic field. When the current through the winding is interrupted, the inductor generates a voltage that opposes the sudden change in current.

A suitably rated flyback diode connected across a conventional brushed DC motor provides a path for the inductive current when the MOSFET switches off. This limits the voltage spike and helps protect the MOSFET.

For the low-side switching arrangement:

- Diode cathode (striped end) connects to the motor positive terminal.
- Diode anode connects to the motor negative terminal, on the MOSFET drain side.

The diode must be selected according to the load and circuit requirements. Some brushless fans with internal electronics may require a different protection arrangement.

### 6. Simulation and Testing

The MOSFET switching stage and DC motor were previously tested in Tinkercad. The motor switched ON and OFF under Arduino control.

However, the available simulated motor did not allow a realistic test of the intended larger fan and its external power requirements.

Therefore, the complete external-supply and common-ground arrangement has not yet been physically verified.

### 7. Day 4 Outcome

- Reviewed the separation between controller and load power.
- Understood the common-ground requirement for a typical low-side MOSFET circuit.
- Reviewed the relationship between supply voltage, load current, and electrical power.
- Understood the role of the flyback diode in providing a path for inductive current and limiting turn-off voltage spikes.
- Identified the component ratings and physical tests required before building the complete circuit.

### 8. Outstanding Physical Verification

When the physical kit is available:

1. Identify the actual motor or fan voltage and current ratings.
2. Confirm the MOSFET pinout and suitability for the Arduino's gate voltage.
3. Verify the external supply and current capacity.
4. Check the common-ground wiring.
5. Verify the flyback diode's type, orientation, and ratings.
6. Test the switching circuit with the appropriate supply and load.
7. Observe switching behaviour and check for unexpected heating or unreliable operation.

### Next Steps

Proceed to temperature-based control after the power and protection arrangement has been reviewed. Complete physical verification of the full power stage when the required motor and power supply are available.

**Git commit message:**
`Day 4: Document power architecture and flyback protection`