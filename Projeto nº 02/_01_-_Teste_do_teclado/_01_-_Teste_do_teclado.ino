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

void setup() {
  Serial.begin(9600);  
}

void loop() {
  char tecla = teclado.getKey();
  if(tecla != NO_KEY) {
    Serial.println(tecla);
  }
}
