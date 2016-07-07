#include <TVout.h>
#include <video_gen.h>

TVout tv;
int led = 13;
int x = 0;
int y[5];
int x_nave;
int y_nave;

void setup() {
 pinMode(led,OUTPUT);
 if(tv.begin(NTSC,128,96) == 0) 
  digitalWrite(led,HIGH);
 else
  digitalWrite(led,LOW);
 delay(1000);
 randomSeed(analogRead(A5));
 for(int i=0;i<5;i++) y[i] = random(0,tv.vres());
 x_nave = tv.hres()-1;
 y_nave = tv.vres()/2;
}

void loop() {
  int ctrl = map(analogRead(A0),0,1024,0,tv.vres());
  tv.draw_line(x_nave,ctrl-2,x_nave,ctrl+2,WHITE);
  delay(10);
  tv.draw_line(x_nave,ctrl-2,x_nave,ctrl+2,BLACK);
  for(int i=0;i<5;i++) tv.set_pixel(x,y[i],WHITE);
  delay(10);
  for(int i=0;i<5;i++) tv.set_pixel(x,y[i],BLACK);  
  if(x > tv.hres()) {
    for(int i=0;i<5;i++) y[i] = random(0,tv.hres());
    x = 0;
  } else {
    x++;
  }
  if(x >= x_nave) {
    for(int i=0;i<5;i++) {
      if((y[i] >= ctrl-2) && (y[i] <= ctrl+2)) {
        tv.clear_screen();
        for(int d=0;d<tv.hres();d++) {
          tv.draw_circle(tv.hres()/2,tv.vres()/2,d,WHITE);
          delay(10);
        }
        delay(15000);
        for(int i=0;i<5;i++) y[i] = random(0,tv.hres());
        tv.clear_screen();
      }
    }
  }
}
