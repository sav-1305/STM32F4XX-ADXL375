/*
 * ADXL375.h
 *
 *  Created on: Apr 8, 2024
 *      Author: Satvik Agrawal
 */

#ifndef INC_ADXL375_H_
#define INC_ADXL375_H_

#include "stm32f4xx_hal.h" /* Needed for SPI */

/*
 * DEFINES
 * 		-	REGISTER ADDRESSES "ADXL375_[]"
 * 		-	REGISTER SET VALUE "ADDRESS_[]"
 */

#define ADXL375_DEVID			0x00
/* REGISTERS 0x01 to 0x1C RESERVED */
#define ADXL375_THRESH_SHOCK	0x1D
#define ADXL375_OFFSET_X		0x1E
#define ADXL375_OFFSET_Y		0x1F
#define ADXL375_OFFSET_Z		0x20
#define ADXL375_SHOCK_DURATION	0x21
#define ADXL375_SHOCK_LATENT	0x22
#define ADXL375_SHOCK_WINDOW	0x23
#define ADXL375_ACT_THRESH		0x24
#define ADXL375_INACT_THRESH	0x25
#define ADXL375_TIME_INACT		0x26
#define ADXL375_ACT_INACT_CTL	0x27
#define ADXL375_SHOCK_AXES		0x2A
#define ADXL375_ACT_SHOCK_STAT	0x2B
#define ADXL375_BW_RATE			0x2C
#define ADXL375_POWER_CTL		0x2D
#define ADXL375_INT_ENABLE		0x2E
#define ADXL375_INT_MAP			0x2F
#define ADXL375_INT_SOURCE		0x30
#define ADXL375_DATA_FORMAT		0x31
#define ADXL375_DATAX0			0x32
#define ADXL375_DATAX1			0x33
#define ADXL375_DATAY0			0x34
#define ADXL375_DATAY1			0x35
#define ADXL375_DATAZ0			0x36
#define ADXL375_DATAZ1			0x37
#define ADXL375_FIFO_CTL		0x38
#define ADXL375_FIFO_STATUS		0x39

/* ADDRESS BITS [A5-A0]
 * DATA BITS    [D7-D0]
 * */

#define DEVID_WHOAMI			0xE5
#define POWER_CTL_MEASURE_MODE	0x08
#define BW_RATE_DATA_RATE		0x0F


/*
 * USER DEFINED STRUCT
 */

typedef struct {

	/* SPI Handle */
	SPI_HandleTypeDef *spiHandle;

	/* Raw Acceleration Data [X0, X1, Y0, Y1, Z0, Z1] */
	uint8_t rawAccData[6];

	/* Cleaned Up Acceleration Data [X, Y, Z] */
	float accData[3];

} ADXL375;

/*
 * INITIALISATION
 */

int ADXL375_Initialise(ADXL375 *dev, SPI_HandleTypeDef *spiHandle);

/*
 * DATA ACQUISITION
 */

HAL_StatusTypeDef ADXL375_ReadAcceleration(ADXL375 *dev);

void ADXL375_CleanRawValues(ADXL375 *dev);

/*
 * LOW-LEVEL FUNCTIONS
 */

HAL_StatusTypeDef WriteData(ADXL375 *dev, uint8_t address, uint8_t data, uint16_t len);

HAL_StatusTypeDef ReadData(ADXL375 *dev, uint8_t address, uint8_t *data, uint16_t len);

void ToggleCSHigh();

void ToggleCSLow();


#endif /* INC_ADXL375_H_ */
