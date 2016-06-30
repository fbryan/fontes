int buzzer = 11;
int vezes = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A0));
  vezes = random(10, 100);
  for (int i = 0; i <= vezes; i++) {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
  }
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
}

void loop() {
}

