int motor_01 = 2;

void setup() {
  pinMode(motor_01,OUTPUT);
}

void loop() {
  digitalWrite(motor_01,HIGH);
  delay(1000);
  digitalWrite(motor_01,LOW);
  delay(1000);
}
