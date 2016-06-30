#include <Ultrasonic.h>

Ultrasonic sensor(3, 2);

int botao = 4;

float anterior = 0;
float distancia = 0;
float deslocamento = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(botao) == LOW) {
    long tempo = sensor.timing();
    float medida = round(sensor.convert(tempo, Ultrasonic::CM));
    distancia = abs(medida - anterior);
    deslocamento = (distancia * 10) / 100;
    Serial.print("anterior = ");
    Serial.print(anterior);
    Serial.print(" - ");
    Serial.print("medida = ");
    Serial.print(medida);
    Serial.print(" - ");
    Serial.print("distancia = ");
    Serial.print(distancia);
    Serial.print(" - ");
    Serial.print("velocidade = ");
    Serial.print(deslocamento);
    Serial.println(" m/seg");
    delay(100);
    anterior = medida;
  }
}

