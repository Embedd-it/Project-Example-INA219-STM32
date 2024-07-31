/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_event_types.h
*
* Description: Provides data types related to events
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

#ifndef _SRC_EMBEDD_EVENT_TYPES_H
#define _SRC_EMBEDD_EVENT_TYPES_H

#include "embedd_device.h"

/*!
 *  \struct EventSource
 *  \brief  event source data type
 *
 *  \param  device  pointer to event data
 *  \param  id      event id
 */
struct EventSource {
    embedd_device_t *device;
    int event_id;
};

/*!
 *  \typedef  embedd_callback_t
 *  \brief    event callback data type
 */
typedef void (*embedd_callback_t)(struct EventSource*);

#define     VOID_EVENT_ID   (0)

#endif //_SRC_EMBEDD_EVENT_TYPES_H
