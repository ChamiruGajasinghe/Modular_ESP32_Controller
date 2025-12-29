#include "globals.h"

// --- SHARED OBJECTS ---
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

// RobTillaart's library accepts the standard integer address
INA3221 INA(0x40);

// --- SHARED STATE VARIABLES ---
bool powerCutDetected = false;
bool emergencyModeActive = false;
bool manualEmergencyControl = false;
bool gpio14Activated = false;

float currentLightIntensity = 100.0;
float totalEnergyConsumed = 0;
float startVoltage = 0;
float endVoltage = 0;

unsigned long emergencyStartTime = 0;
unsigned long gpio14ActivationTime = 0;
unsigned long powerCutStartTime = 0;
unsigned long lastEnergyCalcTime = 0;