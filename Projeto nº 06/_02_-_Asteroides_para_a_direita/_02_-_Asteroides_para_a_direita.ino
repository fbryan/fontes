#include <TVout.h>
#include <video_gen.h>

TVout tv;
int led = 13;
int x = 0;
int y[5];

void setup() {
 pinMode(led,OUTPUT);
 if(tv.begin(NTSC,128,96) == 0) 
  digitalWrite(led,HIGH);
 else
  digitalWrite(led,LOW);
 delay(1000);
 randomSeed(analogRead(A5));
 for(int i=0;i<5;i++) y[i] = random(0,tv.hres());
}

void loop() {
  for(int i=0;i<5;i++) tv.set_pixel(x,y[i],WHITE);
  delay(10);
  for(int i=0;i<5;i++) tv.set_pixel(x,y[i],BLACK);  
  delay(10);
  if(x > tv.hres()) {
    for(int i=0;i<5;i++) y[i] = random(0,tv.hres());
    x = 0;
  } else {
    x++;
  }
}
