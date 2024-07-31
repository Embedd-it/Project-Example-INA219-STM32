/*!
 * \file ina219_registers.h
 * \brief This header file defines register addresses, types, constants and functions prototypes for the
 * Power monitor Power monitor device.
 *
 * Software License Agreement:
 * 
 * This code is proprietary to Embedd Limited and may not be distributed
 * or copied without the express permission of Embedd Limited. This code
 * is provided "as is" without warranty of any kind, either expressed or
 * implied, including but not limited to the implied warranties of
 * merchantability and fitness for a particular purpose. This code is intended
 * for use only by the employees and authorized agents of Embedd Limited
 * and its affiliates, and may not be disclosed or used for any other purpose
 * without prior written consent from Embedd Limited.
 * 
 * Unauthorized distribution or use of this code, or any portion of it, may
 * result in severe civil and criminal penalties, and will be prosecuted to
 * the maximum extent possible under the law.
 * 
 * © 2024 Embedd Limited. All Rights Reserved.
 */
#ifndef _SRC_INA219_REGISTERS_H
#define _SRC_INA219_REGISTERS_H

#include "ina219_data_types.h"

/* --------------------------------------------------------------------------
 * Registers functions prototypes
 * ------------------------------------------------------------------------*/

/*!
 * ina219_write_reg
 * 
 * \brief This function handles writing data to a specified register address within the
 * ina219 device. It constructs the appropriate message format, including the
 * register address and data, and utilizes the underlying hardware abstraction
 * layer (HAL) to perform the bus write operation.
 * 
 * \param dev pointer to embedd_device_t the structure representing the device
 * \param reg_addr uint32_t The register address to write to
 * \param reg pointer to void Pointer to the data to write
 * \param reg_size uint32_t Size of the register data in bytes
 * \param delay uint32_t delay Delay in milliseconds after the write operation
 * 
 * \return EMBEDD_RESULT EMBEDD_RESULT_OK on success, othewise EMBEDD_RESULT_ERR
 */
EMBEDD_RESULT ina219_write_reg(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay);

/*!
 * ina219_read_reg
 * 
 * \brief This function facilitates reading data from a specified register address within
 * the ina219 device. It constructs the necessary message to initiate a bus read
 * operation via the hardware abstraction layer (HAL). After reading, it unpacks the
 * received data into the provided buffer.
 * 
 * \param dev pointer to embedd_device_t the structure representing the device
 * \param reg_addr uint32_t The register address to write to
 * \param reg pointer to void Pointer to the data to write
 * \param reg_size uint32_t Size of the register data in bytes
 * \param delay uint32_t delay Delay in milliseconds after the write operation
 * 
 * \return EMBEDD_RESULT EMBEDD_RESULT_OK on success, othewise EMBEDD_RESULT_ERR
 */
EMBEDD_RESULT ina219_read_reg(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay);

/* -------------------------------------------------------------------------
 * Registers functions prototypes - END
 * ------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------
 * Registers constants
 * -------------------------------------------------------------------------- */

#define INA219_REGISTER_ADDR_SIZE (1)

/* --------------------------------------------------------------------------
 * Register name: Configuration
 * Register description: All-register reset, settings for bus voltage range, PGA Gain, ADC resolution/averaging.
 * -------------------------------------------------------------------------- */
#define ina219_configuration_read_reg_addr 0x00
#define ina219_configuration_write_reg_addr 0x00
#define ina219_configuration_delay 0
typedef ina219_configuration_t ina219_configuration;

/* --------------------------------------------------------------------------
 * Register name: Shunt Voltage
 * Register description: Stores the current shunt voltage reading, VSHUNT. Shunt Voltage register bits are shifted according to the PGA setting selected in the Configuration register (00h).
 * -------------------------------------------------------------------------- */
#define ina219_shunt_voltage_read_reg_addr 0x01
#define ina219_shunt_voltage_write_reg_addr 0x01
#define ina219_shunt_voltage_delay 0
typedef ina219_shunt_voltage_t ina219_shunt_voltage;

/* --------------------------------------------------------------------------
 * Register name: Bus voltage
 * Register description: The Bus Voltage register stores the most recent bus voltage reading, VBUS.
 * -------------------------------------------------------------------------- */
#define ina219_bus_voltage_read_reg_addr 0x02
#define ina219_bus_voltage_delay 0
typedef ina219_bus_voltage_t ina219_bus_voltage;

/* --------------------------------------------------------------------------
 * Register name: Power
 * Register description: The Power register records power in watts by multiplying the values of the current with the value of the bus voltage.
 * -------------------------------------------------------------------------- */
#define ina219_power_read_reg_addr 0x03
#define ina219_power_delay 0
typedef ina219_power_t ina219_power;

/* --------------------------------------------------------------------------
 * Register name: Current
 * Register description: Contains the value of the current flowing through the shunt resistor.
 * -------------------------------------------------------------------------- */
#define ina219_current_read_reg_addr 0x04
#define ina219_current_delay 0
typedef ina219_current_t ina219_current;

/* --------------------------------------------------------------------------
 * Register name: Calibration
 * Register description: Sets full-scale range and LSB of current and power measurements. Overall system calibration.
 * -------------------------------------------------------------------------- */
#define ina219_calibration_read_reg_addr 0x05
#define ina219_calibration_write_reg_addr 0x05
#define ina219_calibration_delay 0
typedef ina219_calibration_t ina219_calibration;


#endif//_SRC_INA219_REGISTERS_H
