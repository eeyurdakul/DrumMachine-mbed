#include "Digital.h"

// Digital methods

GPIO_TypeDef* Digital::getPort(PinName pinName) {
  switch (pinName / 16) {
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

uint8_t Digital::getPin(PinName pinName) {
  return (pinName % 16);
}

void Digital::setType(Digital_Type type) {
  port->OTYPER |= type << pin;
}

void Digital::setSpeed(Digital_Speed speed) {
  port->OSPEEDR |= speed << (pin * 2);
}

void Digital::setPull(Digital_Pull pull) {
  port->PUPDR |= pull << (pin * 2);
}

// Digital_Out methods

Digital_Out::Digital_Out(PinName pinName) {
  DigitalOut dPin(pinName);
  port = getPort(pinName);
  pin = getPin(pinName);
}

Digital_Out::Digital_Out(PinName pinName, Digital_Speed speed) {
  DigitalOut dPin(pinName);
  port = getPort(pinName);
  pin = getPin(pinName);
  setSpeed(speed);
}

Digital_Out::~Digital_Out() {}

void Digital_Out::writeHigh() {
  port->BSRR = (1 << pin);
}

void Digital_Out::writeLow() {
  port->BSRR = (1 << (pin + 16));
}

// Digital_In methods

Digital_In::Digital_In(PinName pinName) {
  DigitalIn dPin(pinName);
  port = getPort(pinName);
  pin = getPin(pinName);
}

Digital_In::Digital_In(PinName pinName, Digital_Speed speed) {
  DigitalIn dPin(pinName);
  port = getPort(pinName);
  pin = getPin(pinName);
  setSpeed(speed);
}

Digital_In::~Digital_In() {}

bool Digital_In::read() {
  return ((port->IDR & ~(1 << pin)) >> pin);
}
