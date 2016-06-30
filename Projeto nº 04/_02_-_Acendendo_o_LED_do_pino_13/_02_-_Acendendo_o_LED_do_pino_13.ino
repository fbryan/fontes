#include <IRLib.h>

IRdecode decodificador;
IRrecv receptor(3);

int led = 13;
long valor = 0;

void setup() {
  pinMode(led,OUTPUT);
  receptor.enableIRIn();
  delay(100);
}

void loop() {
  if(receptor.GetResults(&decodificador)) {
    decodificador.decode();
    delay(100);
    valor = decodificador.value;
    if(valor == 0xFF4AB5) {
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
    }
    receptor.resume();    
  }
}

