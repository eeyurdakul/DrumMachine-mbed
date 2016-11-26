#include "mbed.h"
#include "Digital.h"
#include "Port.h"
#include "TFT.h"
#include "Flash.h"

Serial mac(USBTX, USBRX);

// TFT tft(PortF, PE_2, PE_3, PE_4, PE_5, LANDSCAPE_0);
Flash flash(PD_14, PA_7, PA_6, PA_5);

int main() {
  mac.printf(strLine);
  flash.initialize();
  flash.erase4KB(2);
  flash.writeWord(1, 10, 65432);
  int a = flash.readWord(1, 10);
  mac.printf("%d\n", a);

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
