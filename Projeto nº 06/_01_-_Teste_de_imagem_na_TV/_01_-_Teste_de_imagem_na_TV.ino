#include <TVout.h>
#include <video_gen.h>

TVout tv;
int led = 13;

void setup() {
 pinMode(led,OUTPUT);
 if(tv.begin(NTSC,128,96) == 0) {
  digitalWrite(led,HIGH);
 } else {
  digitalWrite(led,LOW);
 }
 delay(1000);
 tv.draw_rect(0,0,71,55,WHITE,BLACK);
 tv.draw_line(0,0,10,10,WHITE);
 tv.draw_circle(36,28,10,WHITE);
 tv.set_pixel(36,28,WHITE);
}

void loop() {
}
