#include <Servo.h>

Servo motor_d;
Servo motor_t;

int dianteira = 2;
int traseira = 3;

int i = 0;

void setup() {
  motor_d.attach(dianteira);
  motor_t.attach(traseira);
}

void loop() {
  motor_d.write(i);
  motor_t.write(i);
  i++;
  if(i > 180) i = 0;
  delay(100);
}

