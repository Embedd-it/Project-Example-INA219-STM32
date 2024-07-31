/*!
 * \file ina219.c
 * \brief Power monitor
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

#include "ina219.h"

const ina219_api_t ina219_api = {
  .ina219_write_reg = &ina219_write_reg,
  .ina219_read_reg = &ina219_read_reg,
};
