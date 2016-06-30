int sensor_01 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensor_01 = analogRead(A0);
  Serial.println(sensor_01);
}
