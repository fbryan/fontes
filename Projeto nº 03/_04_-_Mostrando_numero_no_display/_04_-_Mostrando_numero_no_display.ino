#include "SevSeg.h"
SevSeg display; 
 
void setup() {
  byte digitos = 2;
  byte pino_digitos[] = {A0, A1};
  byte pino_segmentos[] = {5, 6, 7, 8, 9, 10, 11, 12};
  display.begin(COMMON_ANODE, digitos, pino_digitos, pino_segmentos);
}

void loop() {
  display.setNumber(12,1);
  display.refreshDisplay();
}

