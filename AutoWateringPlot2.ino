#define MOISTURE_SENSOR_PIN A0 //กำหนดขาแอนะล็อกสำหรับเซ็นเซอร์วัดความชื้นในดิน
#define WATER_PUMP_PIN 9       //กำหนดขาควบคุมรีเลย์ที่ใช้เปิด-ปิดปั้มน้ำ

#define MOISTURE_THRESHOLD 400  //กำหนดค่าระดับความชื้นที่จะทำให้ระบบรดน้ำ

void setup() {
  pinMode(WATER_PUMP_PIN, OUTPUT);
  digitalWrite(WATER_PUMP_PIN, LOW); //ปิดปั้มน้ำ
  Serial.begin(9600);
}

void loop() {
  //วัดระดับความชื้นในดิน
  int moisture = analogRead(MOISTURE_SENSOR_PIN);

  //เช็คว่าระดับความชื้นต่ำกว่าเกณฑ์และสภาพอากาศเหมาะสมหรือไม่
  if (moisture < MOISTURE_THRESHOLD) {
    Serial.println("Moisture is low, watering the plants..."); //แสดงสถานะรดน้ำ
    digitalWrite(WATER_PUMP_PIN, HIGH); //เปิดปั้มน้ำ
    delay(5000); //ระยะเวลารดน้ำ(5วินาที)
    digitalWrite(WATER_PUMP_PIN, LOW); //ปิดปั้มน้ำ
    Serial.println("Plant watered"); //แสดงสถานะรดน้ำพืช
  }

  Serial.print("Moisture: "); //แสดงค่าความชื้น
  Serial.println(moisture);

  delay(1000); //ระยะเวลาแสดงผล(1วินาที)
}
