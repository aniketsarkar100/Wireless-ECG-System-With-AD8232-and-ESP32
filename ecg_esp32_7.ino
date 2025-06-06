void setup() {
  Serial.begin(4800);
  pinMode(36, INPUT); // ADC1 pin where OUTPUT of AD8232 is connected
}

void loop() {
  int ecgValue = analogRead(36);
  Serial.println(ecgValue);
  delay(100);  // Print every 100ms
}
