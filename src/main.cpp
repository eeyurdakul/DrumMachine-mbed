#include "mbed.h"
#include "Digital.h"
#include "Port.h"
#include "TFT.h"
// #include "Flash.h"
// #include "HHOpen_80s.h"

Serial mac(USBTX, USBRX);

// uint16_t array[128];

TFT tft(PortF, PE_2, PE_3, PE_4, PE_5, LANDSCAPE_1);
// Flash flash(PD_14, PA_7, PA_6, PA_5);

int main() {
/*
  for (size_t i = 0; i < 128; i++) {
    array[i] = 10000 + i;
  }

  mac.printf(strLine);
  flash.initialize();
  // flash.eraseChip();
  flash.writeWordArray(2302, audioSample, kSampleSize, false);
*/
  char z[] = "MERHABA AYSE";

  tft.initialize();
  tft.fillScreen(BLACK);
  tft.setForeColor(YELLOW);
  tft.setSpacing(4);
  tft.drawText(z, size(z), 100, 25);
  tft.fillRect(10, 10, 50, 50);
  tft.drawCircle(200, 200, 100);
  tft.drawLine(100, 100, 200, 300);
  /*


  tft.fillRect(40, 60, 100, 40);

  tft.drawText(test, size(test), 50, 25);
  tft.drawText(test, size(test), 50, 75);
  */
  while(true) {}
  return 0;
}
