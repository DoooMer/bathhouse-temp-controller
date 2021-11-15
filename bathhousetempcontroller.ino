// C++ code
//
const int GREEN_LED = 13;
const int RED_LED = 12;
const float TEMP_OK = 50; // temperature for enable green led

void setup()
{
  pinMode(A0, INPUT); // inside
  pinMode(A1, INPUT); // outside
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
  
  // off led's
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop()
{
  float tempInside = -40 + 0.488155 * (analogRead(A0) - 20);
  float tempOutside = -40 + 0.488155 * (analogRead(A1) - 20);
  
  Serial.println(tempInside);
  Serial.println(tempOutside);
  
  if (tempInside >= 50) {
    // when temperature is ok - enable green led
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  } else {
    // when temperature is low - enable red led
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  delay(200); // Wait for 200 millisecond(s)
}