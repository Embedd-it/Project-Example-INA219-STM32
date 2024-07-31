/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_i2c.h
*
* Description: Provides data types and functions related to I2C bus
*
* Software License Agreement:
*
* This code is proprietary to Embedd Limited and may not be distributed
* or copied without the express permission of Embedd Limited. This code
* is provided "as is" without warranty of any kind, either expressed or
* implied, including but not limited to the implied warranties of
* merchantability and fitness for a particular purpose. This code is intended
* for use only within the user's organization by its employees and authorized
* agents, and may not be disclosed or used for any other purpose without
* prior written consent from Embedd Limited.
*
* Unauthorized distribution or use of this code, or any portion of it,
* including but not limited to publishing online or making it open source,
* may result in severe civil and criminal penalties, and will be prosecuted to
* the maximum extent possible under the law.
*
* ©️ 2024 Embedd Limited. All Rights Reserved.
******************************************************************************/

#ifndef _SRC_EMBEDD_I2C_H
#define _SRC_EMBEDD_I2C_H

#include "embedd_hal.h"

/*!
 *  \def   EMBEDD_I2C_ADDR_FIRST_7BIT
 *  \brief The first available 7-bit I2C address
 */
#define EMBEDD_I2C_ADDR_FIRST_7BIT 0x08

/*!
 *  \def   EMBEDD_I2C_ADDR_LAST_7BIT
 *  \brief The last available 7-bit I2C address
 */
#define EMBEDD_I2C_ADDR_LAST_7BIT 0x77

/*!
 *  \def   EMBEDD_I2C_ADDR_FIRST_10BIT
 *  \brief The first I2C address which is only available for 10-bit address range
 */
#define EMBEDD_I2C_ADDR_FIRST_10BIT 0x80

/*!
 *  \def   EMBEDD_I2C_ADDR_LAST_10BIT
 *  \brief The last I2C address which is only available for 10-bit address range
 */
#define EMBEDD_I2C_ADDR_LAST_10BIT 0x3FF

/*!
 *  \struct   embedd_i2c_dev_cfg_t
 *  \brief    conficurations related to I2C device
 *
 *  \param    addr device's address on I2C bus
 */
typedef struct embedd_i2c_dev_cfg_t {
    uint16_t addr;
} embedd_i2c_dev_cfg_t;

/*!
 *  \fn       embedd_i2c_set_dev_config
 *  \brief    writes I2C configuration into a device object
 *
 *  \param    dev    pointer to a device object which the configuration should be written to
 *  \param    config a desired I2C configuration
 *
 *  \result   EMBEDD_RESULT_OK or EMBEDD_RESULT_ERR
 */
EMBEDD_RESULT embedd_i2c_set_dev_config( const struct embedd_device_t *dev, embedd_i2c_dev_cfg_t *config );

/*!
 *  \fn       embedd_i2c_get_dev_config
 *  \brief    reads I2C configuration from the device object
 *
 *  \param    dev  pointer to a device object which the configuration should be read from
 *
 *  \result   pointer to the I2C device's configuration or NULL
 */
embedd_i2c_dev_cfg_t *embedd_i2c_get_dev_config( const struct embedd_device_t *dev );

#endif //_SRC_EMBEDD_I2C_H
