/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Name			: PCA9555.h
 * Author		: LL
 * Version		:
 * Created on 	: Apr 9, 2018
 * Note			: makes use of https://github.com/TeraHz/I2C I2C functions
 *
 * Copyright © 2018 LL
 */

#ifndef _PCA9555_H
#define _PCA9555_H
#include <inttypes.h>
#include "I2C.h"
// Register Definitions

#define INPUT_0		0x00	//Input port register 
#define INPUT_1		0x01	//Input port register
#define OUTPUT_0	0x02	//Output port register
#define OUTPUT_1	0x03	//Output port register
#define POL_INV_0	0x04	//Polarity inversion register
#define POL_INV_1	0x05    //Polarity inversion register
#define CONF_0		0x06	//Configuration register (write "1" for input, "0" for output)
#define CONF_1		0x07	//Configuration register (write "1" for input, "0" for output)

//! Main class that exports features for PCA9555 chip
class PCA9555 {
public:
	PCA9555(int,int);
	virtual ~PCA9555();

	void setConfig(uint8_t, int);
	void setPolInv(uint8_t,int);
	void setOutput(uint8_t, int);
	uint8_t getInput(int);

private:
	I2C *i2c;
	void reset(void);
};
#endif

