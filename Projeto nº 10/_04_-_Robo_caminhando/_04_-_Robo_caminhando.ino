#include <Servo.h>

Servo motor_d;
Servo motor_t;

int dianteira = 2;
int traseira = 3;

int i = 45, j = 90;
int sentido = 0;

void setup() {
  motor_d.attach(dianteira);
  motor_t.attach(traseira);
}

void loop() {
  motor_d.write(i);
  motor_t.write(j);
  if(sentido == 0) {
    i++;
    j--;
  } else {
    i--;
    j++;
  }
  if(i > 90) sentido = 1;
  if(i < 45) sentido = 0;
  delay(50);
}

