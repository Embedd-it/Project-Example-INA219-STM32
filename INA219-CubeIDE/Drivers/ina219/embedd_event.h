/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_event.h
*
* Description: Provides an interface to the event manager
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

#ifndef _SRC_EMBEDD_EVENT_H
#define _SRC_EMBEDD_EVENT_H

#include "embedd_event_types.h"

/*!
 *  \fn     embedd_event_manager_init
 *  \brief  Initializing of event manager
 */
EMBEDD_RESULT embedd_event_manager_init();

/*!
 *  \fn     embedd_event_manager_deinit
 *  \brief  De-Initializing of event manager
 */
EMBEDD_RESULT embedd_event_manager_deinit();

/*!
 *  \fn     embedd_event_manager_register_callback
 *  \brief  register callback @cb for @id in event manager data base
 *
 *  \param  id  ID of event
 *  \param  cb  callback
 */
EMBEDD_RESULT embedd_event_manager_register_callback(  int id, embedd_callback_t cb );   

/*!
 *  \fn     embedd_event_manager_register_oneshot
 *  \brief  register oneshot callback @cb for @id in event manager data base
 *
 *  \param  id  ID of event
 *  \param  cb  callback
 */
EMBEDD_RESULT embedd_event_manager_register_oneshot(   int id, embedd_callback_t cb );

/*!
 *  \fn     embedd_event_manager_unregister_callback
 *  \brief  unregister callback @cb for @id in event manager data base
 *
 *  \param  id  ID of event
 *  \param  cb  callback
 */
EMBEDD_RESULT embedd_event_manager_unregister_callback(int id, embedd_callback_t cb );

/*!
 *  \fn     embedd_event_manager_process_events_enable
 *  \brief  enable event manager to process events in queue
 */
EMBEDD_RESULT embedd_event_manager_process_events_enable();

/*!
 *  \fn     embedd_event_manager_process_events_dsiable
 *  \brief  disable event manager to process events in queue
 */
EMBEDD_RESULT embedd_event_manager_process_events_disable();

/*!
 *  \fn     embedd_event_manager_process
 *  \brief  process events in queue by event manager
 */
EMBEDD_RESULT embedd_event_manager_process();

/*!
 *  \fn     embedd_event_manager_trigger
 *  \brief  add event to queue by event manager
 *
 *  \param  id    ID of event
 *  \param  data  data poiner, pointer to @embedd_device_t or pointer to @fsm_t
 */
EMBEDD_RESULT embedd_event_manager_trigger(int event_id, void *data);

#endif //_SRC_EMBEDD_EVENT_H
