int sensorValue = 0;
int previousValue = 0;
int nextValue = 0;

void setup()
{
  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A3);

  if (sensorValue < 133) {
    Serial.println("Stepping on: Field 1");
  }
  if (sensorValue >= 133 and sensorValue < 266) {
   Serial.println("Stepping on: Field 2");
  }
  if (sensorValue >= 266 and sensorValue < 399) {
    Serial.println("Stepping on: Field 3");
  }
  if (sensorValue >= 399 and sensorValue < 532) {
    Serial.println("Stepping on: Field 4");
  }
  if (sensorValue >= 532 and sensorValue < 665) {
    Serial.println("Stepping on: Field 5");
  }
  if (sensorValue >= 665 and sensorValue < 790) {
    Serial.println("Stepping on: Field 6");
  }
  if (sensorValue >= 790 and sensorValue < 900) {
    Serial.println("Stepping on: Field 7");
  }
  if (sensorValue >= 900 and sensorValue < 1000) {
    Serial.println("Stepping on: Field 8");
  }
  if (sensorValue >= 1000) {
    Serial.println("Stepping on: Field 9");
  }
  delay(2000);
}
