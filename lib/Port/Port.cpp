#include "Port.h"

/* Port functions ------------------------------------------------------------*/

GPIO_TypeDef* Port::getPort(PortName portName) {
  switch (portName) {
    case 0:
    return GPIOA;
    break;
    case 1:
    return GPIOB;
    break;
    case 2:
    return GPIOC;
    break;
    case 3:
    return GPIOD;
    break;
    case 4:
    return GPIOE;
    break;
    case 5:
    return GPIOF;
    break;
    case 6:
    return GPIOG;
    break;
    case 7:
    return GPIOH;
    break;
    default:
    return GPIOA;
    break;
  }
}

void Port::setType(Port_Type type) {
  port->OTYPER = type;
}

void Port::setSpeed(Port_Speed speed) {
  port->OSPEEDR = speed;
}

void Port::setPull(Port_Pull pull) {
  port->PUPDR = pull;
}

/* Port_Out functions --------------------------------------------------------*/

Port_Out::Port_Out(PortName portName) {
  PortOut dPort(portName);
  port = getPort(portName);
}

Port_Out::Port_Out(PortName portName, Port_Speed speed) {
  PortOut dPort(portName);
  port = getPort(portName);
  setSpeed(speed);
}

Port_Out::~Port_Out() {}

void Port_Out::write(uint16_t value) {
  port->ODR = value;
}

/* Port_In functions ---------------------------------------------------------*/

Port_In::Port_In(PortName portName) {
  PortIn dPort(portName);
  port = getPort(portName);
}

Port_In::Port_In(PortName portName, Port_Speed speed) {
  PortIn dPort(portName);
  port = getPort(portName);
  setSpeed(speed);
}

Port_In::~Port_In() {}

uint16_t Port_In::read() {
  return (port->IDR);
}
