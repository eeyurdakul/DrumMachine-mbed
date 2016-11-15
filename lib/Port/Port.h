#pragma once

#include "mbed.h"
#include "Global.h"

typedef enum {
  PORT_MODE_IN      = 0x00000000,       // Input Mode
  PORT_MODE_OUT     = 0x55555555,       // Output Mode
  PORT_MODE_AF      = 0xAAAAAAAA,       // Alternate Mode
  PORT_MODE_AN      = 0xFFFFFFFF        // Analog Mode
} Port_Mode;

typedef enum {
  PORT_TYPE_PP      = 0x0000,           // Push / Pull
  PORT_TYPE_OD      = 0x5555            // Open Drain
} Port_Type;

typedef enum {
  PORT_SPEED_4MHZ   = 0x00000000,
  PORT_SPEED_25MHz  = 0x55555555,
  PORT_SPEED_50MHz  = 0xAAAAAAAA,
  PORT_SPEED_100MHz = 0xFFFFFFFF
} Port_Speed;

typedef enum {
  PORT_PULL_NO      = 0x00000000,        // No Pull
  PORT_PULL_UP      = 0x55555555,        // Pull-up
  PORT_PULL_DOWN    = 0xAAAAAAAA         // Pull-down
} Port_Pull;

class Port {
protected:
  GPIO_TypeDef* port;
  GPIO_TypeDef* getPort(PortName portName);
public:
  void setType(Port_Type type);
  void setSpeed(Port_Speed speed);
  void setPull(Port_Pull pull);
};

class Port_Out: public Port {
public:
  Port_Out(PortName portName);
  Port_Out(PortName portName, Port_Speed speed);
  ~Port_Out();
  void write(uint16_t value);
};

class Port_In: public Port {
public:
  Port_In(PortName portName);
  Port_In(PortName portName, Port_Speed speed);
  ~Port_In();
  uint16_t read();
};
