#include <Servo.h>

Servo motor_d;
Servo motor_t;

int dianteira = 2;
int traseira = 3;

int i = 0;
int sentido = 0;

void setup() {
  motor_d.attach(dianteira);
  motor_t.attach(traseira);
}

void loop() {
  motor_d.write(i);
  motor_t.write(i);
  if(sentido == 0) i++; else i--;
  if(i > 180) sentido = 1;
  if(i < 0) sentido = 0;
  delay(100);
}

