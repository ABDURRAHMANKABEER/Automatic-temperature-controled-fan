## Day 5: Temperature Control with Hysteresis

### Objective
Implement temperature-based fan control using hysteresis to prevent rapid switching when the temperature fluctuates around the setpoint.

### Control Logic
The fan uses two temperature thresholds:

- **Turn ON:** When temperature reaches or exceeds 30°C.
- **Turn OFF:** When temperature falls to or below 28°C.
- **Between 28°C and 30°C:** Maintain the previous fan state.

The hysteresis band is 2°C.

### How It Works
The Arduino reads the temperature from the TMP36 sensor and converts the analog reading into degrees Celsius. It then compares the temperature with the two thresholds to determine the fan state.

The `fanOn` Boolean variable stores the current state. It must be declared outside `setup()` and `loop()` so that its value persists between loop iterations.

### Test Results

| Temperature | Expected fan state | Observed fan state |
|---|---|---|
| 22.83°C | OFF | OFF |
| 25.76°C | OFF | OFF |
| 29.18°C, initially OFF | OFF | OFF |
| 37.98°C | ON | ON |
| 40.91°C | ON | ON |
| 35.04°C | ON | ON |
| 32.11°C | ON | ON |
| 29.18°C, after turning ON | ON | ON |

### Observations
- The fan remained OFF while the temperature was below 30°C and it had not previously switched ON.
- When the temperature exceeded 30°C, the fan state changed to ON.
- As the temperature decreased below 30°C, the fan remained ON because it had not yet reached the 28°C OFF threshold.
- At approximately 29.18°C, the controller retained its previous state instead of switching unnecessarily.

### Engineering Concepts Learned
- Temperature-based decision-making.
- Boolean variables and persistent controller state.
- Hysteresis and the importance of separate ON and OFF thresholds.
- Preventing rapid switching around a setpoint.

### Status
**Completed:** Temperature reading, threshold comparison, and hysteresis logic were tested in simulation using the Serial Monitor.

**Not yet verified:** The complete temperature-control system operating with the MOSFET and fan together.

### Next Step
Integrate the temperature sensor, Arduino control logic, MOSFET switching circuit, and fan. Test the complete system and verify that the fan responds automatically to temperature changes.
