int led = 13;
int sensor = 2;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
}

void loop() {
  if(digitalRead(sensor) == HIGH) {
    digitalWrite(led,HIGH);
  } else {
    digitalWrite(led,LOW);
  }
}
