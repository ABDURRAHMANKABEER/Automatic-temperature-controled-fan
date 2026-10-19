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