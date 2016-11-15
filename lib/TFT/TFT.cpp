#include "TFT.h"

TFT::TFT(PortName dataPort, PinName rsPin, PinName wrPin, PinName csPin, PinName rstPin, TFT_Rotation rotation_)
: dataBus(dataPort, PORT_SPEED_100MHz)
, rs(rsPin, DIG_SPEED_100MHz)
, wr(wrPin, DIG_SPEED_100MHz)
, cs(csPin, DIG_SPEED_100MHz)
, rst(rstPin, DIG_SPEED_100MHz)
, foreColor(WHITE)
, backColor(BLACK)
, rotation(rotation_) {
  setFont(FONT_S);
  switch (rotation) {
    case 0:
    width  = kTFT_WIDTH;
    height = kTFT_HEIGHT;
    break;
    case 1:
    width  = kTFT_HEIGHT;
    height = kTFT_WIDTH;
    break;
    case 2:
    width  = kTFT_WIDTH;
    height = kTFT_HEIGHT;
    break;
    case 3:
    width  = kTFT_HEIGHT;
    height = kTFT_WIDTH;
    break;
  }
}

TFT::~TFT() {}

// private methods

void TFT::writeCommand(TFT_Command command) {
  rs.writeLow();
  dataBus.write(command);
  wr.writeLow();
  wr.writeHigh();
}

void TFT::writeData(uint16_t data) {
  rs.writeHigh();
  dataBus.write(data);
  wr.writeLow();
  wr.writeHigh();
}

void TFT::setAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
  writeCommand(TFT_SET_COLUMN_ADDRESS);
  writeData(x0 >> 8);
  writeData(x0);
  writeData(x1 >> 8);
  writeData(x1);
  writeCommand(TFT_SET_PAGE_ADDRESS);
  writeData(y0 >> 8);
  writeData(y0);
  writeData(y1 >> 8);
  writeData(y1);
  writeCommand(TFT_WRITE_MEMORY_START);
}

void TFT::clearAddressWindow() {
  setAddressWindow(0, 0, width - 1, height - 1);
}

void TFT::fastFill(TFT_Color color, uint32_t pixel) {
  dataBus.write(color);

  uint32_t blocks;
  blocks = pixel / 16;

  for (uint32_t i = 0; i < blocks; i++)
  {
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
    wr.writeLow();
    wr.writeHigh();
  }

  if ((pixel % 16) != 0)
  for (uint8_t i = 0; i < (pixel % 16) + 1; i++)
  {
    wr.writeLow();
    wr.writeHigh();
  }
}

uint8_t TFT::getLetter(char letter) {
  switch (letter) {
    case '0':
    return 0;
    break;
    case '1':
    return 1;
    break;
    case '2':
    return 2;
    break;
    case '3':
    return 3;
    break;
    case '4':
    return 4;
    break;
    case '5':
    return 5;
    break;
    case '6':
    return 6;
    break;
    case '7':
    return 7;
    break;
    case '8':
    return 8;
    break;
    case '9':
    return 9;
    break;
    case 'A':
    case 'a':
    return 10;
    break;
    case 'B':
    case 'b':
    return 11;
    break;
    case 'C':
    case 'c':
    return 12;
    break;
    case 'D':
    case 'd':
    return 13;
    break;
    case 'E':
    case 'e':
    return 14;
    break;
    case 'F':
    case 'f':
    return 15;
    break;
    case 'G':
    case 'g':
    return 16;
    break;
    case 'H':
    case 'h':
    return 17;
    break;
    case 'I':
    case 'i':
    return 18;
    break;
    case 'J':
    case 'j':
    return 19;
    break;
    case 'K':
    case 'k':
    return 20;
    break;
    case 'L':
    case 'l':
    return 21;
    break;
    case 'M':
    case 'm':
    return 22;
    break;
    case 'N':
    case 'n':
    return 23;
    break;
    case 'O':
    case 'o':
    return 24;
    break;
    case 'P':
    case 'p':
    return 25;
    break;
    case 'Q':
    case 'q':
    return 26;
    break;
    case 'R':
    case 'r':
    return 27;
    break;
    case 'S':
    case 's':
    return 28;
    break;
    case 'T':
    case 't':
    return 29;
    break;
    case 'U':
    case 'u':
    return 30;
    break;
    case 'V':
    case 'v':
    return 31;
    break;
    case 'W':
    case 'w':
    return 32;
    break;
    case 'X':
    case 'x':
    return 33;
    break;
    case 'Y':
    case 'y':
    return 34;
    break;
    case 'Z':
    case 'z':
    return 35;
    break;
    case '/':
    return 36;
    break;
    case '-':
    return 37;
    break;
    case '+':
    return 38;
    break;
    case '%':
    return 39;
    break;
    case '.':
    return 40;
    break;
    case ',':
    return 41;
    break;
    case ':':
    return 42;
    break;
    case '<':
    return 43;
    break;
    case '>':
    return 44;
    break;
    case '[':
    return 45;
    break;
    case ']':
    return 46;
    break;
    case '_':
    return 47;
    break;
    case '|':
    return 48;
    break;
    case ' ':
    return 49;
    break;
    default:
    return 49;
    break;
  }
}

// public methods

uint16_t TFT::getWidth() const {
  return width;
}

uint16_t TFT::getHeight() const {
  return height;
}

void TFT::setForeColor(TFT_Color color) {
  foreColor = color;
}

TFT_Color TFT::getForeColor() const {
  return foreColor;
}

void TFT::setBackColor(TFT_Color color) {
  backColor = color;
}

TFT_Color TFT::getBackColor() const {
  return backColor;
}

void TFT::setRotation(TFT_Rotation rotation_) {
  rotation = rotation_;
  cs.writeLow();
  writeCommand(TFT_SET_ADDRESS_MODE);
  switch (rotation) {
    case PORTRAIT_0:
    writeData(0x0A);
    width  = kTFT_WIDTH;
    height = kTFT_HEIGHT;
    break;
    case LANDSCAPE_0:
    writeData(0x28);
    width  = kTFT_HEIGHT;
    height = kTFT_WIDTH;
    break;
    case PORTRAIT_1:
    writeData(0x09);
    width  = kTFT_WIDTH;
    height = kTFT_HEIGHT;
    break;
    case LANDSCAPE_1:
    writeData(0x2B);
    width  = kTFT_HEIGHT;
    height = kTFT_WIDTH;
    break;
  }
  cs.writeHigh();
}

TFT_Rotation TFT::getRotation() const {
  return rotation;
}

void TFT::setFont(TFT_Font font_) {
  font = font_;
  switch (font) {
    case FONT_S:
    fontData = &kFontData_Small[0][0];
    fontWidth = kFontWidth_Small;
    fontHeight = kFontHeight_Small;
    fontSpacing = kFontSpacing_Small;
    break;
    case FONT_M:
    fontData = &kFontData_Medium[0][0];
    fontWidth = kFontWidth_Medium;
    fontHeight = kFontHeight_Medium;
    fontSpacing = kFontSpacing_Medium;
    break;
    case FONT_L:
    fontData = &kFontData_Large[0][0];
    fontWidth = kFontWidth_Large;
    fontHeight = kFontHeight_Large;
    fontSpacing = kFontSpacing_Large;
    break;
  }
}

TFT_Font TFT::getFont() const {
  return font;
}

void TFT::setSpacing(uint16_t spacing) {
  fontSpacing = spacing;
}

uint16_t TFT::getSpacing() const {
  return fontSpacing;
}

void TFT::initialize() {
  // reset TFT
  rst.writeLow();
  wait_ms(50);
  rst.writeLow();
  wait_ms(150);
  rst.writeHigh();
  wait_ms(150);
  dataBus.write(0x00);
  wr.writeHigh();
  cs.writeLow();
  // initialize TFT
  writeCommand(TFT_EXIT_SLEEP_MODE);
  wait_ms(20);
  writeCommand(TFT_POWER_SETTING);
  writeData(0x07);
  writeData(0x42);
  writeData(0x18);
  writeCommand(TFT_VCOM_CONTROL);
  writeData(0x00);
  writeData(0x07);
  writeData(0x10);
  writeCommand(TFT_POWER_SETTING_NORMAL);
  writeData(0x01);
  writeData(0x02);
  writeCommand(TFT_PANEL_DRIVING_SETTING);
  writeData(0x10);
  writeData(0x3B);
  writeData(0x00);
  writeData(0x02);
  writeData(0x11);
  writeCommand(TFT_FRAME_RATE);
  writeData(0x03);
  writeCommand(TFT_GAMMA_SETTING);
  writeData(0x00);
  writeData(0x32);
  writeData(0x36);
  writeData(0x45);
  writeData(0x06);
  writeData(0x16);
  writeData(0x37);
  writeData(0x75);
  writeData(0x77);
  writeData(0x54);
  writeData(0x0C);
  writeData(0x00);
  writeCommand(TFT_SET_ADDRESS_MODE);
  switch (rotation) {
    case 0:
    writeData(0x0A);
    break;
    case 1:
    writeData(0x28);
    break;
    case 2:
    writeData(0x09);
    break;
    case 3:
    writeData(0x2B);
    break;
  }
  writeCommand(TFT_SET_PIXEL_FORMAT);
  writeData(0x55);
  writeCommand(TFT_SET_COLUMN_ADDRESS);
  writeData(0x00);
  writeData(0x00);
  writeData(0x01);
  writeData(0x3F);
  writeCommand(TFT_SET_PAGE_ADDRESS);
  writeData(0x00);
  writeData(0x00);
  writeData(0x01);
  writeData(0xE0);
  wait_ms(120);
  writeCommand(TFT_SET_DISPLAY_ON);
  writeCommand(TFT_WRITE_MEMORY_START);
}

void TFT::clearScreen() {
  cs.writeLow();
  clearAddressWindow();
  rs.writeHigh();
  fastFill(backColor, width * height);
  cs.writeHigh();
}

void TFT::fillScreen() {
  fillScreen(foreColor);
}

void TFT::fillScreen(TFT_Color color) {
  cs.writeLow();
  clearAddressWindow();
  rs.writeHigh();
  fastFill(color, width * height);
  cs.writeHigh();
}

void TFT::drawPixel(uint16_t x, uint16_t y) {
  if ((x < width) && (y < height)) {
    cs.writeLow();
    setAddressWindow(x, y, x, y);
    rs.writeHigh();
    dataBus.write(foreColor);
    wr.writeLow();
    wr.writeHigh();
    cs.writeHigh();
  }
}

void TFT::drawHLine(uint16_t x, uint16_t y, uint16_t l) {
  if ((x < width) && (y < height)) {
    if ((x + l - 1) >= width) {
      l = width - x;
    }
    cs.writeLow();
    setAddressWindow(x, y, x + l - 1, y);
    rs.writeHigh();
    fastFill(foreColor, l);
    cs.writeHigh();
  }
}

void TFT::drawVLine(uint16_t x, uint16_t y, uint16_t l) {
  if ((x < width) && (y < height)) {
    if((y + l - 1) >= height) {
      l = height - y;
    }
    cs.writeLow();
    setAddressWindow(x, y, x, y + l - 1);
    rs.writeHigh();
    fastFill(foreColor, l);
    cs.writeHigh();
  }
}

void TFT::drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    swap(x0, y0);
    swap(x1, y1);
  }

  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++) {
    if (steep) {
      drawPixel(y0, x0);
    } else {
      drawPixel(x0, y0);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

void TFT::drawRect(uint16_t x, uint16_t y, uint32_t w, uint32_t h) {
  if((x < width) && (y < height)) {
    if ((x + w - 1) >= width) {
      w = width - x;
    }
    if ((y + h - 1) >= height) {
      h = height - y;
    }
    drawHLine(x, y, w);
    drawHLine(x, y + h - 1, w);
    drawVLine(x, y, h);
    drawVLine(x + w - 1, y, h);
  }
}

void TFT::fillRect(uint16_t x, uint16_t y, uint32_t w, uint32_t h) {
  if ((x < width) && (y < height)) {
    if ((x + w - 1) >= width) {
      w = width - x;
    }
    if ((y + h - 1) >= height) {
      h = height - y;
    }
    cs.writeLow();
    setAddressWindow(x, y, x + w - 1, y + h - 1);
    rs.writeHigh();
    fastFill(foreColor, w * h);
    cs.writeHigh();
  }
}

void TFT::drawCircle(uint16_t x, uint16_t y, uint16_t r) {
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t xc = 0;
  int16_t yc = r;
  drawPixel(x, y + r);
  drawPixel(x, y - r);
  drawPixel(x + r, y);
  drawPixel(x - r, y);
  while (xc < yc) {
    if (f >= 0) {
      yc--;
      ddF_y += 2;
      f += ddF_y;
    }
    xc++;
    ddF_x += 2;
    f += ddF_x;
    drawPixel(x + xc, y + yc);
    drawPixel(x - xc, y + yc);
    drawPixel(x + xc, y - yc);
    drawPixel(x - xc, y - yc);
    drawPixel(x + yc, y + xc);
    drawPixel(x - yc, y + xc);
    drawPixel(x + yc, y - xc);
    drawPixel(x - yc, y - xc);
  }
}

void TFT::drawCircleHelper(uint16_t x, uint16_t y, uint16_t r, uint8_t cornername) {
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t xh    = 0;
  int16_t yh    = r;

  while (xh < yh) {
    if (f >= 0) {
      yh--;
      ddF_y += 2;
      f     += ddF_y;
    }
    xh++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x4) {
      drawPixel(x + xh, y + yh);
      drawPixel(x + yh, y + xh);
    }
    if (cornername & 0x2) {
      drawPixel(x + xh, y - yh);
      drawPixel(x + yh, y - xh);
    }
    if (cornername & 0x8) {
      drawPixel(x - yh, y + xh);
      drawPixel(x - xh, y + yh);
    }
    if (cornername & 0x1) {
      drawPixel(x - yh, y - xh);
      drawPixel(x - xh, y - yh);
    }
  }
}

void TFT::fillCircle(uint16_t x, uint16_t y, uint16_t r) {
  drawVLine(x, y - r, 2 * r + 1);
  fillCircleHelper(x, y, r, 3, 0);
}

void TFT::fillCircleHelper(uint16_t x, uint16_t y, uint16_t r, uint8_t cornername, uint16_t delta) {
  int16_t f     = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t xh    = 0;
  int16_t yh    = r;

  while (xh < yh) {
    if (f >= 0) {
      yh--;
      ddF_y += 2;
      f     += ddF_y;
    }
    xh++;
    ddF_x += 2;
    f     += ddF_x;
    if (cornername & 0x1) {
      drawVLine(x+xh, y-yh, 2*yh+1+delta);
      drawVLine(x+yh, y-xh, 2*xh+1+delta);
    }
    if (cornername & 0x2) {
      drawVLine(x-xh, y-yh, 2*yh+1+delta);
      drawVLine(x-yh, y-xh, 2*xh+1+delta);
    }
  }
}

void TFT::drawText(char text[], uint16_t textLength, uint16_t x, uint16_t y) {
  uint16_t wText = textLength * (fontWidth + fontSpacing);
  uint16_t hText = fontHeight;
  //const uint8_t* fontData = &kFont_Small[0][0];
  // draw Text
  cs.writeLow();
  setAddressWindow(x, y, x + wText - 1, y + hText - 1);
  rs.writeHigh();
  // row --> letter --> column
  for (uint16_t row = 0; row < hText; row++) {
    for (uint16_t letter = 0; letter < textLength; letter++) {
      // draw letter
      for (uint16_t column = 0; column < fontWidth; column++) {
        uint16_t offset = (getLetter(text[letter]) * fontHeight) + row;
        bool pixel = (*(fontData + offset) >> (fontWidth - column - 1)) & 0x01;
        if (pixel) {
          dataBus.write(foreColor);
        } else {
          dataBus.write(backColor);
        }
        wr.writeLow();
        wr.writeHigh();
      }
      // draw spacing
      dataBus.write(backColor);
      for (uint8_t i = 0; i < fontSpacing; i++) {
        wr.writeLow();
        wr.writeHigh();
      }
    }
  }
  cs.writeHigh();
}

void TFT::invertDisplay(bool invert) {
  cs.writeLow();
  if (invert) {
    writeCommand(TFT_ENTER_INVERT_MODE);
  } else {
    writeCommand(TFT_EXIT_INVERT_MODE);
  }
  cs.writeHigh();
}

void TFT::displayOn() {
  cs.writeLow();
  writeCommand(TFT_SET_DISPLAY_ON);
  cs.writeHigh();
}

void TFT::displayOff() {
  cs.writeLow();
  writeCommand(TFT_SET_DISPLAY_OFF);
  cs.writeHigh();
}
