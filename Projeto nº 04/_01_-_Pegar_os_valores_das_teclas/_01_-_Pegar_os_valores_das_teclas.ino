#include <IRLib.h>

IRdecode decodificador;
IRrecv receptor(3);

void setup() {
  Serial.begin(9600);
  receptor.enableIRIn();
  delay(100);
}

void loop() {
  if(receptor.GetResults(&decodificador)) {
    decodificador.decode();
    delay(100);
    Serial.println(decodificador.value, HEX);
    receptor.resume();    
  }
}
