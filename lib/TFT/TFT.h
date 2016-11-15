#pragma once

#include "mbed.h"
#include "Global.h"
#include "Digital.h"
#include "Port.h"
#include "Font_S.h"
#include "Font_M.h"
#include "Font_L.h"

typedef enum {                         //      type      parameter
  TFT_NOP                     = 0x00,  //      C         0
  TFT_SOFT_RESET              = 0x01,  //      C         0
  TFT_GET_RED_CHANNEL         = 0x06,  //      R         1
  TFT_GET_GREEN_CHANNEL       = 0x07,  //      R         1
  TFT_GET_BLUE_CHANNEL        = 0x08,  //      R         1
  TFT_GET_POWER_MODE          = 0x0A,  //      R         1
  TFT_GET_ADDRESS_MODE        = 0x0B,  //      R         1
  TFT_GET_PIXEL_FORMAT        = 0x0C,  //      R         1
  TFT_GET_DISPLAY_MODE        = 0x0D,  //      R         1
  TFT_GET_SIGNAL_MODE         = 0x0E,  //      R         1
  TFT_GET_DIAGNOSTIC_RESULT   = 0x0F,  //      R         1
  TFT_ENTER_SLEEP_MODE        = 0x10,  //      C         0
  TFT_EXIT_SLEEP_MODE         = 0x11,  //      C         0
  TFT_ENTER_PARTIAL_MODE      = 0x12,  //      C         0
  TFT_ENTER_NORMAL_MODE       = 0x13,  //      C         0
  TFT_EXIT_INVERT_MODE        = 0x20,  //      C         0
  TFT_ENTER_INVERT_MODE       = 0x21,  //      C         0
  TFT_SET_GAMMA_CURVE         = 0x26,  //      W         1
  TFT_SET_DISPLAY_OFF         = 0x28,  //      C         0
  TFT_SET_DISPLAY_ON          = 0x29,  //      C         0
  TFT_SET_COLUMN_ADDRESS      = 0x2A,  //      W         4
  TFT_SET_PAGE_ADDRESS        = 0x2B,  //      W         4
  TFT_WRITE_MEMORY_START      = 0x2C,  //      W         variable
  TFT_WITE_LUT                = 0x2D,  //      W         variable
  TFT_READ_MEMORY_START       = 0x2E,  //      R         variable
  TFT_SET_PARTIAL_AREA        = 0x30,  //      W         4
  TFT_SET_SCROLL_AREA         = 0x33,  //      W         6
  TFT_SET_TEAR_OFF            = 0x34,  //      C         0
  TFT_SET_TEAR_ON             = 0x35,  //      W         1
  TFT_SET_ADDRESS_MODE        = 0x36,  //      W         1
  TFT_SET_SCROLL_START        = 0x37,  //      W         2
  TFT_EXIT_IDLE_MODE          = 0x38,  //      C         0
  TFT_ENTER_IDLE_MODE         = 0x39,  //      C         0
  TFT_SET_PIXEL_FORMAT        = 0x3A,  //      W         1
  TFT_WRITE_MEMORY_CONTINUE   = 0x3C,  //      W         variable
  TFT_READ_MEMORY_CONTINUE    = 0x3E,  //      R         variable
  TFT_SET_TEAR_SCANLINE       = 0x44,  //      W         2
  TFT_GET_SCANLINE            = 0x45,  //      R         2
  TFT_READ_DDB_START          = 0xA1,  //      R         5
  TFT_READ_DDB_CONTINUE       = 0xA8,  //      R         variable
  TFT_COMMAND_ACCESS_PROTECT  = 0xB0,  //      W/R       1
  TFT_LOW_POWER_MODE_CONTROL  = 0xB1,  //      W/R       1
  TFT_FMA_SETTING             = 0xB3,  //      W/R       5
  TFT_FMW_SETTING             = 0xB4,  //      W/R       1
  TFT_DEVICE_CODE_READ        = 0xBF,  //      R         4
  TFT_PANEL_DRIVING_SETTING   = 0xC0,  //      W/R       7
  TFT_DISPLAY_TIMING_NORMAL   = 0xC1,  //      W/R       3
  TFT_DISPLAY_TIMING_PARTIAL  = 0xC2,  //      W/R       3
  TFT_DISPLAY_TIMING_IDLE     = 0xC3,  //      W/R       3
  TFT_FRAME_RATE              = 0xC5,  //      W/R       1
  TFT_INTERFACE_CONTROL       = 0xC6,  //      W/R       1
  TFT_GAMMA_SETTING           = 0xC8,  //      W/R       12
  TFT_POWER_SETTING           = 0xD0,  //      W/R       3
  TFT_VCOM_CONTROL            = 0xD1,  //      W/R       3
  TFT_POWER_SETTING_NORMAL    = 0xD2,  //      W/R       2
  TFT_POWER_SETTING_PARTIAL   = 0xD3,  //      W/R       2
  TFT_POWER_SETTING_IDLE      = 0xD4,  //      W/R       2
  TFT_NV_MEMORY_WRITE         = 0xE0,  //      W/R       1
  TFT_NV_MEMORY_CONTROL       = 0xE1,  //      W/R       1
  TFT_NV_MEMORY_STATUS        = 0xE2,  //      W/R       3
  TFT_NV_MEMORY_PROTECTION    = 0xE3,  //      W/R       2
  TFT_EEPROM_WRITE_ENABLE     = 0xE8,  //      C         0
  TFT_EEPROM_WRITE_DISABLE    = 0xE9,  //      C         0
  TFT_EEPROM_WORD_WRITE       = 0xEA,  //      W/R       2
  TFT_EEPROM_WORD_READ        = 0xEB,  //      R         3
  TFT_EEPROM_ADDRESS_SET      = 0xEC,  //      W/R       1
  TFT_EEPROM_ERASE            = 0xED,  //      W/R       1
  TFT_EEPROM_ERASE_ALL        = 0xEE,  //      C         0
  TFT_LSI_TEST_REGISTERS      = 0xFF  //      W/R       variable
} TFT_Command;

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

const uint16_t kTFT_WIDTH  = 320;
const uint16_t kTFT_HEIGHT = 480;

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
  void writeCommand(TFT_Command command);
  void writeData(uint16_t data);
  void setAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
  void clearAddressWindow();
  void fastFill(TFT_Color color, uint32_t pix);
  uint8_t getLetter(char letter);
public:
  TFT(PortName dataPort, PinName rsPin, PinName wrPin, PinName csPin, PinName rstPin, TFT_Rotation rotation_);
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
