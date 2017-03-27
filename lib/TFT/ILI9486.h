#pragma once

#include "mbed.h"

/* ILI9486 Commands ----------------------------------------------------------*/

#define  TFT_NOP                          0x00      //      C         0
#define  TFT_SOFT_RESET                   0x01      //      C         0
#define  TFT_GET_ID                       0x04      //      R         3
#define  TFT_GET_ERRORS                   0x05      //      R         1
#define  TFT_GET_STATUS                   0x09      //      R         4
#define  TFT_GET_POWER_MODE               0x0A      //      R         1
#define  TFT_GET_MADCTL                   0x0B      //      R         1
#define  TFT_GET_PIXEL_FORMAT             0x0C      //      R         1
#define  TFT_GET_IMAGE_MODE               0x0D      //      R         1
#define  TFT_GET_SIGNAL_MODE              0x0E      //      R         1
#define  TFT_GET_SELF_DIAGNOSTIC          0x0F      //      R         1
#define  TFT_ENTER_SLEEP_MODE             0x10      //      C         0
#define  TFT_EXIT_SLEEP_MODE              0x11      //      C         0
#define  TFT_ENTER_PARTIAL_MODE           0x12      //      C         0
#define  TFT_ENTER_NORMAL_MODE            0x13      //      C         0
#define  TFT_EXIT_INVERT_MODE             0x20      //      C         0
#define  TFT_ENTER_INVERT_MODE            0x21      //      C         0
#define  TFT_SET_DISPLAY_OFF              0x28      //      C         0
#define  TFT_SET_DISPLAY_ON               0x29      //      C         0
#define  TFT_SET_COLUMN_ADDRESS           0x2A      //      W         4
#define  TFT_SET_PAGE_ADDRESS             0x2B      //      W         4
#define  TFT_WRITE_MEMORY_START           0x2C      //      W         var
#define  TFT_READ_MEMORY_START            0x2E      //      R         var
#define  TFT_SET_PARTIAL_AREA             0x30      //      W         4
#define  TFT_SET_SCROLL_AREA              0x33      //      W         6
#define  TFT_SET_TEAR_OFF                 0x34      //      C         0
#define  TFT_SET_TEAR_ON                  0x35      //      C         0
#define  TFT_SET_ADDRESS_MODE             0x36      //      W         1
#define  TFT_SET_SCROLL_START             0x37      //      W         2
#define  TFT_EXIT_IDLE_MODE               0x38      //      C         0
#define  TFT_ENTER_IDLE_MODE              0x39      //      C         0
#define  TFT_SET_PIXEL_FORMAT             0x3A      //      W         1
#define  TFT_WRITE_MEMORY_CONTINUE        0x3C      //      W         var
#define  TFT_READ_MEMORY_CONTINUE         0x3E      //      R         var
#define  TFT_SET_TEAR_SCANLINE            0x44      //      W         2
#define  TFT_GET_TEAR_SCANLINE            0x45      //      R         2
#define  TFT_SET_DISPLAY_FUNCTION_CTRL    0xB6      //      W         3
#define  TFT_SET_POWER_CTRL_1             0xC0      //      W         2
#define  TFT_SET_POWER_CTRL_2             0xC1      //      W         2
#define  TFT_SET_POWER_CTRL_3             0xC2      //      W         1
#define  TFT_SET_POWER_CTRL_4             0xC3      //      W         1
#define  TFT_SET_POWER_CTRL_5             0xC4      //      W         1
#define  TFT_SET_VCOM_CTRL_1              0xC5      //      W         4
#define  TFT_SET_POSITIVE_GAMMA_CTRL      0xE0      //      W         15
#define  TFT_SET_NEGATIVE_GAMMA_CTRL      0xE1      //      W         15
#define  TFT_SET_DIGITAL_GAMMA_CTRL_1     0xE2      //      W         3
#define  TFT_SET_DIGITAL_GAMMA_CTRL_2     0xE3      //      W         3
