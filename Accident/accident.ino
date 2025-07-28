#include <DHT.h>

// --- Pin Definitions ---
const int mq2Pin = A0;
const int mq3Pin = A1;
const int flameSensorPin = 2;
const int dhtPin = 3;          // DHT11 data pin
const int buzzerPin = 8;
const int ledPin = 9;

// --- Sensor Thresholds ---
const int smokeThreshold = 300;
const int alcoholThreshold = 350;

// --- DHT Settings ---
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(flameSensorPin, INPUT);
  
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // --- MQ-2: Smoke Detection ---
  int smokeLevel = analogRead(mq2Pin);
  Serial.print("Smoke Level (MQ-2): ");
  Serial.println(smokeLevel);

  if (smokeLevel > smokeThreshold) {
    alert("Smoke Detected!");
  } else {
    resetAlert();
  }
  delay(1000);

  // --- MQ-3: Alcohol Detection ---
  int alcoholLevel = analogRead(mq3Pin);
  Serial.print("Alcohol Level (MQ-3): ");
  Serial.println(alcoholLevel);

  if (alcoholLevel > alcoholThreshold) {
    alert("Alcohol Detected!");
  } else {
    resetAlert();
  }
  delay(1000);

  // --- Flame Detection ---
  int flameStatus = digitalRead(flameSensorPin);
  Serial.print("Flame Sensor: ");
  Serial.println(flameStatus == LOW ? "Flame Detected!" : "No Flame");

  if (flameStatus == LOW) {
    alert("Flame Detected!");
  } else {
    resetAlert();
  }
  delay(1000);

  // --- DHT11: Temp & Humidity ---
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000); // Longer delay for DHT11 reading
}

// --- Helper Functions ---
void alert(const char* message) {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  Serial.println(message);
}

void resetAlert() {
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}



