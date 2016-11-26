#pragma once

#include "mbed.h"
#include "Global.h"

typedef enum {
  DIG_MODE_IN      = 0x00,       // Input Mode
  DIG_MODE_OUT     = 0x01,       // Output Mode
  DIG_MODE_AF      = 0x02,       // Alternate Mode
  DIG_MODE_AN      = 0x03        // Analog Mode
} Digital_Mode;

typedef enum {
  DIG_TYPE_PP      = 0x00,       // Push / Pull
  DIG_TYPE_OD      = 0x01        // Open Drain
} Digital_Type;

typedef enum {
  DIG_SPEED_4MHZ   = 0x00,
  DIG_SPEED_25MHz  = 0x01,
  DIG_SPEED_50MHz  = 0x02,
  DIG_SPEED_100MHz = 0x03
} Digital_Speed;

typedef enum {
  DIG_PULL_NO      = 0x00,        // No Pull
  DIG_PULL_UP      = 0x01,        // Pull-up
  DIG_PULL_DOWN    = 0x02         // Pull-down
} Digital_Pull;

/* Digital -------------------------------------------------------------------*/

class Digital {
protected:
  GPIO_TypeDef* port;
  uint8_t pin;
  GPIO_TypeDef* getPort(PinName pinName);
  uint8_t getPin(PinName pinName);
public:
  void setType(Digital_Type type);
  void setSpeed(Digital_Speed speed);
  void setPull(Digital_Pull pull);
};

/* Digital_Out ---------------------------------------------------------------*/

class Digital_Out: public Digital {
public:
  Digital_Out(PinName pinName);
  Digital_Out(PinName pinName, Digital_Speed speed);
  ~Digital_Out();
  void writeHigh();
  void writeLow();
};

/* Digital_In ----------------------------------------------------------------*/

class Digital_In: public Digital {
public:
  Digital_In(PinName pinName);
  Digital_In(PinName pinName, Digital_Speed speed);
  ~Digital_In();
  bool read();
};
