#define MOISTURE_SENSOR_PIN A0 //Define pin for soil moisture sensor
#define WATER_PUMP_PIN 9       //Define pin to control the water pump

#define MOISTURE_THRESHOLD 400  //moisture level to trigger watering

void setup() {
  pinMode(WATER_PUMP_PIN, OUTPUT);
  digitalWrite(WATER_PUMP_PIN, LOW); //turn off water pump
  Serial.begin(9600);
}

void loop() {
  //read soil moisture level
  int moisture = analogRead(MOISTURE_SENSOR_PIN);

  //check if moisture is below threshold are suitable
  if (moisture < MOISTURE_THRESHOLD) {
    Serial.println("Moisture is low, watering the plants..."); //display watering status
    digitalWrite(WATER_PUMP_PIN, HIGH); //turn on water pump
    delay(5000); //watering time(5 seconds)
    digitalWrite(WATER_PUMP_PIN, LOW); //turn off water pump
    Serial.println("Plant watered"); //display watering status
  }

  Serial.print("Moisture: "); //display moisture level
  Serial.println(moisture);

  delay(1000); //display delay (1 second)
}
