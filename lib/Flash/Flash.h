#pragma once

#include "mbed.h"
#include "Global.h"
#include "Digital.h"
#include "Port.h"

/* IS25LP128 ------------------------------------------------------------------------------------------------*/
                                                 //   Byte1       Byte2       Byte3       Byte4       Byte5
#define   FLASH_NORMAL_READ               0x03   //   A[23:16]    A[15:8]     A[7:0]      DataOut     DataOut
#define   FLASH_FAST_READ                 0x0B   //   A[23:16]    A[15:8]     A[7:0]      Dummy       DataOut
#define   FLASH_PAGE_PROGRAM              0x02   //   A[23:16]    A[15:8]     A[7:0]      DataIn      DataIn
#define   FLASH_SECTOR_ERASE_4K           0xD7   //   A[23:16]    A[15:8]     A[7:0]      -           -
#define   FLASH_BLOCK_ERASE_32K           0x52   //   A[23:16]    A[15:8]     A[7:0]      -           -
#define   FLASH_BLOCK_ERASE_64K           0xD8   //   A[23:16]    A[15:8]     A[7:0]      -           -
#define   FLASH_CHIP_ERASE                0xC7   //   -           -           -           -           -
#define   FLASH_WRITE_ENABLE              0x06   //   -           -           -           -           -
#define   FLASH_WRITE_DISABLE             0x04   //   -           -           -           -           -
#define   FLASH_READ_STATUS_REG           0x05   //   DataOut     -           -           -           -
#define   FLASH_WRITE_STATUS_REG          0x01   //   S_Reg       -           -           -           -
#define   FLASH_READ_FUNCTION_REG         0x48   //   DataOut     -           -           -           -
#define   FLASH_WRITE_FUNCTION_REG        0x42   //   F_Reg       -           -           -           -
#define   FLASH_SUSPEND_PROG_ERASE        0x75   //   -           -           -           -           -
#define   FLASH_RESUME_PROG_ERASE         0x7A   //   -           -           -           -           -
#define   FLASH_POWER_DOWN                0xB9   //   -           -           -           -           -
#define   FLASH_SET_READ_PARAMETERS       0xC0   //   DataIn      -           -           -           -
#define   FLASH_READ_MAN_DEVICE_ID        0x90   //   0x00        0x00        0x00        ManID       DevID
#define   FLASH_READ_UNIQUE_ID            0x4B   //   0x00        0x00        0x00        UniID       -
#define   FLASH_READ_JEDEC_ID             0x9F   //   ManID       ID[15:8]    ID[7:0]     -           -
#define   FLASH_SOFTWARE_RESET_ENABLE     0x66   //   -           -           -           -           -
#define   FLASH_SOFTWARE_RESET            0x99   //   -           -           -           -           -
#define   FLASH_MODE_RESET                0xFF   //   -           -           -           -           -

const uint16_t kFlashErase4KBTime   = 300;      // ms
const uint16_t kFlashErase32KBTime  = 750;      // ms
const uint16_t kFlashErase64KBTime  = 1500;     // ms
const uint32_t kFlashEraseChipTime  = 90000;    // ms
const uint16_t kWriteRegisterTime   = 15;       // ms
const uint16_t kPageProgramTime     = 1;        // ms

const uint16_t kPage4K              = 16;
const uint16_t kPage32K             = 128;
const uint16_t kPage64K             = 256;
const uint16_t kPageByteSize        = 256;
const uint16_t kPageWordSize        = 128;
const uint32_t kFlashCapacity       = 16L * 1024L * 1024L;
const uint32_t kFlashMaxPage        = 65535;
const uint32_t kFlashFrequency      = 90000000;

const char strDash[] = "------------------------\n";
const char strLine[] = "\n";

typedef enum {
  FLASH_OK            = 0x00,
  FLASH_ERROR_WRITE   = 0x01,
  FLASH_ERROR_READ    = 0x02,
  FLASH_ERROR_MAXPAGE = 0x03
} Flash_Check;

class Flash {
private:
  SPI flash;
  Digital_Out cs;
  Serial mac;
  uint8_t manID;
  uint8_t devID;
  bool checkPageIsValid(uint32_t page) const;
  void printStatus(uint8_t status);
public:
  Flash(PinName csPin, PinName mosiPin, PinName misoPin, PinName sclkPin);
  ~Flash();
  void getChipID();
  uint8_t getManID() const;
  uint8_t getDevID() const;
  void initialize();
  void writeEnable();
  void writeDisable();
  uint8_t readByte(uint32_t page, uint8_t offset);
  uint16_t readWord(uint32_t page, uint8_t offset);
  void readBytePage(uint32_t page, uint8_t* byteArray);
  void readWordPage(uint32_t page, uint16_t* wordArray);
  void writeByte(uint32_t page, uint8_t offset, uint8_t data);
  void writeWord(uint32_t page, uint8_t offset, uint16_t data);
  void writeBytePage(uint32_t page, const uint8_t* data);
  void writeWordPage(uint32_t page, const uint16_t* data);
  void writeByteArray(uint32_t startPage, const uint8_t* data, uint32_t arraySize, bool erase);
  void writeWordArray(uint32_t startPage, const uint16_t* data, uint32_t arraySize, bool erase);
  void checkByteArray(uint32_t startPage, const uint8_t* data, uint32_t arraySize);
  void checkWordArray(uint32_t startPage, const uint16_t* data, uint32_t arraySize);
  bool copyFlash(Flash& flashRef, uint32_t startPageRef, uint32_t startPageTarget, uint32_t totalPage, bool eraseTargetChip);
  void erase4KB(uint32_t page);
  void erase32KB(uint32_t page);
  void erase64KB(uint32_t page);
  void eraseChip();
};
