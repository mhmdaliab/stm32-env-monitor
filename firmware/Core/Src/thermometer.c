
#include "thermometer.h"


void print_all_regs(){
	uint8_t temp;
	
	bmp280_ReadSingle(BMP280_REG_STATUS,  &temp);
	printf("BMP280_REG_STATUS 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_CTRL_MEAS,  &temp);
	printf("BMP280_REG_CTRL_MEAS 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_CONFIG,  &temp);
	printf("BMP280_REG_CONFIG 0x%02x\r\n", temp);
	/*
	bmp280_ReadSingle(BMP280_REG_PRESS_MSB,  &temp);
	printf("BMP280_REG_PRESS_MSB 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_PRESS_LSB,  &temp);
	printf("BMP280_REG_PRESS_LSB 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_PRESS_XLSB,  &temp);
	printf("BMP280_REG_PRESS_XLSB 0x%02x\r\n", temp);
	
	bmp280_ReadSingle(BMP280_REG_TEMP_MSB,  &temp);
	printf("BMP280_REG_TEMP_MSB 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_TEMP_LSB,  &temp);
	printf("BMP280_REG_TEMP_LSB 0x%02x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_TEMP_XLSB,  &temp);
	printf("BMP280_REG_TEMP_XLSB 0x%02x\r\n", temp);
	*/
	bmp280_ReadSingle(BMP280_REG_DIG_T1_MSB,  &temp);
	printf("BMP280_REG_DIG_T1_MSB 0x%x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_DIG_T1_LSB,  &temp);
	printf("BMP280_REG_DIG_T1_LSB 0x%x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_DIG_T2_MSB,  &temp);
	printf("BMP280_REG_DIG_T2_MSB 0x%x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_DIG_T2_LSB,  &temp);
	printf("BMP280_REG_DIG_T2_LSB 0x%x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_DIG_T3_MSB,  &temp);
	printf("BMP280_REG_DIG_T3_MSB 0x%x\r\n", temp);
	bmp280_ReadSingle(BMP280_REG_DIG_T3_LSB,  &temp);
	printf("BMP280_REG_DIG_T3_LSB 0x%x\r\n", temp);
	
	}


void wait_for_results() {
	uint8_t temp;
	while (1){
		bmp280_ReadSingle(BMP280_REG_STATUS, &temp);
		if ((temp & 0b1001)== 0x0)
			break;
	}
}
void run_thermometer(){
	
	uint8_t temp_data_8b;
	
	char buff[20];
	bmp280_Init();
	ssd1306_Init();
	
	while (1){
		uint8_t temp[BMP280_DATA_T_LEN] = {};
		bmp280_ReadMuilt(BMP280_REG_TEMP_MSB, temp, BMP280_DATA_T_LEN); 
		BMP280_S32_t adc_T = (temp[0]<<12)+(temp[1]<<4)+(temp[2]>>4);
		
		double var1, var2, T = 0;
		var1 = (((double)adc_T)/16384.0 - ((double)DIG_T1)/1024.0) * ((double)DIG_T2);
		var2 = ((((double)adc_T)/131072.0 - ((double)DIG_T1)/8192.0) * (((double)adc_T)/131072.0 - ((double) DIG_T1)/8192.0)) * ((double)DIG_T3);
		T = (var1 + var2) / 5120.0;
		
		bmp280_ReadMuilt(BMP280_REG_PRESS_MSB, temp, BMP280_DATA_P_LEN); 
		BMP280_S32_t adc_P = (temp[0]<<12)+(temp[1]<<4)+(temp[2]>>4);
		
		double P;
		var1 = ((double)(var1 + var2)/2.0) - 64000.0;
		var2 = var1 * var1 * ((double)DIG_P6) / 32768.0;
		var2 = var2 + var1 * ((double)DIG_P5) * 2.0;
		var2 = (var2/4.0)+(((double)DIG_P4) * 65536.0);
		var1 = (((double)DIG_P3) * var1 * var1 / 524288.0 + ((double)DIG_P2) * var1) / 524288.0;
		var1 = (1.0 + var1 / 32768.0)*((double)DIG_P1);
		if (var1 == 0.0){
			P = 0; // avoid exception caused by division by zero
		}
		P = 1048576.0 - (double)adc_P;
		P = (P - (var2 / 4096.0)) * 6250.0 / var1;
		var1 = ((double)DIG_P9) * P * P / 2147483648.0;
		var2 = P * ((double)DIG_P8) / 32768.0;
		P = P + (var1 + var2 + ((double)DIG_P7)) / 16.0;
		
		sprintf(buff, "T: %.2f C", T);
		ssd1306_SetCursor(0,3);
		ssd1306_WriteString(buff, Font_7x10, White);
		
		sprintf(buff, "P: %.2f Pa", P);
		ssd1306_SetCursor(0,19);
		ssd1306_WriteString(buff, Font_7x10, White);
		
		ssd1306_UpdateScreen();
	}
}
