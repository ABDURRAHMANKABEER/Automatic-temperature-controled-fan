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