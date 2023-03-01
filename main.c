#include <stdint.h>
#include "mpu6050.h"
#include "stm32f10x.h"                  // Device header
#include "i2c.h"

#define RCC_PORTB	(1UL<<3)  	//ENABLE rcc portb
#define PIN0			(1UL<<0)
#define LED				(PIN0)



static int16_t ax, ay, az, gx ,gy, gz, t;
static float acc_x, acc_y, acc_z, temperature, gyro_x, gyro_y, gyro_z;
extern char sensors_data[14];

int main(void){
	
	while(1){
		mpu_init();
		mpu_read_values(DATA_START_R);
		ax = ((int16_t)sensors_data[0]<<8)  | (int16_t)sensors_data[1];
		ay = ((int16_t)sensors_data[2]<<8)  | (int16_t)sensors_data[3];
		az = ((int16_t)sensors_data[4]<<8)  | (int16_t)sensors_data[5];
		t  = ((int16_t)sensors_data[6]<<8)  | (int16_t)sensors_data[7];
		gx = ((int16_t)sensors_data[8]<<8)  | (int16_t)sensors_data[9];
		gy = ((int16_t)sensors_data[10]<<8) | (int16_t)sensors_data[11];
		gz = ((int16_t)sensors_data[12]<<8) | (int16_t)sensors_data[13];
		temperature = t/340 + 36.53f;
		acc_x = (float)ax/8192;
		acc_y = (float)ay/8192;
		acc_z = (float)az/8192;
		gyro_x = (float)gx/65.5f;
		gyro_y = (float)gy/65.5f;
		gyro_z = (float)gz/65.5f;
	}	
}
