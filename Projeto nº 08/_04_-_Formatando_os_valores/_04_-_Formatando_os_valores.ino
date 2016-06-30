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
        Serial.println(formataHora(campo[1]));
        Serial.println(formataData(campo[9]));
        Serial.println(decNMEA(campo[3], campo[4]), 10);
        Serial.println(decNMEA(campo[5], campo[6]), 10);
        Serial.println(velocidadeKM(campo[7]));
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

float velocidadeKM(String v) {
  return v.toFloat() * 1.852;
}

String formataHora(String hr) {
  return hr.substring(0, 2) + ":" + hr.substring(2, 4) + ":" + hr.substring(4, 6);
}

String formataData(String dt) {
  return dt.substring(0, 2) + "/" + dt.substring(2, 4) + "/" + dt.substring(4, 6);
}

double decNMEA(String l, String h) {
  int a = int(l.toFloat()) / 100;
  double b = (l.toFloat() - (a * 100)) / 60;
  if (h.equals("W") || h.equals("S")) {
    return (a + b)*-1;
  } else {
    return a + b;
  }
}

