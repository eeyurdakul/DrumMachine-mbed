#include "Flash.h"

Flash::Flash(PinName csPin, PinName mosiPin, PinName misoPin, PinName sclkPin)
: flash(mosiPin, misoPin, sclkPin)
, cs(csPin, DIG_SPEED_100MHz)
, mac(USBTX, USBRX) {}

Flash::~Flash() {}

/* Private functions ---------------------------------------------------------*/

bool Flash::checkPageIsValid(uint32_t page) const {
  bool check = false;
  if (page <= kFlashMaxPage) {
    check = true;
  }
  return check;
}

void Flash::printStatus(uint8_t status) {
  mac.printf("status      ---> ");
  switch (status) {
    case (FLASH_ERROR_MAXPAGE):
    mac.printf("maxPageExceeded\n");
    break;
    case (FLASH_ERROR_WRITE):
    mac.printf("writeError\n");
    break;
    case(FLASH_ERROR_READ):
    mac.printf("readError\n");
    break;
    case(FLASH_OK):
    mac.printf("successful\n");
    break;
    default:
    mac.printf("readError\n");
    break;
  }
}

/* Public functions ----------------------------------------------------------*/

void Flash::getChipID() {
  // read chip ID
  cs.writeLow();
  flash.write(FLASH_READ_MAN_DEVICE_ID);
  flash.write(0x00);
  flash.write(0x00);
  flash.write(0x00);
  manID = flash.write(0x00);
  devID = flash.write(0x00);
  cs.writeHigh();
  // list header
  mac.printf("chipID\n");
  mac.printf(strDash);
  // list report
  mac.printf("manID       ---> 0x%x\n", manID);
  mac.printf("devID       ---> 0x%x\n", devID);
  mac.printf(strLine);
}

uint8_t Flash::getManID() const {
  return manID;
}

uint8_t Flash::getDevID() const {
  return devID;
}

void Flash::initialize() {
  cs.writeHigh();
  flash.format(8, 0);
  flash.frequency(kFlashFrequency);
  getChipID();
}

void Flash::writeEnable() {
  cs.writeLow();
  flash.write(FLASH_WRITE_ENABLE);
  cs.writeHigh();
  wait_ms(kWriteRegisterTime);
}

void Flash::writeDisable() {
  cs.writeLow();
  flash.write(FLASH_WRITE_DISABLE);
  cs.writeHigh();
  wait_ms(kWriteRegisterTime);
}

uint8_t Flash::readByte(uint32_t page, uint8_t offset) {
  uint8_t data;
  if (checkPageIsValid(page)) {
    // calculate address
    uint32_t address = (page << 8) + offset;
    // read data
    cs.writeLow();
    flash.write(FLASH_FAST_READ);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(0x00);
    data = flash.write(0x00);
    cs.writeHigh();
  }
  return data;
}

uint16_t Flash::readWord(uint32_t page, uint8_t offset) {
  uint16_t data;
  if (checkPageIsValid(page)) {
    // calculate address
    uint32_t address = (page << 8) + offset;
    // read data
    cs.writeLow();
    flash.write(FLASH_FAST_READ);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(0x00);
    uint8_t data01 = flash.write(0x00);
    uint8_t data02 = flash.write(0x00);
    data = (data01 << 8) ^ data02;
    cs.writeHigh();
  }
  return data;
}

void Flash::readBytePage(uint32_t page, uint8_t* byteArray) {
  if (checkPageIsValid(page)) {
    // calculate address
    uint32_t address = page << 8;
    // read data
    cs.writeLow();
    flash.write(FLASH_FAST_READ);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(0x00);
    for (uint16_t i = 0; i < kPageByteSize; i++) {
      byteArray[i] = flash.write(0x00);
    }
    cs.writeHigh();
  }
}

void Flash::readWordPage(uint32_t page, uint16_t* wordArray) {
  if (checkPageIsValid(page)) {
    // calculate address
    uint32_t address = page << 8;
    // read data
    cs.writeLow();
    flash.write(FLASH_FAST_READ);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(0x00);
    for (uint16_t i = 0; i < kPageWordSize; i++) {
      uint8_t data01 = flash.write(0x00);
      uint8_t data02 = flash.write(0x00);
      wordArray[i] = (data01 << 8) ^ data02;
    }
    cs.writeHigh();
  }
}

void Flash::writeByte(uint32_t page, uint8_t offset, uint8_t data) {
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    uint32_t address = (page << 8) + offset;
    // write data
    cs.writeLow();
    flash.write(FLASH_PAGE_PROGRAM);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(data);
    cs.writeHigh();
    wait_ms(kPageProgramTime);
  }
}

void Flash::writeWord(uint32_t page, uint8_t offset, uint16_t data) {
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    uint32_t address = (page << 8) + offset;
    // write data
    cs.writeLow();
    flash.write(FLASH_PAGE_PROGRAM);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    flash.write(data >> 8);
    flash.write(data);
    cs.writeHigh();
    wait_ms(kPageProgramTime);
  }
}

void Flash::writeBytePage(uint32_t page, const uint8_t* data) {
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    uint32_t address = page << 8;
    // write data
    cs.writeLow();
    flash.write(FLASH_PAGE_PROGRAM);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    for (uint16_t i = 0; i < kPageByteSize; i++) {
      flash.write(data[i]);
    }
    cs.writeHigh();
    wait_ms(kPageProgramTime);
  }
}

void Flash::writeWordPage(uint32_t page, const uint16_t* data) {
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    uint32_t address = page << 8;
    // write data
    cs.writeLow();
    flash.write(FLASH_PAGE_PROGRAM);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    for (uint16_t i = 0; i < (kPageWordSize); i++) {
      uint8_t data01 = data[i] >> 8;
      uint8_t data02 = data[i];
      flash.write(data01);
      flash.write(data02);
    }
    cs.writeHigh();
    wait_ms(kPageProgramTime);
  }
}

void Flash::writeByteArray(uint32_t startPage, const uint8_t* data, uint32_t arraySize, bool erase) {
  uint8_t status = FLASH_ERROR_WRITE;
  uint32_t page = startPage;
  // calculate total page size
  uint32_t totalPage = arraySize / kPageByteSize;
  if (arraySize % kPageByteSize) {
    totalPage += 1;
  }
  uint32_t endPage = startPage + totalPage - 1;
  // if lower than maxPage
  if (checkPageIsValid(endPage)) {
    // erase enough memory of flash
    if (erase) {
      uint32_t eraseStartPage = (startPage / 16) * 16;
      uint32_t eraseEndPage = (endPage / 16) * 16 + 15;
      uint32_t erase64K = ((eraseEndPage + 1) - eraseStartPage) / 256;          // 64KB = 256 pages
      uint32_t erase32K = (((eraseEndPage + 1) - eraseStartPage) % 256) / 128;  // 32KB = 128 pages
      uint32_t erase4K = (((eraseEndPage + 1) - eraseStartPage) % 128) / 16;    // 4KB  = 16  pages
      // erase 64KB
      for (uint32_t i = 0; i < erase64K; i++) {
        erase64KB(eraseStartPage);
        eraseStartPage += kPage64K;
      }
      // erase 32KB
      for (uint32_t i = 0; i < erase32K; i++) {
        erase32KB(eraseStartPage);
        eraseStartPage += kPage32K;
      }
      // erase 4KB
      for (uint32_t i = 0; i < erase4K; i++) {
        erase4KB(eraseStartPage);
        eraseStartPage += kPage4K;
      }
    }
    // write byte array
    uint16_t pageDataLimit = 256;
    uint8_t pageData[256];
    uint8_t offset = 0;
    bool writeFlag = false;
    for(uint32_t j = 0; j < arraySize; j++) {
      // read case
      if (j < pageDataLimit) {
        pageData[offset] = data[j];
        if (offset < 255) {
          offset += 1;
        } else {
          writeFlag = true;
        }
      }
      // write case (last page)
      if (j == arraySize - 1) {
        writeBytePage(page, pageData);
        writeFlag = false;
        status = FLASH_OK;
      }
      // write case
      if (writeFlag) {
        writeBytePage(page, pageData);
        page += 1;
        offset = 0;
        pageDataLimit += kPageByteSize;
        writeFlag = false;
        // clear writePageData
        for (int k = 0; k < kPageByteSize; k++) {
          pageData[k] = 0;
        }
      }
    }
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("writeByteArray\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", page);
  mac.printf(strLine);
  // check byteArray
  checkByteArray(startPage, data, arraySize);
}

void Flash::writeWordArray(uint32_t startPage, const uint16_t* data, uint32_t arraySize, bool erase) {
  uint8_t status = FLASH_ERROR_WRITE;
  uint32_t page = startPage;
  // calculate total page size
  uint32_t totalPage = arraySize / kPageWordSize;
  if (arraySize % kPageWordSize) {
    totalPage += 1;
  }
  uint32_t endPage = startPage + totalPage - 1;
  // if lower than maxPage
  if (checkPageIsValid(endPage)) {
    // erase enough memory of flash
    if (erase) {
      uint32_t eraseStartPage = (startPage / 16) * 16;
      uint32_t eraseEndPage = (endPage / 16) * 16 + 15;
      uint32_t erase64K = ((eraseEndPage + 1) - eraseStartPage) / 256;          // 64KB = 256 pages
      uint32_t erase32K = (((eraseEndPage + 1) - eraseStartPage) % 256) / 128;  // 32KB = 128 pages
      uint32_t erase4K = (((eraseEndPage + 1) - eraseStartPage) % 128) / 16;    // 4KB  = 16  pages
      // erase 64KB
      for (uint32_t i = 0; i < erase64K; i++) {
        erase64KB(eraseStartPage);
        eraseStartPage += kPage64K;
      }
      // erase 32KB
      for (uint32_t i = 0; i < erase32K; i++) {
        erase32KB(eraseStartPage);
        eraseStartPage += kPage32K;
      }
      // erase 4KB
      for (uint32_t i = 0; i < erase4K; i++) {
        erase4KB(eraseStartPage);
        eraseStartPage += kPage4K;
      }
    }
    // write word array
    uint16_t pageDataLimit = 128;
    uint16_t pageData[128];
    uint8_t offset = 0;
    bool writeFlag = false;
    for (uint32_t j = 0; j < arraySize; j++) {
      // read case
      if ((j < pageDataLimit) && (offset < kPageWordSize)) {
        pageData[offset] = data[j];
        if (offset < 127) {
          offset += 1;
        } else {
          writeFlag = true;
        }
      }
      // write case (last page)
      if (j == arraySize - 1) {
        writeWordPage(page, pageData);
        writeFlag = false;
        status = FLASH_OK;
      }
      // write case
      if (writeFlag) {
        writeWordPage(page, pageData);
        page += 1;
        offset = 0;
        pageDataLimit += kPageWordSize;
        writeFlag = false;
        // clear writePageData
        for (int k = 0; k < kPageWordSize; k++) {
          pageData[k] = 0;
        }
      }
    }
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("writeWordArray\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", page);
  mac.printf(strLine);
  // check wordArray
  checkWordArray(startPage, data, arraySize);
}

void Flash::checkByteArray(uint32_t startPage, const uint8_t* data, uint32_t arraySize) {
  uint8_t status = FLASH_ERROR_READ;
  uint32_t error = 0;
  // calculate total page size
  uint32_t totalPage = arraySize / kPageByteSize;
  if (arraySize % kPageByteSize) {
    totalPage += 1;
  }
  uint32_t endPage = startPage + totalPage - 1;
  // if lower than maxPage
  if (checkPageIsValid(endPage)) {
    uint8_t flashData[256];
    for (uint32_t i = 0; i < totalPage; i++) {
      // read flash data
      readBytePage(startPage + i, flashData);
      // compare arrays
      if (i < totalPage - 1) {
        for (uint16_t j = 0; j < kPageByteSize; j++) {
          if (data[(i * kPageByteSize) + j] != flashData[j]) {
            error += 1;
          }
        }
      } else {
        // read last page
        for (uint32_t k = 0; k < arraySize % kPageByteSize; k++) {
          if (data[(i * kPageByteSize) + k] != flashData[k]) {
            error += 1;
          }
        }
      }
    }
    if (error == 0) {
      status = FLASH_OK;
    }
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("checkByteArray\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", endPage);
  mac.printf("errorCount  ---> %lu\n", error);
  mac.printf(strLine);
}

void Flash::checkWordArray(uint32_t startPage, const uint16_t* data, uint32_t arraySize) {
  uint8_t status = FLASH_ERROR_READ;
  uint32_t error = 0;
  // calculate total page size
  uint32_t totalPage = arraySize / kPageWordSize;
  if (arraySize % kPageWordSize) {
    totalPage += 1;
  }
  uint32_t endPage = startPage + totalPage - 1;
  // if lower than maxPage
  if (checkPageIsValid(endPage)) {
    uint16_t flashData[128];
    for (uint32_t i = 0; i < totalPage; i++) {
      // read flash data
      readWordPage(startPage + i, flashData);
      // compare arrays
      if (i < totalPage - 1) {
        for (uint16_t j = 0; j < kPageWordSize; j++) {
          if (data[(i * kPageWordSize) + j] != flashData[j]) {
            error += 1;
          }
        }
      } else {
        // read last page
        for (uint16_t k = 0; k < arraySize % kPageWordSize; k++) {
          if (data[(i * kPageWordSize) + k] != flashData[k]) {
            error += 1;
          }
        }
      }
    }
    if (error == 0) {
      status = FLASH_OK;
    }
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("checkWordArray\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", endPage);
  mac.printf("errorCount  ---> %lu\n", error);
  mac.printf(strLine);
}

void Flash::erase4KB(uint32_t page) {
  uint32_t startPage;
  uint32_t address;
  uint8_t status = FLASH_ERROR_WRITE;
  // check maxPage
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    startPage = (page / 16) * 16;
    address = startPage << 8;
    // erase data
    cs.writeLow();
    flash.write(FLASH_SECTOR_ERASE_4K);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    cs.writeHigh();
    wait_ms(kFlashErase4KBTime);
    status = FLASH_OK;
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("erase4KB\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", startPage + 15);
  mac.printf(strLine);
}

void Flash::erase32KB(uint32_t page) {
  uint32_t startPage;
  uint32_t address;
  uint8_t status = FLASH_ERROR_WRITE;
  // check maxPage
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    startPage = (page / 16) * 16;
    address = startPage << 8;
    // erase data
    cs.writeLow();
    flash.write(FLASH_BLOCK_ERASE_32K);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    cs.writeHigh();
    wait_ms(kFlashErase32KBTime);
    status = FLASH_OK;
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("erase32KB\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", startPage + 127);
  mac.printf(strLine);
}

void Flash::erase64KB(uint32_t page) {
  uint32_t startPage;
  uint32_t address;
  uint8_t status = FLASH_ERROR_WRITE;
  // check maxPage
  if (checkPageIsValid(page)) {
    writeEnable();
    // calculate address
    startPage = (page / 16) * 16;
    address = startPage << 8;
    // erase data
    cs.writeLow();
    flash.write(FLASH_BLOCK_ERASE_64K);
    flash.write(address >> 16);
    flash.write(address >> 8);
    flash.write(address);
    cs.writeHigh();
    wait_ms(kFlashErase64KBTime);
    status = FLASH_OK;
  } else {
    status = FLASH_ERROR_MAXPAGE;
  }
  // list header
  mac.printf("erase64KB\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf("startPage   ---> %lu\n", startPage);
  mac.printf("endPage     ---> %lu\n", startPage + 255);
  mac.printf(strLine);
}

void Flash::eraseChip() {
  uint8_t status = FLASH_ERROR_WRITE;
  // erase chip
  writeEnable();
  cs.writeLow();
  flash.write(FLASH_CHIP_ERASE);
  cs.writeHigh();
  wait(kFlashEraseChipTime);
  status = FLASH_OK;
  // list header
  mac.printf("eraseChip\n");
  mac.printf(strDash);
  // list report
  printStatus(status);
  mac.printf(strLine);
}
