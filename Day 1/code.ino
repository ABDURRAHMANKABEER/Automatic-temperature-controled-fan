// C++ code
//

void setup()
  {
    Serial.begin(9600);
  }

void loop()
  {
    int temp = analogRead(A0);
    Serial.println(temp);
    
    delay(500); // Wait for 500 millisecond(s)
  }