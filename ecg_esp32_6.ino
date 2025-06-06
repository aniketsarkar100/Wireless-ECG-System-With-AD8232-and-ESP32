#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "Aniket_002";
const char* password = "zack2001";

// Create a web server on port 80
WebServer server(80);

// HTML page (from previous step)
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset=\"utf-8\">
  <title>ECG Monitor</title>
  <script src=\"https://cdn.jsdelivr.net/npm/chart.js\"></script>
  <style>
    body { font-family: Arial; text-align: center; margin-top: 30px; }
    canvas { max-width: 100%; height: 400px; }
  </style>
</head>
<body>
  <h2>Live ECG Monitoring (ESP32)</h2>
  <canvas id=\"ecgChart\"></canvas>

  <script>
    const ecgData = [];
    const maxDataPoints = 100;

    const ctx = document.getElementById('ecgChart').getContext('2d');
    const ecgChart = new Chart(ctx, {
      type: 'line',
      data: {
        labels: Array(maxDataPoints).fill(''),
        datasets: [{
          label: 'ECG Value',
          data: ecgData,
          borderColor: 'red',
          borderWidth: 1,
          fill: false,
          tension: 0.1,
        }]
      },
      options: {
        animation: false,
        scales: {
          y: { beginAtZero: true, max: 4095 },
          x: { display: false }
        }
      }
    });

    async function fetchECG() {
      try {
        const res = await fetch('/ecg');
        const value = await res.text();
        const ecg = parseInt(value);
        
        if (!isNaN(ecg)) {
          if (ecgData.length >= maxDataPoints) ecgData.shift();
          ecgData.push(ecg);
          ecgChart.update();
        }
      } catch (err) {
        console.error("Fetch error:", err);
      }
    }

    setInterval(fetchECG, 100);
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  pinMode(36, INPUT);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());

  // Route for root page
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlPage);
  });

  // Route for ECG data
  server.on("/ecg", HTTP_GET, []() {
    int ecgValue = analogRead(36); // Use ADC1 pin like GPIO36
    Serial.println(ecgValue);
    server.send(200, "text/plain", String(ecgValue));
  });

  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
} 
