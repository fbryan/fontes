#include <SoftwareSerial.h>

SoftwareSerial gps(2,3);
int led = 13;
int led_status = LOW;

void setup() {
  gps.begin(4800);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  char lido = 0;
  String resposta = "";
  while((lido = gps.read()) != 10) {
    if(lido > 0) {
      resposta += lido;
    }
  }
  if(!resposta.equals("")) {
    if(resposta.indexOf("RMC") > 0) {
      if(resposta.charAt(17) == 'A') {
        Serial.println(resposta);
        led_status = HIGH;
      } else {
        if(led_status == LOW) {
          led_status = HIGH;
        } else {
          led_status = LOW;
        }
      }
    }
  }
  digitalWrite(led,led_status);
}
