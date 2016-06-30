int sensor_01 = 0;
int motor_01 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(motor_01,OUTPUT);
}

void loop() {
  sensor_01 = analogRead(A0);
  Serial.println(sensor_01);
  if(sensor_01 < 500) {
    digitalWrite(motor_01,HIGH);
  } else {
    digitalWrite(motor_01,LOW);
  }
}
