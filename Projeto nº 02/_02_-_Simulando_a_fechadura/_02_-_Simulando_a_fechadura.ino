#include <Key.h>
#include <Keypad.h>

const byte n_linhas = 4;
const byte n_colunas = 3;
char teclas[n_linhas][n_colunas] =  {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'},
            {'*','0','#'}
          };
byte mapa_linha[n_linhas] = {9,8,7,6};
byte mapa_coluna[n_colunas] = {5,4,3};
Keypad teclado = Keypad(makeKeymap(teclas),mapa_linha,mapa_coluna,n_linhas,n_colunas);

int pos = 0;
int led = 13;
char senha[12];
char correta[] = "123456";

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  char tecla = teclado.getKey();
  if(tecla != NO_KEY) {
    if(tecla != '#') {
      senha[pos] = tecla;
      pos++;
    }
    if(tecla == '#') {
      Serial.println(senha);
      if(!strcmp(correta,senha)) {
        Serial.println("Senha correta");
        digitalWrite(led,HIGH);
        delay(5000);
      }
      for(int i=0;i<strlen(senha);i++) senha[i] = ' ';
      pos = 0;
      digitalWrite(led,LOW);

    }
  }
}
