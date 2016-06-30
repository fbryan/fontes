#include <SoftwareSerial.h>

SoftwareSerial gps(2, 3);
int led = 13;
int led_status = LOW;
String campo[13];

void setup() {
  gps.begin(4800);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  char lido = 0;
  String resposta = "";
  while ((lido = gps.read()) != 10) {
    if (lido > 0) {
      resposta += lido;
    }
  }
  if (!resposta.equals("")) {
    if (resposta.indexOf("RMC") > 0) {
      if (resposta.charAt(17) == 'A') {
        decodeResposta(resposta);
        Serial.println(resposta);
        for(int i=0;i<13;i++) Serial.println(campo[i]);
        led_status = HIGH;
      } else {
        if (led_status == LOW) {
          led_status = HIGH;
        } else {
          led_status = LOW;
        }
      }
    }
  }
  digitalWrite(led, led_status);
}

void decodeResposta(String r) {
  int ant = 0;
  int pos = 0;
  for (int i = 0; i < 13; i++) {
    pos = r.indexOf(",", ant + 1);
    campo[i] = r.substring(ant, pos);
    ant = pos + 1;
  }
}
