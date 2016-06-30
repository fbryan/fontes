#include <Ultrasonic.h>
#include <SevSeg.h>

Ultrasonic sensor(3, 2);
SevSeg display; 

int botao = 4;

float anterior = 0;
float distancia = 0;
float deslocamento = 0;

void setup()
{
  pinMode(botao, INPUT_PULLUP);
  byte digitos = 2;
  byte pino_digitos[] = {A0, A1};
  byte pino_segmentos[] = {5, 6, 7, 8, 9, 10, 11, 12};
  display.begin(COMMON_ANODE, digitos, pino_digitos, pino_segmentos);
}

void loop()
{
  if (digitalRead(botao) == LOW) {
    long tempo = sensor.timing();
    float medida = round(sensor.convert(tempo, Ultrasonic::CM));
    distancia = abs(medida - anterior);
    deslocamento = (distancia * 10) / 100;
    anterior = medida;
  }
  display.setNumber(deslocamento,1);
  display.refreshDisplay();
}

