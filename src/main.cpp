#include "mbed.h"
#include "Global.h"
#include "Digital.h"
#include "Port.h"
#include "TFT.h"

TFT tft(PortF, PE_2, PE_3, PE_4, PE_5, LANDSCAPE_0);

int main() {
  tft.initialize();
  tft.clearScreen();

  char test[] = "TEMPO";

  tft.fillRect(40, 60, 100, 40);

  tft.drawText(test, size(test), 50, 25);
  tft.drawText(test, size(test), 50, 75);

  while(true) {}
  return 0;
}
