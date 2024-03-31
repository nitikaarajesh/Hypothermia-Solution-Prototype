#define TEMPERATURE_ALERT_PIN 2 // Change to the pin connected to pin 13 of the first Arduino
#define VEST_LED_PIN 3          // LED simulating the PCM activation

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  bool isTemperatureLow = digitalRead(2);

  if (isTemperatureLow) {
    digitalWrite(3, HIGH); // Turn on LED to simulate PCM activation
    Serial.println("Vest LED is: ON");
  } else {
    digitalWrite(3, LOW);  // Turn off LED to stop PCM simulation
    Serial.println("Vest LED is: OFF");
  }

  delay(100); // Short delay to avoid bouncing
}