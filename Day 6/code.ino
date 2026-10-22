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