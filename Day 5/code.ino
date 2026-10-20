float readTemperature()
{
    float rawReading = analogRead(A0);
    float vIn = (rawReading / 1023.0) * 5.0;
    float temp = (vIn - 0.5) / 0.01;

    return temp;
}

bool fanOn = false;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    float temp = readTemperature();
  	
  	if (temp >= 30.0) {
      fanOn = true;
    }
    else if (temp <= 28.0) {
      fanOn = false;
    } 

    Serial.print("Temp:");
    Serial.println(temp);
    Serial.print("Fan:");
    Serial.println(fanOn);

    delay(500);
}