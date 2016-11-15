#pragma once

#include "mbed.h"

class Flash {
public:
  Flash();
  ~Flash();
  uint8_t Init(void);
  uint8_t DeInit(void);
  uint8_t Read(uint8_t* pData, uint32_t ReadAddr, uint32_t Size);
  uint8_t Write(uint8_t* pData, uint32_t WriteAddr, uint32_t Size);
  uint8_t Erase_Block(uint32_t BlockAddress);
  uint8_t Erase_Chip(void);
  uint8_t GetStatus(void);
  uint8_t GetInfo(QSPI_InfoTypeDef* pInfo);
  uint8_t EnableMemoryMappedMode(void);
};
