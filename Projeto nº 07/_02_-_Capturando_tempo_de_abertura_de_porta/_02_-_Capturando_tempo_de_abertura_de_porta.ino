int led = 13;
int sensor = 2;

int ctrl_abre = 0;
int ctrl_fecha = 0;

unsigned long tempo_abrir = 0;
unsigned long tempo_fechar = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  if (digitalRead(sensor) == HIGH) {
    digitalWrite(led, HIGH);
    if (ctrl_abre == 0) {
      tempo_fechar = millis();
      ctrl_abre = 1;
      ctrl_fecha = 0;
      Serial.print("Porta ficou aberta por ");
      Serial.print((tempo_fechar - tempo_abrir) / 1000);
      Serial.println(" segundos");
    }
  } else {
    digitalWrite(led, LOW);
    if (ctrl_fecha == 0) {
      tempo_abrir = millis();
      ctrl_fecha = 1;
      ctrl_abre = 0;
    }
  }
}
