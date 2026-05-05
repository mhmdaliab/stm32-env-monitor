
#include "bmp280.h"
#include "stdio.h"

#if defined(BMP280_USE_I2C)

void bmp280_Reset(void) {
    bmp280_WriteCommand(BMP280_REG_RESET, 0xB6); // power-on-reset procedure
}

void bmp280_WriteCommand(uint8_t reg, uint8_t data) {
    HAL_I2C_Mem_Write(&BMP280_I2C_PORT, BMP280_I2C_ADDR, reg, 1, &data, 1, HAL_MAX_DELAY);
}

void bmp280_ReadSingle(uint8_t reg, uint8_t *pData) {
    HAL_I2C_Mem_Read(&BMP280_I2C_PORT, BMP280_I2C_ADDR, reg, 1, pData, 1, HAL_MAX_DELAY);
}

void bmp280_ReadMuilt(uint8_t reg, uint8_t *pData, uint8_t size) {
    HAL_I2C_Mem_Read(&BMP280_I2C_PORT, BMP280_I2C_ADDR, reg, 1, pData, size, HAL_MAX_DELAY);
}

#elif defined(BMP280_USE_SPI)

// to develope
void bmp280_Reset(void) {

}

void bmp280_WriteSingle(uint8_t reg, uint8_t *pData) {

}

void bmp280_WriteMulti(uint8_t reg, uint8_t *pData, uint8_t size) {

}

void bmp280_ReadSingle(uint8_t reg, uint8_t *pData) {

}

void bmp280_ReadMuilt(uint8_t reg, uint8_t *pData, uint8_t size) {

}

#else
#error "You should define SSD1306_USE_SPI or SSD1306_USE_I2C macro"
#endif


void bmp280_Init (void){
	// power-on-reset procedure start
	bmp280_Reset();
	uint8_t temp;
	
	// config register declaration
	temp = 0x0;
#if  defined(BMP280_OP_NORMAL_MODE)
	#if defined(BMP280_T_SB_500U)
	temp = temp + (0b000 << 5);
	#elif defined(BMP280_T_SB_62500U)
	temp = temp + (0b001 << 5);
	#elif defined(BMP280_T_SB_125M)
	temp = temp + (0b010 << 5);
	#elif defined(BMP280_T_SB_250M)
	temp = temp + (0b011 << 5);
	#elif defined(BMP280_T_SB_500M)
	temp = temp + (0b100 << 5);
	#elif defined(BMP280_T_SB_1000M)
	temp = temp + (0b101 << 5);
	#elif defined(BMP280_T_SB_2000M)
	temp = temp + (0b110 << 5);
	#elif defined(BMP280_T_SB_4000M)
	temp = temp + (0b111 << 5);
	#else
	#error "No standby time declared"
	#endif
#endif

// this is not decalred in datasheet, should be checked
#if  defined(BMP280_FLITER_ON)
	#if defined(BMP280_FLITER_COEFF_16)
	temp = temp + (0b000 << 2);
	#elif defined(BMP280_FLITER_COEFF_8)
	temp = temp + (0b001 << 2);
	#elif defined(BMP280_FLITER_COEFF_4)
	temp = temp + (0b010 << 2);
	#elif defined(BMP280_FLITER_COEFF_2)
	temp = temp + (0b011 << 2);
	#else
	#error "No filter coefficient declared"
	#endif
#endif

	bmp280_WriteCommand(BMP280_REG_CONFIG, temp);
	//printf("config: 0x%X\r\n", temp);

// ctrl_meas register declaration
	temp = 0x0;
#if  defined(BMP280_OP_SLEEP_MODE)
	temp = temp + (0b00 << 0);
#elif defined(BMP280_OP_FORCED_MODE)
	temp = temp + (0b01 << 0);
#elif defined(BMP280_OP_NORMAL_MODE)
	temp = temp + (0b11 << 0);
#else
#error "No mode defined"
#endif

#if defined(BMP280_OS_ULTRA_LOW_POWER)
	temp = temp + (0b001001 << 2);
#elif defined(BMP280_OS_LOW_POWER)
	temp = temp + (0b001010 << 2);
#elif defined(BMP280_OS_STANDARD_RESOLUTION)
	temp = temp + (0b001011 << 2);
#elif defined(BMP280_OS_HIGH_RESOLUTION)
	temp = temp + (0b001100 << 2);
#elif defined(BMP280_OS_ULTRA_HIGH_TESOLUTION)
	temp = temp + (0b010101 << 2);
#elif  defined(BMP280_OS_TEMPPERATURE_MEASUREMENT)
	#if defined(BMP280_OS_TEMPPERATURE_MEASUREMENT_x16)
	temp = temp + (0b101000 << 2);
	#elif defined(BMP280_OS_TEMPPERATURE_MEASUREMENT_x8)
	temp = temp + (0b100000 << 2);
	#elif defined(BMP280_OS_TEMPPERATURE_MEASUREMENT_x4)
	temp = temp + (0b011000 << 2);
	#elif defined(BMP280_OS_TEMPPERATURE_MEASUREMENT_x2)
	temp = temp + (0b010000 << 2);
	#elif defined(BMP280_OS_TEMPPERATURE_MEASUREMENT_x1)
	temp = temp + (0b001000 << 2);
	#else
	#error "No temperture oversample defined
	#endif
#else

#endif
	bmp280_WriteCommand(BMP280_REG_CTRL_MEAS, temp);
	//printf("ctrl_meas: 0x%X\r\n", temp);
}