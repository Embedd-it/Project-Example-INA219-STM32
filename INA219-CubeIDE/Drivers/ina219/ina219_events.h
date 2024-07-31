/*
 * \file ina219_events.h
 * \brief Power monitor Events
 *
 * This file defines event IDs for Power monitor,
 * specifically the Power monitor. These ID represent various status changes
 * or general events from the device.
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
#ifndef _SRC_INA219_EVENTS_H
#define _SRC_INA219_EVENTS_H

#include <stdint.h>
#include "embedd_device.h"

enum {
/* --------------------------------------------------------------------------
 * Event name: Communication Error Event
 * Event description: Triggered by errors in I²C communication, such as acknowledgment failures or bus errors.
 * -------------------------------------------------------------------------- */
  INA219_COMMUNICATION_ERROR_EVENT_EVENT_ID = 0x9fb406c2,
};

#endif//_SRC_INA219_EVENTS_H
