/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_hal.h
*
* Description: Provides data types and functions for hardware abstraction
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

#ifndef _SRC_EMBEDD_HAL_H
#define _SRC_EMBEDD_HAL_H

#include <stdint.h>
#include <stddef.h>
#include "embedd_error.h"

struct embedd_device_t;

/*!
 *  \typedef    embedd_bus_type_t
 *  \brief      embedd bus type such as I2C, SPI, UART, etc
 */
typedef enum {
    EMBEDD_BUS_TYPE_NA = 0,
    EMBEDD_BUS_TYPE_I2C,
    EMBEDD_BUS_TYPE_SPI
} embedd_bus_type_t;

/*!
 *  \struct     embedd_bus_dev_cfg_t
 *  \brief      conficurations related to a bus the device is on
 *
 *  \param      bus_type     type of the bus use by a device
 *  \param      configs      pointer to the device configurations
 */
typedef struct {
    uint16_t bus_type;
    void *configs;
} embedd_bus_dev_cfg_t;

/*!
 *  \struct     embedd_bus_t
 *  \brief      bus structure
 *
 *  \param      write     pointer to bus write function
 *  \param      read      pointer to bus read function
 */
typedef struct embedd_bus_t {
    EMBEDD_RESULT (*write)(const struct embedd_device_t* dev, const uint8_t* data_ptr, uint32_t data_size);
    EMBEDD_RESULT (*read) (const struct embedd_device_t* dev, uint8_t* data_ptr, uint32_t data_size);
} embedd_bus_t;

/*!
 *  \fn       embedd_hal_sleep
 *  \brief    read data to bus device
 *
 *  \param    mseconds  time in ms of sleep
 */
void embedd_hal_sleep( uint32_t mseconds );

#endif //_SRC_EMBEDD_HAL_H
