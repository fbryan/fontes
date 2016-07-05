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
  randomSeed(analogRead(A0));
  int numero = random(1,6);
  if(numero == 1) um(5);
  if(numero == 2) dois(5);
  if(numero == 3) tres(5);
  if(numero == 4) quatro(5);
  if(numero == 5) cinco(5);
  if(numero == 6) seis(5);
  apaga();
  while(1);
}

void loop() {
  um(1);
  dois(1);
  tres(1);
  quatro(1);
  cinco(1);
  seis(1);
}

void apaga() {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
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
