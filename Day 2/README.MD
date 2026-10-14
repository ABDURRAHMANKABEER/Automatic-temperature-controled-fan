## Day 2: Temperature Conversion and Functions

### Objective
Convert the TMP36 sensor's raw analog reading into voltage and temperature in degrees Celsius, then organise the code using a reusable function.

### What I Learned
- `analogRead(A0)` reads the analog voltage from the temperature sensor and converts it into a digital value between 0 and 1023 on the Arduino Uno.
- The raw ADC reading can be converted into voltage using the assumed 5 V reference.
- The TMP36 converts temperature changes into corresponding voltage changes.
- Temperature in Celsius can be calculated from the sensor voltage using the TMP36 conversion formula.
- A C++ function can perform a specific task and return its result to the part of the program that called it.
- Separating sensor calculations from the main `loop()` makes the program easier to read and maintain.

### Temperature Conversion Process

The program follows these steps:

1. Read the raw ADC value from analog pin A0.
2. Convert the ADC value into voltage.
3. Convert the voltage into temperature in degrees Celsius.
4. Return the calculated temperature from `readTemperature()`.
5. Display the temperature through the Serial Monitor every 500 milliseconds.

### Code

```cpp
float readTemperature()
{
    float rawReading = analogRead(A0);
    float vIn = (rawReading / 1023.0) * 5.0;
    float temp = (vIn - 0.5) / 0.01;

    return temp;
}

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    float temp = readTemperature();

    Serial.print("Temp:");
    Serial.println(temp);

    delay(500);
}
```

### Function Explanation

The `readTemperature()` function reads the sensor, performs the voltage and temperature conversions, and returns the calculated temperature.

The `loop()` function calls `readTemperature()`, displays the returned value, and repeats the process.

This separates the sensor-processing task from the program's main execution loop.

### Testing and Observations

During testing, the displayed temperature fluctuated unexpectedly. Further inspection revealed that accidentally pressing `Ctrl + Z` in Tinkercad had disconnected some circuit wires.

The unexpected readings were therefore associated with the circuit being unintentionally altered. The circuit connections needed to be restored before reliable temperature readings could be confirmed.

### Day 2 Outcome

- Implemented the TMP36 voltage-to-temperature conversion.
- Created and used a function that returns the calculated temperature.
- Practised separating sensor processing from the main program loop.
- Identified the importance of checking circuit connections when debugging unexpected readings.

### Next Steps

- Restore and verify the sensor wiring.
- Confirm that the raw ADC readings are stable when the temperature setting is unchanged.
- Verify that the displayed temperature responds appropriately to changes in the sensor setting.
- Proceed to transistor or MOSFET switching for the fan in Day 3.