/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_error.h
*
* Description: Provides the possible EMBEDD_RESULT codes
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

#ifndef _SRC_EMBEDD_ERROR_H
#define _SRC_EMBEDD_ERROR_H

/*!
 *  \typedef  EMBEDD_RESULT
 *  \brief    Type for errors
 */
typedef enum {
  EMBEDD_RESULT_OK  =0,
  EMBEDD_RESULT_ERR =(!EMBEDD_RESULT_OK),
} EMBEDD_RESULT;

#endif //_SRC_EMBEDD_ERROR_H
