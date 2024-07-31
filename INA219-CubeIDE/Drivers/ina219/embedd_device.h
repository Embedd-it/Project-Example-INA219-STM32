/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_device.h
*
* Description: This file describes embedd device structure and provides macro
* to create such device
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

#ifndef _SRC_EMBEDD_DEV_H
#define _SRC_EMBEDD_DEV_H

#include  <stddef.h>
#include  <stdint.h>

#include  "embedd_error.h"
#include  "embedd_hal.h"

/*!
 *  \struct   embedd_dev_cfg_t
 *  \brief    Structure storing the device configurations
 *
 *  \param    bus_cfg      pointer to the bus specific configurations of the device
 */
typedef struct {
    embedd_bus_dev_cfg_t bus_cfg;
} embedd_dev_cfg_t;

/*!
 *  \struct   embedd_device_t
 *  \brief    Structure for device
 *
 *  \param    name         name of device
 *  \param    config       pointer to @embedd_dev_cfg_t structure
 *  \param    api          pointer to device api
 *  \param    fsms         pointer to state machines of device
 *  \param    data         pointer to data of device
 *  \param    event        reserved for future using
 *  \param    bus          pointer to the bus API used by the device
 */
typedef struct embedd_device_t {
    const char          *name;
    embedd_dev_cfg_t    *config;
    const void          *api;
    void                *fsms;
    void                *data;
    void                *event;
    embedd_bus_t        *bus;
} embedd_device_t;

/*!
 *  \brief  @embedd_device_t initialization Macro
 *
 *  \param    var          name of the variable containing device structure
 *  \param    _name        string containing the device name
 *  \param    _config      pointer to the device configurations
 *  \param    _api         pointer to the device API
 *  \param    _fsms        pointer to the device state machines
 *  \param    _data        pointer to the device data
 *  \param    _events      pointer to the device events
 *  \param    _bus         pointer to the bus interface
 */
#define EMBEDD_DEVICE_DEFINE_FULL(var, _name, _config, _api, _fsms, _data, _event, _bus )\
embedd_device_t var = {\
    .name       = (_name),\
    .config     = _config,\
    .api        = (void*)(_api),\
    .fsms       = (void*)(_fsms),\
    .data       = (void*)(_data),\
    .event      = (void*)_event,\
    .bus        = _bus\
};

#endif //_SRC_EMBEDD_DEV_H
