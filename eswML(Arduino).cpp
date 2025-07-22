#include <DHT.h>  // Include the DHT sensor library
#include <Adafruit_Sensor.h>

// Define constants for the linear model
const float slope_DC = 4.1623;
const float slope_Temp = 0.0058;
const float intercept = -14.6694;

// Default parameters
const float R1 = 9300.0;  // Fixed resistor value (Ohms)
const float R2 = 383.0;
const float RC_default = 820.0;  // Default variable resistor value (Ohms)
const float gain_original = 27.1;  // Original default gain

// Pin definitions
const int tempSensorPin = 2;  // Pin for DHT sensor
const int dcSensorPin = A0;   // Pin for DC voltage sensor (analog input)

// Initialize DHT sensor
DHT dht(tempSensorPin, DHT11);  // DHT sensor type (DHT11)

void setup() {
  Serial.begin(9600);
  dht.begin();  // Initialize the DHT sensor
  pinMode(dcSensorPin, INPUT);  // Set DC sensor pin as input
}

void loop() {
  // Step 1: Read temperature from DHT sensor (in Celsius)
  float temp = dht.readTemperature();
  
  // Step 2: Read DC voltage from sensor (value between 0 to 1023)
  int dcReading = analogRead(dcSensorPin);
  float dcVoltage = (dcReading * 0.029);  // Convert to voltage (assume 5V reference and scale factor)
  dcVoltage = (dcVoltage * (R1 + R2)) / R2;  // Account for voltage divider
  
  // Step 3: Calculate gain using the updated linear model
  float gain = slope_DC * dcVoltage + slope_Temp * temp + intercept;

  // Step 4: Calculate new resistor value to match the original gain
  float R2_new = RC_default * (gain_original / gain);

  // Display the results
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, DC Voltage: ");
  Serial.print(dcVoltage);
  Serial.print(" V, New Gain : ");
  Serial.print(gain);
  Serial.print(", New Required Resistor: ");
  Serial.print(R2_new);
  Serial.println(" Ohms\n");
  
  delay(1000);  // Delay for 1 second before reading again
}