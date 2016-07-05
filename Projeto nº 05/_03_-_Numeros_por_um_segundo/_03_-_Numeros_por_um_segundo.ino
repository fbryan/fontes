// Linha 1 - Pino 2 
// Linha 2 - Pino 3 
// Linha 3 - Pino 4 

// Coluna 1 - Pino 8 
// Coluna 2 - Pino 9 
// Coluna 3 - Pino 10

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  um(1);
  dois(1);
  tres(1);
  quatro(1);
  cinco(1);
  seis(1);
}

void acende(int linha,int coluna) {
  if(linha == 1)  digitalWrite(2,HIGH); else digitalWrite(2,LOW);
  if(linha == 2)  digitalWrite(3,HIGH); else digitalWrite(3,LOW);
  if(linha == 3)  digitalWrite(4,HIGH); else digitalWrite(4,LOW);
  if(coluna == 1) digitalWrite(8,LOW);  else digitalWrite(8,HIGH);
  if(coluna == 2) digitalWrite(9,LOW);  else digitalWrite(9,HIGH);
  if(coluna == 3) digitalWrite(10,LOW); else digitalWrite(10,HIGH);
}

void um(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 1000)) {
    tempo = millis();
    acende(2,2);
  }
}

void dois(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 998)) {
    tempo = millis();
    acende(1,1);
    delay(1);
    acende(3,3);
    delay(1);
  }
}

void tres(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 997)) {
    tempo = millis();
    acende(1,1);
    delay(1);
    acende(2,2);
    delay(1);
    acende(3,3);
    delay(1);
  }
}

void quatro(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 996)) {
    tempo = millis();
    acende(1,1);
    delay(1);
    acende(1,3);
    delay(1);
    acende(3,1);
    delay(1);
    acende(3,3);
    delay(1);
  }
}

void cinco(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 995)) {
    tempo = millis();
    acende(1,1);
    delay(1);
    acende(1,3);
    delay(1);
    acende(2,2);
    delay(1);
    acende(3,1);
    delay(1);
    acende(3,3);
    delay(1);
  }
}

void seis(int t) {
  unsigned long tempo;
  unsigned long tempo_anterior = tempo = millis();
  while(tempo - tempo_anterior < (t * 994)) {
    tempo = millis();
    acende(1,1);
    delay(1);
    acende(1,2);
    delay(1);
    acende(1,3);
    delay(1);
    acende(3,1);
    delay(1);
    acende(3,2);
    delay(1);
    acende(3,3);
    delay(1);
  }
}
