# Wireless-ECG-System-With-AD8232-ESP32
This project is a real-time wireless ECG monitoring system built using an ESP32 microcontroller and an AD8232 ECG sensor. It captures analog heart signal data, converts it to digital using the ESP32’s ADC, and transmits the data via Wi-Fi. Initially, the system used the Ubidots IoT platform to visualize ECG waveforms on a cloud dashboard with time-synchronized data points. To improve portability and independence from third-party services, a custom web-based visualization interface was developed using HTML, JavaScript, and Chart.js, hosted directly on the ESP32 through its internal web server. The system continuously reads ECG signals and streams live data to any device on the same Wi-Fi network. This lightweight, mobile solution is ideal for remote health monitoring and is powered by a USB power bank for enhanced usability. The project demonstrates core IoT concepts like sensor integration, cloud/data communication, and embedded web development for biomedical applications.
![ad8232 and esp32 2](https://github.com/user-attachments/assets/6fd3cbac-d6de-4ed6-bde0-4d7e88ba664b)
![ecg lead placement](https://github.com/user-attachments/assets/46533e9a-e2ee-4f0b-9c71-a230f0bd3b27)
![ecg waveform proper last](https://github.com/user-attachments/assets/3c771044-c31d-41f4-883c-b34505485f09)


