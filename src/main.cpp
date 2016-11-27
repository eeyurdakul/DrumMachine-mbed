#include "mbed.h"
#include "Digital.h"
#include "Port.h"
#include "TFT.h"
#include "Flash.h"
#include "HHOpen_80s.h"

Serial mac(USBTX, USBRX);

uint16_t array[128];

// TFT tft(PortF, PE_2, PE_3, PE_4, PE_5, LANDSCAPE_0);
Flash flash(PD_14, PA_7, PA_6, PA_5);

int main() {

  for (size_t i = 0; i < 128; i++) {
    array[i] = 10000 + i;
  }

  mac.printf(strLine);
  flash.initialize();
  // flash.eraseChip();
  flash.writeWordArray(2302, audioSample, kSampleSize, false);

  /*
  tft.initialize();
  tft.clearScreen();

  char test[] = "TEMPO";

  tft.fillRect(40, 60, 100, 40);

  tft.drawText(test, size(test), 50, 25);
  tft.drawText(test, size(test), 50, 75);
  */
  while(true) {}
  return 0;
}
