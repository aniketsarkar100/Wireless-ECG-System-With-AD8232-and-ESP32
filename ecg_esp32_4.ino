#include <ThingerCore32.h>

ThingerCore32 thing("aniketsarkar", "ECGMonitoringSystem", "F#a8gCyV9Oas7W@X","OnePlus12", "k4prhc58");

void setup() {
  Serial.begin(115200);
  
  // Declare ECG data resource
  thing["ecg_value"] = [] {
    return analogRead(36);  // Replace 36 with your actual ADC pin
  };
}

void loop() {
  thing.handle();