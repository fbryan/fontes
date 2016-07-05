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
  for(int i=1;i<=3;i++) {
    for(int j=1;j<=3;j++) {
      acende(i,j);
      delay(500);
    }
  }
}

void acende(int linha,int coluna) {
  if(linha == 1)  digitalWrite(2,HIGH); else digitalWrite(2,LOW);
  if(linha == 2)  digitalWrite(3,HIGH); else digitalWrite(3,LOW);
  if(linha == 3)  digitalWrite(4,HIGH); else digitalWrite(4,LOW);
  if(coluna == 1) digitalWrite(8,LOW);  else digitalWrite(8,HIGH);
  if(coluna == 2) digitalWrite(9,LOW);  else digitalWrite(9,HIGH);
  if(coluna == 3) digitalWrite(10,LOW); else digitalWrite(10,HIGH);
}

