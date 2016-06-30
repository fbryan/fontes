#include <EEPROM.h>

int tempo = 0;
int tempo_max = 30;

int led = 13;
int sensor = 2;
int buzzer = 11;

int ctrl_abre = 0;
int ctrl_fecha = 0;
int contador = -1;

unsigned long tempo_abrir = 0;
unsigned long tempo_fechar = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  if(EEPROM.read(0) != 9) {
    EEPROM.write(0,9);
    EEPROM.write(1,0);
    EEPROM.write(2,0);
  }
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
      contador++;
      EEPROM.write(1,contador);
      if(EEPROM.read(2) < (tempo_fechar - tempo_abrir) / 1000) {
        EEPROM.write(2,round((tempo_fechar - tempo_abrir) / 1000));
      }
    }
  } else {
    digitalWrite(led, LOW);
    tempo = millis() / 1000;
    if(tempo - (tempo_fechar / 1000) > tempo_max) {
      digitalWrite(buzzer,HIGH);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
    }
    if (ctrl_fecha == 0) {
      tempo_abrir = millis();
      ctrl_fecha = 1;
      ctrl_abre = 0;
      tempo = 0;
    }
  }
  if(Serial.available() > 0) {
    char lido = toUpperCase(Serial.read());
    if(lido == 'Q') {
      Serial.println("Nesse ciclo a porta da geladeira: ");
      Serial.print("Foi aberta ");
      Serial.print(EEPROM.read(1));
      Serial.println(" vezes.");
      Serial.print("Ficou aberta pelo tempo maximo de ");
      Serial.print(EEPROM.read(2));
      Serial.println(" segundos.");
    }
    if(lido == 'R') {
      Serial.println("Valores zerados, novo ciclo iniciado.");
      contador = 0;
      EEPROM.write(1,0);
      EEPROM.write(2,0);
    }
  }
}
