#include <Arduino.h>
#include "config.h"
#include "globals.h"
#include "network.h"
#include "hardware.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== ESP32 MQTT LED Controller (Modular) ===");

  setupHardware();
  
  connectWiFi();
  
  mqtt_client.setServer(mqtt_broker, mqtt_port);
  mqtt_client.setCallback(mqttCallback);
  connectMQTT();
}

void loop() {
  checkNetwork(); // Keeps WiFi/MQTT alive
  updateSensors(); // Reads INA3221 and Intensity
  handleEmergencyLogic(); // Handles the 1-minute timer
}