#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <WiFi.h>           // <--- Critical Fix
#include <PubSubClient.h>
#include <Wire.h>
#include "INA3221.h"

// --- SHARED OBJECTS ---
extern WiFiClient espClient;
extern PubSubClient mqtt_client;
extern INA3221 INA;

// --- SHARED STATE VARIABLES ---
extern bool powerCutDetected;
extern bool emergencyModeActive;
extern bool manualEmergencyControl;
extern bool gpio14Activated;

extern float currentLightIntensity;
extern float totalEnergyConsumed;
extern float startVoltage;
extern float endVoltage;

extern unsigned long emergencyStartTime;
extern unsigned long gpio14ActivationTime;
extern unsigned long powerCutStartTime;
extern unsigned long lastEnergyCalcTime;

#endif