#include <Ultrasonic.h>

Ultrasonic sensor(3, 2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float medida;
  long tempo = sensor.timing();
  medida = sensor.convert(tempo, Ultrasonic::CM);
  Serial.print("Tempo de ida e volta = ");
  Serial.print(tempo);
  Serial.print(" microssegundos - ");
  Serial.print("Distancia medida = ");
  Serial.print(medida);
  Serial.println(" cm");
  delay(1000);
}

