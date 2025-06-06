#include <ThingerESP32.h>

#define USERNAME "aniketsarkar"
#define DEVICE_ID "ESP32"
#define DEVICE_CREDENTIAL "ESP32ECG"

#define WIFI_SSID "OnePlus12"
#define WIFI_PASSWORD "k4prhc58"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  Serial.begin(115200);
  thing.add_wifi(WIFI_SSID, WIFI_PASSWORD);

  // Correct usage: Assign value to 'out' using a lambda
  thing["ecg_value"] >> [](pson &out){
    out = analogRead(A0); // Read ECG data from ADC pin
  };
}

void loop() {
  thing.handle();
}