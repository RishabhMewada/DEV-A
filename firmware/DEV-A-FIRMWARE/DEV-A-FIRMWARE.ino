#include <Arduino.h>

#define SERIAL_BAUD 115200

unsigned long startTime = 0;
unsigned long lastPrint = 0;
const unsigned long interval = 1000;

void setup() {
Serial.begin(SERIAL_BAUD);

unsigned long timeout = millis();
while (!Serial && (millis() - timeout < 5000)) {
delay(10);
}

startTime = millis();

Serial.println("\n==================================");
Serial.println(" COMPUTE MINI Devboard Booting...");
Serial.println("==================================");

Serial.print("CPU Frequency: ");
Serial.print(rp2040.f_cpu() / 1000000);
Serial.println(" MHz");

Serial.print("Flash Size: ");
Serial.print(rp2040.getFlashSize() / (1024 * 1024));
Serial.println(" MB");

Serial.println("System Initialization: OK");
Serial.println("----------------------------------");
}

void loop() {
unsigned long currentTime = millis();

if (currentTime - lastPrint >= interval) {
lastPrint = currentTime;

Serial.print("Uptime: ");
Serial.print(currentTime / 1000);
Serial.println(" s | Status: RUNNING OK 🚀");

}
}


