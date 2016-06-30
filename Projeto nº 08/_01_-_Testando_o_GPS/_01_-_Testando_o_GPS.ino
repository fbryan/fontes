#include <SoftwareSerial.h>

SoftwareSerial gps(2,3);

void setup() {
  gps.begin(4800);
  Serial.begin(9600);  
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
    Serial.println(resposta);
  }
}
