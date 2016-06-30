#include <Servo.h>

Servo motor_d;
Servo motor_t;

int dianteira = 2;
int traseira = 3;

void setup() {
  motor_d.attach(dianteira);
  motor_t.attach(traseira);
  motor_d.write(90);
  motor_t.write(90);
}

void loop() {
}

