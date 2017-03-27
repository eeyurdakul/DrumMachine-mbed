#pragma once

#include "mbed.h"
#include "Global.h"
#include "Digital.h"
#include "Port.h"
#include "Font_S.h"
#include "Font_M.h"
#include "Font_L.h"
#include "ILI9486.h"

const uint16_t kTFT_WIDTH  = 320;
const uint16_t kTFT_HEIGHT = 480;

typedef enum {
  BLACK       = 0x0000,
  WHITE       = 0xFFFF,
  LGRAY       = 0x9CF3,
  MGRAY       = 0x8C51,
  DGRAY       = 0x31A6,
  BLUE        = 0x001F,
  RED         = 0xF800,
  GREEN       = 0x07E0,
  CYAN        = 0x07FF,
  MAGENTA     = 0xF81F,
  YELLOW      = 0xFFE0
} TFT_Color;

typedef enum {
  PORTRAIT_0   = 0x00,
  PORTRAIT_1   = 0x02,
  LANDSCAPE_0  = 0x01,
  LANDSCAPE_1  = 0x03
} TFT_Rotation;

typedef enum {
  FONT_S  = 0x00,
  FONT_M  = 0x01,
  FONT_L  = 0x02
} TFT_Font;

class TFT {
private:
  Port_Out dataBus;
  Digital_Out rs;
  Digital_Out wr;
  Digital_Out cs;
  Digital_Out rst;
  uint16_t width;
  uint16_t height;
  TFT_Color foreColor;
  TFT_Color backColor;
  TFT_Rotation rotation;
  TFT_Font font;
  const uint16_t* fontData;
  uint16_t fontSpacing;
  uint16_t fontWidth;
  uint16_t fontHeight;
  void writeCommand(uint8_t command);
  void writeData(uint16_t data);
  void setAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
  void clearAddressWindow();
  void fastFill(TFT_Color color, uint32_t pix);
  uint8_t getLetter(char letter);
public:
  TFT(PortName dataPort, PinName csPin, PinName rsPin, PinName wr, PinName rstPin, TFT_Rotation rotation_);
  ~TFT();
  uint16_t getWidth() const;
  uint16_t getHeight() const;
  void setForeColor(TFT_Color color);
  TFT_Color getForeColor() const;
  void setBackColor(TFT_Color color);
  TFT_Color getBackColor() const;
  void setRotation(TFT_Rotation rotation_);
  TFT_Rotation getRotation() const;
  void setFont(TFT_Font font_);
  TFT_Font getFont() const;
  void setSpacing(uint16_t spacing);
  uint16_t getSpacing() const;
  void initialize();
  void clearScreen();
  void fillScreen();
  void fillScreen(TFT_Color color);
  void drawPixel(uint16_t x, uint16_t y);
  void drawHLine(uint16_t x, uint16_t y, uint16_t l);
  void drawVLine(uint16_t x, uint16_t y, uint16_t l);
  void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
  void drawRect(uint16_t x, uint16_t y, uint32_t w, uint32_t h);
  void fillRect(uint16_t x, uint16_t y, uint32_t w, uint32_t h);
  void drawCircle(uint16_t x, uint16_t y, uint16_t r);
  void drawCircleHelper(uint16_t x, uint16_t y, uint16_t r, uint8_t cornername);
  void fillCircle(uint16_t x, uint16_t y, uint16_t r);
  void fillCircleHelper(uint16_t x, uint16_t y, uint16_t r, uint8_t cornername, uint16_t delta);
  void drawText(char text[], uint16_t textLength, uint16_t x, uint16_t y);
  void invertDisplay(bool invert);
  void displayOn();
  void displayOff();
};
