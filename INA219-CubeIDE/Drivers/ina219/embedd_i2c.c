/******************************************************************************
 * Company: Embedd Limited
 *
 * File: embedd_i2c.c
 *
 * Description: Provides implementations of functions related to I2C bus
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

#include "embedd_i2c.h"

#include "embedd_device.h"

EMBEDD_RESULT embedd_i2c_set_dev_config(const struct embedd_device_t *dev, embedd_i2c_dev_cfg_t *config) {
    if (config != NULL) {
        embedd_i2c_dev_cfg_t *current_cfg = embedd_i2c_get_dev_config(dev);
        if (current_cfg != NULL) {
            current_cfg->addr = config->addr;
            return EMBEDD_RESULT_OK;
        }
    }
    return EMBEDD_RESULT_ERR;
}

embedd_i2c_dev_cfg_t *embedd_i2c_get_dev_config(const struct embedd_device_t *dev) {
    if ((dev != NULL) && (dev->config != NULL) && (dev->config->bus_cfg.bus_type == EMBEDD_BUS_TYPE_I2C)) {
        return (embedd_i2c_dev_cfg_t *)dev->config->bus_cfg.configs;
    }

    return NULL;
}
