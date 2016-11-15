#include "Flash.h"

Flash::Flash() {
  BSP_QSPI_Init();
}

Flash::~Flash() {
  BSP_QSPI_DeInit();
}

uint8_t Flash::Init(void) {
  return BSP_QSPI_Init();
}

uint8_t Flash::DeInit(void) {
  return BSP_QSPI_DeInit();
}

uint8_t Flash::Read(uint8_t* pData, uint32_t ReadAddr, uint32_t Size) {
  return BSP_QSPI_Read(pData, ReadAddr, Size);
}

uint8_t Flash::Write(uint8_t* pData, uint32_t WriteAddr, uint32_t Size) {
  return BSP_QSPI_Write(pData, WriteAddr, Size);
}

uint8_t Flash::Erase_Block(uint32_t BlockAddress) {
  return BSP_QSPI_Erase_Block(BlockAddress);
}

uint8_t Flash::Erase_Chip(void) {
  return BSP_QSPI_Erase_Chip();
}

uint8_t Flash::GetStatus(void) {
  return BSP_QSPI_GetStatus();
}

uint8_t Flash::GetInfo(QSPI_InfoTypeDef* pInfo) {
  return BSP_QSPI_GetInfo(pInfo);
}

uint8_t Flash::EnableMemoryMappedMode(void) {
  return BSP_QSPI_MemoryMappedMode();
}
