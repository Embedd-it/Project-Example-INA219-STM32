/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_event.c
*
* Description: Provides 'weak' definitions of event interface
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

#include  "embedd_event.h"

__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_init() { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_deinit() { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_register_callback(  int id, embedd_callback_t cb ) { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_register_oneshot(   int id, embedd_callback_t cb ) { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_unregister_callback(int id, embedd_callback_t cb ) { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_process_events_enable() { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_process_events_disable() { return EMBEDD_RESULT_OK; }

__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_process() { return EMBEDD_RESULT_OK; }
__attribute__((weak)) EMBEDD_RESULT embedd_event_manager_trigger(int event_id, void *device) { return EMBEDD_RESULT_OK; }
