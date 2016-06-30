#include <SD.h>

void setup() {
  Serial.begin(9600);
  if(!SD.begin(4)) {
    Serial.println("Houve um erro em inicializar o modulo SD.");
    while(1);
  }
  Serial.println("Modulo SD inicializado com sucesso.");
}

void loop() {
  String texto = "Teste de gravação no cartão SD";
  File arquivo = SD.open("teste.txt", FILE_WRITE);
  if(arquivo) {
    arquivo.println(texto);
    arquivo.close();
    Serial.println("Texto gravado!");
    while(1);
  }
}
