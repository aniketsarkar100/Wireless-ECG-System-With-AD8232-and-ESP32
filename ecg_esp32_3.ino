const int ecgPin = 36; // Analog pin connected to AD8232 OUTPUT

void setup() {
  Serial.begin(4800);
  delay(2000); // Give time to stabilize
  Serial.println("ECG Data");
}

void loop() {
  int ecgValue = analogRead(ecgPin);  // Read analog ECG signal
  Serial.println(ecgValue);           // Send to Serial Plotter
  delay(2);                           // Small delay for smoother plot
}