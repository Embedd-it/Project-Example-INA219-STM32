/*!
 * \file ina219_registers.c
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

#include "embedd_device.h"
#include "embedd_utils.h"
#include "embedd_hal.h"

#include "ina219_registers.h"
#include "ina219_data_types.h"

/* --------------------------------------------------------------------------
 * Power monitor register access methods
 * -------------------------------------------------------------------------- */

EMBEDD_RESULT ina219_write_reg(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay) {
    EMBEDD_RESULT result = EMBEDD_RESULT_ERR;
    if( dev == NULL || reg == NULL ) {
      return result;
    }
    if( ( dev->bus == NULL ) || ( dev->data == NULL ) ) {
      return result;
    }
    if( dev->bus->write == NULL) {
      return result;
    }
    ina219_data_t* _data = (ina219_data_t*)dev->data;
    if(_data->out_buf == NULL) {
      return result;
    }
    uint32_t msg_size = INA219_REGISTER_ADDR_SIZE + reg_size ;
    uint8_t* _out_ptr = _data->out_buf;
    embedd_pack( _out_ptr, &reg_addr, INA219_REGISTER_ADDR_SIZE );
    embedd_pack( _out_ptr + INA219_REGISTER_ADDR_SIZE, reg, reg_size );
    result = dev->bus->write( dev, _out_ptr, msg_size );
    if(result != EMBEDD_RESULT_OK) {
      return result;
    }
    embedd_hal_sleep( delay );
    return result;
}

EMBEDD_RESULT ina219_read_reg(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay) {
    EMBEDD_RESULT result = EMBEDD_RESULT_ERR;
    if( dev == NULL || reg == NULL ) {
      return result;
    }
    if( ( dev->bus == NULL ) || ( dev->data == NULL ) ) {
      return result;
    }
    if( dev->bus->write == NULL || dev->bus->read == NULL ) {
      return result;
    }
    ina219_data_t* _data = (ina219_data_t*)dev->data;
    if( _data->out_buf == NULL || _data->in_buf == NULL ) {
      return result;
    }
    uint32_t msg_size = INA219_REGISTER_ADDR_SIZE;
    uint8_t* _out_ptr = _data->out_buf;
    uint8_t* _in_ptr  = _data->in_buf;
    embedd_pack( _out_ptr, &reg_addr, INA219_REGISTER_ADDR_SIZE );
    result = dev->bus->write( dev, _out_ptr, msg_size );
    if( result != EMBEDD_RESULT_OK ) {
      return result;
    }
    embedd_hal_sleep(delay);
    result = dev->bus->read( dev, _in_ptr, reg_size );
    if( result != EMBEDD_RESULT_OK ) {
      return result;
    }
    embedd_pack( reg, _in_ptr, reg_size );
    return result;
}

