#ifndef __BMP280_H__
#define __BMP280_H__

#include "bmp280_config.h"

#if defined(STM32WB)
#include "stm32wbxx_hal.h"
#elif defined(STM32F0)
#include "stm32f0xx_hal.h"
#elif defined(STM32F1)
#include "stm32f1xx_hal.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#elif defined(STM32L0)
#include "stm32l0xx_hal.h"
#elif defined(STM32L1)
#include "stm32l1xx_hal.h"
#elif defined(STM32L4)
#include "stm32l4xx_hal.h"
#elif defined(STM32L5)
#include "stm32l5xx_hal.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#elif defined(STM32H7)
#include "stm32h7xx_hal.h"
#elif defined(STM32F7)
#include "stm32f7xx_hal.h"
#elif defined(STM32G0)
#include "stm32g0xx_hal.h"
#elif defined(STM32G4)
#include "stm32g4xx_hal.h"
#elif defined(STM32C0)
#include "stm32c0xx_hal.h"
#else
#error "SSD1306 library was tested only on STM32F0, STM32F1, STM32F3, STM32F4, STM32F7, STM32L0, STM32L1, STM32L4, STM32H7, STM32G0, STM32G4, STM32WB, STM32C0 MCU families. Please modify ssd1306.h if you know what you are doing. Also please send a pull request if it turns out the library works on other MCU's as well!"
#endif

#if defined(BMP280_USE_I2C)
extern I2C_HandleTypeDef BMP280_I2C_PORT;
#elif defined(BMP280_USE_SPI)
extern SPI_HandleTypeDef BMP280_SPI_PORT;
#else
#error "You should define BMP280_USE_SPI or BMP280_USE_I2C macro!"
#endif


#if defined (BMP280_CAL_PARAMS_SET)
#define DIG_T1 0x6A83
#define DIG_T2 0x662D
#define DIG_T3 0xFC18

#define DIG_P1 0x8B55
#define DIG_P2 0xD639
#define DIG_P3 0x0BD0
#define DIG_P4 0x0567
#define DIG_P5 0x01BE
#define DIG_P6 0xFFF9
#define DIG_P7 0x3C8C
#define DIG_P8 0xC6F8
#define DIG_P9 0x1770
#else
#error "You should define calibration parameters"
#endif

/* BMP280 Registers and Length*/

#define BMP280_REG_CHIP_ID			0xD0
#define BMP280_REG_RESET				0xE0
#define BMP280_REG_STATUS				0xF3
#define BMP280_REG_CTRL_MEAS		0xF4	
#define BMP280_REG_CONFIG				0xF5

#define BMP280_REG_PRESS_MSB		0xF7
#define BMP280_REG_PRESS_LSB		0xF8
#define BMP280_REG_PRESS_XLSB		0xF9

#define BMP280_REG_TEMP_MSB			0xFA
#define BMP280_REG_TEMP_LSB			0xFB
#define BMP280_REG_TEMP_XLSB		0xFC

#define BMP280_DATA_P_LEN				3
#define BMP280_DATA_T_LEN				3
#define BMP280_DATA_PT_LEN			6

#define BMP280_REG_DIG_T1_LSB		0x88
#define BMP280_REG_DIG_T1_MSB		0x89
#define BMP280_REG_DIG_T2_LSB		0x8A
#define BMP280_REG_DIG_T2_MSB		0x8B
#define BMP280_REG_DIG_T3_LSB		0x8C
#define BMP280_REG_DIG_T3_MSB		0x8D

#define BMP280_REG_DIG_P1_LSB		0x8E
#define BMP280_REG_DIG_P1_MSB		0x8F
#define BMP280_REG_DIG_P2_LSB		0x90
#define BMP280_REG_DIG_P2_MSB		0x91
#define BMP280_REG_DIG_P3_LSB		0x92
#define BMP280_REG_DIG_P3_MSB		0x93
#define BMP280_REG_DIG_P4_LSB		0x94
#define BMP280_REG_DIG_P4_MSB		0x95
#define BMP280_REG_DIG_P5_LSB		0x96
#define BMP280_REG_DIG_P5_MSB		0x97
#define BMP280_REG_DIG_P6_LSB		0x98
#define BMP280_REG_DIG_P6_MSB		0x99
#define BMP280_REG_DIG_P7_LSB		0x9A
#define BMP280_REG_DIG_P7_MSB		0x9B
#define BMP280_REG_DIG_P8_LSB		0x9C
#define BMP280_REG_DIG_P8_MSB		0x9D
#define BMP280_REG_DIG_P9_LSB		0x9E
#define BMP280_REG_DIG_P9_MSB		0x9F

#define BMP280_DIG_T_LEN				6
#define BMP280_DIG_P_LEN				18
#define BMP280_DIG_PT_LEN				24

/* BMP280 typedef */

#define BMP280_S32_t int32_t
#define BMP280_U32_t uint32_t

/* BMP280 Function Prototypes */

void bmp280_Reset(void);
void bmp280_Init(void);
void bmp280_WriteCommand(uint8_t reg, uint8_t data);
void bmp280_ReadSingle(uint8_t reg, uint8_t *pData);
void bmp280_ReadMuilt(uint8_t reg, uint8_t *pData, uint8_t size);

	
#endif //__BMP280_H__

