/**
 * Private configuration file for the BMP280 library.
 * This example is configured for STM32F0, I2C, and SDO pulled down.
 */

#ifndef __BMP280_CONFIG_H__
#define __BMP280_CONFIG_H__

/* Choose a microcontroller family */

#define STM32F0
//#define STM32F1
//#define STM32F4
//#define STM32L0
//#define STM32L1
//#define STM32L4
//#define STM32F3
//#define STM32H7
//#define STM32F7
//#define STM32G0
//#define STM32C0

/* Choose a bus */

#define BMP280_USE_I2C
//#define BMP280_USE_SPI

/* I2C Configuration */

#define BMP280_I2C_PORT        hi2c1

/** 
	* You can change I2C address using SDO pin in BMP280.
	* Check your pin status to choose the right configutaion.
	* If you float SDO pin, the I2C address is undefine.
	*/

#define BMP280_I2C_SDO_PULL_DOWN
//#define BMP280_I2C_SDO_PULL_UP

#ifdef BMP280_I2C_SDO_PULL_DOWN
#define BMP280_I2C_ADDR        (0x76 << 1)
#endif

#ifdef BMP280_I2C_SDO_PULL_UP
#define BMP280_I2C_ADDR        (0x77 << 1)
#endif

/* SPI Configuration - 3 wires */

/* SPI Configuration - 4 wires */

/* Opration Mode */

//#define BMP280_OP_SLEEP_MODE
#define BMP280_OP_NORMAL_MODE
//#define BMP280_OP_FORCED_MODE

/* Oversampling setting */

//#define BMP280_OS_TEMPPERATURE_MEASUREMENT 	// p x0
//#define BMP280_OS_ULTRA_LOW_POWER 					// p x1  t x1
//#define BMP280_OS_LOW_POWER 								// p x2  t x1
#define BMP280_OS_STANDARD_RESOLUTION 			// p x4  t x1
//#define BMP280_OS_HIGH_RESOLUTION 					// p x8  t x1
//#define BMP280_OS_ULTRA_HIGH_TESOLUTION 		// p x16 t x2

#ifdef BMP280_OS_TEMPPERATURE_MEASUREMENT
#define BMP280_OS_TEMPPERATURE_MEASUREMENT_x16
//#define BMP280_OS_TEMPPERATURE_MEASUREMENT_x8
//#define BMP280_OS_TEMPPERATURE_MEASUREMENT_x4
//#define BMP280_OS_TEMPPERATURE_MEASUREMENT_x2
//#define BMP280_OS_TEMPPERATURE_MEASUREMENT_x1
#endif

/* IRR filter setting */

#define BMP280_FLITER_OFF
//#define BMP280_FLITER_ON

#ifdef BMP280_FLITER_ON
#define BMP280_FLITER_COEFF_16
//#define BMP280_FLITER_COEFF_8
//#define BMP280_FLITER_COEFF_4
//#define BMP280_FLITER_COEFF_2
#endif

/* standby time setting in normal mode */

#if defined(BMP280_OP_NORMAL_MODE)
//#define BMP280_T_SB_500U
//#define BMP280_T_SB_62500U
#define BMP280_T_SB_125M
//#define BMP280_T_SB_250M
//#define BMP280_T_SB_500M
//#define BMP280_T_SB_1000M
//#define BMP280_T_SB_2000M
//#define BMP280_T_SB_4000M
#endif

/*
	Warning:The compensation parameters can be different in sensors.
				  Be sure to check values of 0x88...0xA1 registers before any further steps.
*/
#define BMP280_CAL_PARAMS_SET

#endif // __BMP280_CONFIG_H__

