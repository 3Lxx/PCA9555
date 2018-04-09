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
 * Name        : PCA9555.cpp
 * Author      : LL
 * Version     :
 * Created on  : Apr 9, 2018
 *
 * Copyright © 2018 LL
 */

#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
//#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdio.h>      /* Standard I/O functions */
#include <fcntl.h>
#include <syslog.h>		/* Syslog functionallity */
#include <inttypes.h>
#include <errno.h>
#include <math.h>

#include "PCA9555.h"

//! Constructor takes bus and address arguments
/*!
 \param bus the bus to use in /dev/i2c-%d.
 \param address the device address on bus
 */
PCA9555::PCA9555(int bus, int address) {
	i2c = new I2C(bus,address);
	reset();
}

PCA9555::~PCA9555() {
	delete i2c;
}
//! Sets PCA9555 mode to all input
void PCA9555::reset() {

		i2c->write_byte(CONF_0, 0xFF); //Port 0 Input
		i2c->write_byte(CONF_1, 0xFF); //Port 1 Input

}

//! Configure a single port
/*!
 \param data bitmask for configuration (1 for Input)
 \param port port 0 or 1 to configure 
 */
void PCA9555::setConfig(uint8_t data, int port) {
	if(port == 0) i2c->write_byte(CONF_0, data);
	if(port == 1) i2c->write_byte(CONF_1, data);
}

//! Configure a single port polarity inversion
/*!
 \param data bitmask for configuration (1 for Inversion active)
 \param port port 0 or 1 to configure 
 */
void PCA9555::setPolInv(uint8_t data, int port) {
	if(port == 0) i2c->write_byte(POL_INV_0, data);
	if(port == 1) i2c->write_byte(POL_INV_1, data);
}

//! Configure a single port output
/*!
 \param data bitmask for data output
 \param port port 0 or 1 to configure 
 */
void PCA9555::setOutput(uint8_t data, int port) {
	if(port == 0) i2c->write_byte(OUTPUT_0, data);
	if(port == 1) i2c->write_byte(OUTPUT_1, data);
}
//! Get the current state of the input port
/*!
 \param port port 0 or 1 to read input from 
 */
uint8_t PCA9555::getInput(int port){
	uint8_t data = 0;
	if(port==0) data = i2c->read_byte(INPUT_0);
	if(port==1) data = i2c->read_byte(INPUT_1);

	return data;
}
