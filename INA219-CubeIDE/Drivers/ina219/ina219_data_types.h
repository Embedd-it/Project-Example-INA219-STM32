/*!
 * \file ina219_data_types.h
 * \brief Power monitor data types
 *
 * This file contains all the information about Power monitor specific data types.
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

#ifndef _SRC_INA219_DATA_TYPES_H
#define _SRC_INA219_DATA_TYPES_H

#include <stdint.h>
#include "embedd_device.h"
#include "embedd_hal.h"

/* --------------------------------------------------------------------------
 * DATA type
 * ------------------------------------------------------------------------*/
#pragma pack(push, 1)


/*!
 * \struct ina219_configuration_t
 * \brief All-register reset, settings for bus voltage range, PGA Gain, ADC resolution/averaging.
 *
 * \var mode Operating Mode. Selects continuous, triggered, or power-down mode of operation.
 * \var sadc SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
 * \var badc BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
 * \var pg PGA (Shunt Voltage Only). Sets PGA gain and range.
 * \var brng Bus Voltage Range. Sets the bus voltage range.
 * \var reserved Reserved field as space was unfilled
 * \var rst Reset Bit. Setting this bit to '1' generates a system reset that is the same as power-on reset. Resets all registers to default values; this bit self-clears.
 */
typedef struct {
  uint16_t mode:3;
  uint16_t sadc:4;
  uint16_t badc:4;
  uint16_t pg:2;
  uint16_t brng:1;
  uint16_t reserved:1;
  uint16_t rst:1;
} ina219_configuration_t;

/*!
 * \def INA219_CONFIGURATION_MODE_POWERDOWN
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_POWERDOWN 0

/*!
 * \def INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_TRIGGERED
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_TRIGGERED 1

/*!
 * \def INA219_CONFIGURATION_MODE_BUS_VOLTAGE_TRIGGERED
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_BUS_VOLTAGE_TRIGGERED 2

/*!
 * \def INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_TRIGGERED
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_TRIGGERED 3

/*!
 * \def INA219_CONFIGURATION_MODE_ADC_OFF_DISABLED
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_ADC_OFF_DISABLED 4

/*!
 * \def INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_CONTINUOUS
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_CONTINUOUS 5

/*!
 * \def INA219_CONFIGURATION_MODE_BUS_VOLTAGE_CONTINUOUS
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_BUS_VOLTAGE_CONTINUOUS 6

/*!
 * \def INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_CONTINUOUS
 * \brief Operating Mode. Selects continuous, triggered, or power-down mode of operation.
*/
#define INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_CONTINUOUS 7


/*!
 * \macro INA219_CONFIGURATION_MODE_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_mode type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_MODE_VALID(val) (\
  (val) == INA219_CONFIGURATION_MODE_POWERDOWN ||\
  (val) == INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_TRIGGERED ||\
  (val) == INA219_CONFIGURATION_MODE_BUS_VOLTAGE_TRIGGERED ||\
  (val) == INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_TRIGGERED ||\
  (val) == INA219_CONFIGURATION_MODE_ADC_OFF_DISABLED ||\
  (val) == INA219_CONFIGURATION_MODE_SHUNT_VOLTAGE_CONTINUOUS ||\
  (val) == INA219_CONFIGURATION_MODE_BUS_VOLTAGE_CONTINUOUS ||\
  (val) == INA219_CONFIGURATION_MODE_SHUNT_AND_BUS_CONTINUOUS ||\
  0)

/*!
 * \def INA219_CONFIGURATION_SADC_9_BIT
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_9_BIT 0

/*!
 * \def INA219_CONFIGURATION_SADC_10_BIT
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_10_BIT 1

/*!
 * \def INA219_CONFIGURATION_SADC_4_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_4_SAMPLES 10

/*!
 * \def INA219_CONFIGURATION_SADC_8_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_8_SAMPLES 11

/*!
 * \def INA219_CONFIGURATION_SADC_12_BIT_DEFAULT
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_12_BIT_DEFAULT 8

/*!
 * \def INA219_CONFIGURATION_SADC_2_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_2_SAMPLES 9

/*!
 * \def INA219_CONFIGURATION_SADC_16_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_16_SAMPLES 12

/*!
 * \def INA219_CONFIGURATION_SADC_32_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_32_SAMPLES 13

/*!
 * \def INA219_CONFIGURATION_SADC_64_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_64_SAMPLES 14

/*!
 * \def INA219_CONFIGURATION_SADC_128_SAMPLES
 * \brief SADC Shunt ADC Resolution/Averaging. These bits adjust the Shunt ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Shunt Voltage Register (01h).
*/
#define INA219_CONFIGURATION_SADC_128_SAMPLES 15


/*!
 * \macro INA219_CONFIGURATION_SADC_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_sadc type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_SADC_VALID(val) (\
  (val) == INA219_CONFIGURATION_SADC_9_BIT ||\
  (val) == INA219_CONFIGURATION_SADC_10_BIT ||\
  (val) == INA219_CONFIGURATION_SADC_4_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_8_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_12_BIT_DEFAULT ||\
  (val) == INA219_CONFIGURATION_SADC_2_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_16_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_32_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_64_SAMPLES ||\
  (val) == INA219_CONFIGURATION_SADC_128_SAMPLES ||\
  0)

/*!
 * \def INA219_CONFIGURATION_BADC_9_BIT
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_9_BIT 0

/*!
 * \def INA219_CONFIGURATION_BADC_10_BIT
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_10_BIT 1

/*!
 * \def INA219_CONFIGURATION_BADC_4_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_4_SAMPLES 10

/*!
 * \def INA219_CONFIGURATION_BADC_8_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_8_SAMPLES 11

/*!
 * \def INA219_CONFIGURATION_BADC_12_BIT_DEFAULT
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_12_BIT_DEFAULT 8

/*!
 * \def INA219_CONFIGURATION_BADC_2_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_2_SAMPLES 9

/*!
 * \def INA219_CONFIGURATION_BADC_16_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_16_SAMPLES 12

/*!
 * \def INA219_CONFIGURATION_BADC_32_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_32_SAMPLES 13

/*!
 * \def INA219_CONFIGURATION_BADC_64_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_64_SAMPLES 14

/*!
 * \def INA219_CONFIGURATION_BADC_128_SAMPLES
 * \brief BADC Bus ADC Resolution/Averaging. These bits adjust the Bus ADC resolution (9-, 10-, 11-, or 12-bit) or set the number of samples used when averaging results for the Bus Voltage Register (02h).
*/
#define INA219_CONFIGURATION_BADC_128_SAMPLES 15


/*!
 * \macro INA219_CONFIGURATION_BADC_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_badc type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_BADC_VALID(val) (\
  (val) == INA219_CONFIGURATION_BADC_9_BIT ||\
  (val) == INA219_CONFIGURATION_BADC_10_BIT ||\
  (val) == INA219_CONFIGURATION_BADC_4_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_8_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_12_BIT_DEFAULT ||\
  (val) == INA219_CONFIGURATION_BADC_2_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_16_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_32_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_64_SAMPLES ||\
  (val) == INA219_CONFIGURATION_BADC_128_SAMPLES ||\
  0)

/*!
 * \def INA219_CONFIGURATION_PG_GAIN_EQ_1_RANGE_EQ_40_MV
 * \brief PGA (Shunt Voltage Only). Sets PGA gain and range.
*/
#define INA219_CONFIGURATION_PG_GAIN_EQ_1_RANGE_EQ_40_MV 0

/*!
 * \def INA219_CONFIGURATION_PG_GAIN_EQ_2_RANGE_EQ_80_MV
 * \brief PGA (Shunt Voltage Only). Sets PGA gain and range.
*/
#define INA219_CONFIGURATION_PG_GAIN_EQ_2_RANGE_EQ_80_MV 1

/*!
 * \def INA219_CONFIGURATION_PG_GAIN_EQ_4_RANGE_EQ_160_MV
 * \brief PGA (Shunt Voltage Only). Sets PGA gain and range.
*/
#define INA219_CONFIGURATION_PG_GAIN_EQ_4_RANGE_EQ_160_MV 2

/*!
 * \def INA219_CONFIGURATION_PG_GAIN_EQ_8_RANGE_EQ_320_MV
 * \brief PGA (Shunt Voltage Only). Sets PGA gain and range.
*/
#define INA219_CONFIGURATION_PG_GAIN_EQ_8_RANGE_EQ_320_MV 3


/*!
 * \macro INA219_CONFIGURATION_PG_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_pg type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_PG_VALID(val) (\
  (val) == INA219_CONFIGURATION_PG_GAIN_EQ_1_RANGE_EQ_40_MV ||\
  (val) == INA219_CONFIGURATION_PG_GAIN_EQ_2_RANGE_EQ_80_MV ||\
  (val) == INA219_CONFIGURATION_PG_GAIN_EQ_4_RANGE_EQ_160_MV ||\
  (val) == INA219_CONFIGURATION_PG_GAIN_EQ_8_RANGE_EQ_320_MV ||\
  0)

/*!
 * \def INA219_CONFIGURATION_BRNG_EQ_16V_FSR_DEFAULT_VALUE
 * \brief Bus Voltage Range. Sets the bus voltage range.
*/
#define INA219_CONFIGURATION_BRNG_EQ_16V_FSR_DEFAULT_VALUE 0

/*!
 * \def INA219_CONFIGURATION_BRNG_EQ_32V_FSR
 * \brief Bus Voltage Range. Sets the bus voltage range.
*/
#define INA219_CONFIGURATION_BRNG_EQ_32V_FSR 1


/*!
 * \macro INA219_CONFIGURATION_BRNG_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_brng type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_BRNG_VALID(val) (\
  (val) == INA219_CONFIGURATION_BRNG_EQ_16V_FSR_DEFAULT_VALUE ||\
  (val) == INA219_CONFIGURATION_BRNG_EQ_32V_FSR ||\
  0)

/*!
 * \def INA219_CONFIGURATION_RST_NO_RESET
 * \brief Reset Bit. Setting this bit to '1' generates a system reset that is the same as power-on reset. Resets all registers to default values; this bit self-clears.
*/
#define INA219_CONFIGURATION_RST_NO_RESET 0

/*!
 * \def INA219_CONFIGURATION_RST_GENERATE_SYSTEM_RESET
 * \brief Reset Bit. Setting this bit to '1' generates a system reset that is the same as power-on reset. Resets all registers to default values; this bit self-clears.
*/
#define INA219_CONFIGURATION_RST_GENERATE_SYSTEM_RESET 1


/*!
 * \macro INA219_CONFIGURATION_RST_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_configuration_t_rst type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CONFIGURATION_RST_VALID(val) (\
  (val) == INA219_CONFIGURATION_RST_NO_RESET ||\
  (val) == INA219_CONFIGURATION_RST_GENERATE_SYSTEM_RESET ||\
  0)

/*!
 * \struct ina219_shunt_voltage_t
 * \brief Stores the current shunt voltage reading, VSHUNT. Shunt Voltage register bits are shifted according to the PGA setting selected in the Configuration register (00h).
 *
 * \var sd0 Shunt voltage data bit 0.
 * \var sd1 Shunt voltage data bit 1.
 * \var sd2 Shunt voltage data bit 2.
 * \var sd3 Shunt voltage data bit 3.
 * \var sd4 Shunt voltage data bit 4.
 * \var sd5 Shunt voltage data bit 5.
 * \var sd6 Shunt voltage data bit 6.
 * \var sd7 Shunt voltage data bit 7.
 * \var sd8 Shunt voltage data bit 8.
 * \var sd9 Shunt voltage data bit 9.
 * \var sd10 Shunt voltage data bit 10.
 * \var sd11 Shunt voltage data bit 11.
 * \var sd12 Shunt voltage data bit 12.
 * \var sd13 Shunt voltage data bit 13.
 * \var sd14 Shunt voltage data bit 14.
 * \var sign Sign bit indicating the polarity of the shunt voltage.
 */
typedef struct {
  uint16_t sd0:1;
  uint16_t sd1:1;
  uint16_t sd2:1;
  uint16_t sd3:1;
  uint16_t sd4:1;
  uint16_t sd5:1;
  uint16_t sd6:1;
  uint16_t sd7:1;
  uint16_t sd8:1;
  uint16_t sd9:1;
  uint16_t sd10:1;
  uint16_t sd11:1;
  uint16_t sd12:1;
  uint16_t sd13:1;
  uint16_t sd14:1;
  uint16_t sign:1;
} ina219_shunt_voltage_t;

/*!
 * \def INA219_SHUNT_VOLTAGE_SIGN_POSITIVE
 * \brief Sign bit indicating the polarity of the shunt voltage.
*/
#define INA219_SHUNT_VOLTAGE_SIGN_POSITIVE 0

/*!
 * \def INA219_SHUNT_VOLTAGE_SIGN_NEGATIVE
 * \brief Sign bit indicating the polarity of the shunt voltage.
*/
#define INA219_SHUNT_VOLTAGE_SIGN_NEGATIVE 1


/*!
 * \macro INA219_SHUNT_VOLTAGE_SIGN_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_shunt_voltage_t_sign type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_SHUNT_VOLTAGE_SIGN_VALID(val) (\
  (val) == INA219_SHUNT_VOLTAGE_SIGN_POSITIVE ||\
  (val) == INA219_SHUNT_VOLTAGE_SIGN_NEGATIVE ||\
  0)

/*!
 * \struct ina219_bus_voltage_t
 * \brief The Bus Voltage register stores the most recent bus voltage reading, VBUS.
 *
 * \var ovf Math Overflow Flag
 * \var cnvr Conversion Ready
 * \var reserved Reserved field as space was unfilled
 * \var bd0 Bus voltage data bit 0
 * \var bd1 Bus voltage data bit 1
 * \var bd2 Bus voltage data bit 2
 * \var bd3 Bus voltage data bit 3
 * \var bd4 Bus voltage data bit 4
 * \var bd5 Bus voltage data bit 5
 * \var bd6 Bus voltage data bit 6
 * \var bd7 Bus voltage data bit 7
 * \var bd8 Bus voltage data bit 8
 * \var bd9 Bus voltage data bit 9
 * \var bd10 Bus voltage data bit 10
 * \var bd11 Bus voltage data bit 11
 */
typedef struct {
  uint16_t ovf:1;
  uint16_t cnvr:1;
  uint16_t reserved:2;
  uint16_t bd0:1;
  uint16_t bd1:1;
  uint16_t bd2:1;
  uint16_t bd3:1;
  uint16_t bd4:1;
  uint16_t bd5:1;
  uint16_t bd6:1;
  uint16_t bd7:1;
  uint16_t bd8:1;
  uint16_t bd9:1;
  uint16_t bd10:1;
  uint16_t bd11:1;
} ina219_bus_voltage_t;

/*!
 * \def INA219_BUS_VOLTAGE_OVF_NO_OVERFLOW
 * \brief Math Overflow Flag
*/
#define INA219_BUS_VOLTAGE_OVF_NO_OVERFLOW 0

/*!
 * \def INA219_BUS_VOLTAGE_OVF_OVERFLOW_OCCURRED
 * \brief Math Overflow Flag
*/
#define INA219_BUS_VOLTAGE_OVF_OVERFLOW_OCCURRED 1


/*!
 * \macro INA219_BUS_VOLTAGE_OVF_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_bus_voltage_t_ovf type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_BUS_VOLTAGE_OVF_VALID(val) (\
  (val) == INA219_BUS_VOLTAGE_OVF_NO_OVERFLOW ||\
  (val) == INA219_BUS_VOLTAGE_OVF_OVERFLOW_OCCURRED ||\
  0)

/*!
 * \def INA219_BUS_VOLTAGE_CNVR_CONVERSION_NOT_READY
 * \brief Conversion Ready
*/
#define INA219_BUS_VOLTAGE_CNVR_CONVERSION_NOT_READY 0

/*!
 * \def INA219_BUS_VOLTAGE_CNVR_CONVERSION_READY
 * \brief Conversion Ready
*/
#define INA219_BUS_VOLTAGE_CNVR_CONVERSION_READY 1


/*!
 * \macro INA219_BUS_VOLTAGE_CNVR_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_bus_voltage_t_cnvr type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_BUS_VOLTAGE_CNVR_VALID(val) (\
  (val) == INA219_BUS_VOLTAGE_CNVR_CONVERSION_NOT_READY ||\
  (val) == INA219_BUS_VOLTAGE_CNVR_CONVERSION_READY ||\
  0)

/*!
 * \struct ina219_power_t
 * \brief The Power register records power in watts by multiplying the values of the current with the value of the bus voltage.
 *
 * \var pd0 Reserved
 * \var pd1 Reserved
 * \var pd2 Reserved
 * \var pd3 Reserved
 * \var pd4 Reserved
 * \var pd5 Reserved
 * \var pd6 Reserved
 * \var pd7 Reserved
 * \var pd8 Reserved
 * \var pd9 Reserved
 * \var pd10 Reserved
 * \var pd11 Reserved
 * \var pd12 Reserved
 * \var pd13 Reserved
 * \var pd14 Reserved
 * \var pd15 Reserved
 */
typedef struct {
  uint16_t pd0:1;
  uint16_t pd1:1;
  uint16_t pd2:1;
  uint16_t pd3:1;
  uint16_t pd4:1;
  uint16_t pd5:1;
  uint16_t pd6:1;
  uint16_t pd7:1;
  uint16_t pd8:1;
  uint16_t pd9:1;
  uint16_t pd10:1;
  uint16_t pd11:1;
  uint16_t pd12:1;
  uint16_t pd13:1;
  uint16_t pd14:1;
  uint16_t pd15:1;
} ina219_power_t;

/*!
 * \def INA219_POWER_PD0_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD0_RESERVED 0


/*!
 * \macro INA219_POWER_PD0_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd0 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD0_VALID(val) (\
  (val) == INA219_POWER_PD0_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD1_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD1_RESERVED 0


/*!
 * \macro INA219_POWER_PD1_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd1 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD1_VALID(val) (\
  (val) == INA219_POWER_PD1_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD2_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD2_RESERVED 0


/*!
 * \macro INA219_POWER_PD2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD2_VALID(val) (\
  (val) == INA219_POWER_PD2_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD3_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD3_RESERVED 0


/*!
 * \macro INA219_POWER_PD3_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd3 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD3_VALID(val) (\
  (val) == INA219_POWER_PD3_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD4_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD4_RESERVED 0


/*!
 * \macro INA219_POWER_PD4_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd4 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD4_VALID(val) (\
  (val) == INA219_POWER_PD4_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD5_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD5_RESERVED 0


/*!
 * \macro INA219_POWER_PD5_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd5 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD5_VALID(val) (\
  (val) == INA219_POWER_PD5_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD6_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD6_RESERVED 0


/*!
 * \macro INA219_POWER_PD6_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd6 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD6_VALID(val) (\
  (val) == INA219_POWER_PD6_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD7_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD7_RESERVED 0


/*!
 * \macro INA219_POWER_PD7_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd7 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD7_VALID(val) (\
  (val) == INA219_POWER_PD7_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD8_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD8_RESERVED 0


/*!
 * \macro INA219_POWER_PD8_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd8 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD8_VALID(val) (\
  (val) == INA219_POWER_PD8_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD9_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD9_RESERVED 0


/*!
 * \macro INA219_POWER_PD9_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd9 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD9_VALID(val) (\
  (val) == INA219_POWER_PD9_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD10_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD10_RESERVED 0


/*!
 * \macro INA219_POWER_PD10_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd10 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD10_VALID(val) (\
  (val) == INA219_POWER_PD10_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD11_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD11_RESERVED 0


/*!
 * \macro INA219_POWER_PD11_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd11 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD11_VALID(val) (\
  (val) == INA219_POWER_PD11_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD12_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD12_RESERVED 0


/*!
 * \macro INA219_POWER_PD12_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd12 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD12_VALID(val) (\
  (val) == INA219_POWER_PD12_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD13_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD13_RESERVED 0


/*!
 * \macro INA219_POWER_PD13_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd13 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD13_VALID(val) (\
  (val) == INA219_POWER_PD13_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD14_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD14_RESERVED 0


/*!
 * \macro INA219_POWER_PD14_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd14 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD14_VALID(val) (\
  (val) == INA219_POWER_PD14_RESERVED ||\
  0)

/*!
 * \def INA219_POWER_PD15_RESERVED
 * \brief Reserved
*/
#define INA219_POWER_PD15_RESERVED 0


/*!
 * \macro INA219_POWER_PD15_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_power_t_pd15 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_POWER_PD15_VALID(val) (\
  (val) == INA219_POWER_PD15_RESERVED ||\
  0)

/*!
 * \struct ina219_current_t
 * \brief Contains the value of the current flowing through the shunt resistor.
 *
 * \var current_value The current value in 2's complement format.
 * \var csign Sign bit for the current value. 1 indicates a negative value.
 */
typedef struct {
  uint16_t current_value:15;
  uint16_t csign:1;
} ina219_current_t;

/*!
 * \def INA219_CURRENT_CSIGN_POSITIVE_CURRENT_VALUE
 * \brief Sign bit for the current value. 1 indicates a negative value.
*/
#define INA219_CURRENT_CSIGN_POSITIVE_CURRENT_VALUE 0

/*!
 * \def INA219_CURRENT_CSIGN_NEGATIVE_CURRENT_VALUE
 * \brief Sign bit for the current value. 1 indicates a negative value.
*/
#define INA219_CURRENT_CSIGN_NEGATIVE_CURRENT_VALUE 1


/*!
 * \macro INA219_CURRENT_CSIGN_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_current_t_csign type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CURRENT_CSIGN_VALID(val) (\
  (val) == INA219_CURRENT_CSIGN_POSITIVE_CURRENT_VALUE ||\
  (val) == INA219_CURRENT_CSIGN_NEGATIVE_CURRENT_VALUE ||\
  0)

/*!
 * \struct ina219_calibration_t
 * \brief Sets full-scale range and LSB of current and power measurements. Overall system calibration.
 *
 * \var fs0 FS0 is a void bit and will always be 0. It is not possible to write a 1 to FS0.
 * \var fs1 Calibration value bit 1
 * \var fs2 Calibration value bit 2
 * \var fs3 Calibration value bit 3
 * \var fs4 Calibration value bit 4
 * \var fs5 Calibration value bit 5
 * \var fs6 Calibration value bit 6
 * \var fs7 Calibration value bit 7
 * \var fs8 Calibration value bit 8
 * \var fs9 Calibration value bit 9
 * \var fs10 Calibration value bit 10
 * \var fs11 Calibration value bit 11
 * \var fs12 Calibration value bit 12
 * \var fs13 Calibration value bit 13
 * \var fs14 Calibration value bit 14
 * \var fs15 Calibration value bit 15
 */
typedef struct {
  uint16_t fs0:1;
  uint16_t fs1:1;
  uint16_t fs2:1;
  uint16_t fs3:1;
  uint16_t fs4:1;
  uint16_t fs5:1;
  uint16_t fs6:1;
  uint16_t fs7:1;
  uint16_t fs8:1;
  uint16_t fs9:1;
  uint16_t fs10:1;
  uint16_t fs11:1;
  uint16_t fs12:1;
  uint16_t fs13:1;
  uint16_t fs14:1;
  uint16_t fs15:1;
} ina219_calibration_t;

/*!
 * \def INA219_CALIBRATION_FS0_DEFAULT_VALUE
 * \brief FS0 is a void bit and will always be 0. It is not possible to write a 1 to FS0.
*/
#define INA219_CALIBRATION_FS0_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS0_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs0 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS0_VALID(val) (\
  (val) == INA219_CALIBRATION_FS0_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS1_DEFAULT_VALUE
 * \brief Calibration value bit 1
*/
#define INA219_CALIBRATION_FS1_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS1_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs1 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS1_VALID(val) (\
  (val) == INA219_CALIBRATION_FS1_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS2_DEFAULT_VALUE
 * \brief Calibration value bit 2
*/
#define INA219_CALIBRATION_FS2_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS2_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs2 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS2_VALID(val) (\
  (val) == INA219_CALIBRATION_FS2_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS3_DEFAULT_VALUE
 * \brief Calibration value bit 3
*/
#define INA219_CALIBRATION_FS3_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS3_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs3 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS3_VALID(val) (\
  (val) == INA219_CALIBRATION_FS3_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS4_DEFAULT_VALUE
 * \brief Calibration value bit 4
*/
#define INA219_CALIBRATION_FS4_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS4_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs4 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS4_VALID(val) (\
  (val) == INA219_CALIBRATION_FS4_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS5_DEFAULT_VALUE
 * \brief Calibration value bit 5
*/
#define INA219_CALIBRATION_FS5_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS5_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs5 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS5_VALID(val) (\
  (val) == INA219_CALIBRATION_FS5_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS6_DEFAULT_VALUE
 * \brief Calibration value bit 6
*/
#define INA219_CALIBRATION_FS6_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS6_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs6 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS6_VALID(val) (\
  (val) == INA219_CALIBRATION_FS6_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS7_DEFAULT_VALUE
 * \brief Calibration value bit 7
*/
#define INA219_CALIBRATION_FS7_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS7_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs7 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS7_VALID(val) (\
  (val) == INA219_CALIBRATION_FS7_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS8_DEFAULT_VALUE
 * \brief Calibration value bit 8
*/
#define INA219_CALIBRATION_FS8_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS8_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs8 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS8_VALID(val) (\
  (val) == INA219_CALIBRATION_FS8_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS9_DEFAULT_VALUE
 * \brief Calibration value bit 9
*/
#define INA219_CALIBRATION_FS9_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS9_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs9 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS9_VALID(val) (\
  (val) == INA219_CALIBRATION_FS9_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS10_DEFAULT_VALUE
 * \brief Calibration value bit 10
*/
#define INA219_CALIBRATION_FS10_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS10_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs10 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS10_VALID(val) (\
  (val) == INA219_CALIBRATION_FS10_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS11_DEFAULT_VALUE
 * \brief Calibration value bit 11
*/
#define INA219_CALIBRATION_FS11_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS11_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs11 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS11_VALID(val) (\
  (val) == INA219_CALIBRATION_FS11_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS12_DEFAULT_VALUE
 * \brief Calibration value bit 12
*/
#define INA219_CALIBRATION_FS12_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS12_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs12 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS12_VALID(val) (\
  (val) == INA219_CALIBRATION_FS12_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS13_DEFAULT_VALUE
 * \brief Calibration value bit 13
*/
#define INA219_CALIBRATION_FS13_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS13_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs13 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS13_VALID(val) (\
  (val) == INA219_CALIBRATION_FS13_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS14_DEFAULT_VALUE
 * \brief Calibration value bit 14
*/
#define INA219_CALIBRATION_FS14_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS14_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs14 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS14_VALID(val) (\
  (val) == INA219_CALIBRATION_FS14_DEFAULT_VALUE ||\
  0)

/*!
 * \def INA219_CALIBRATION_FS15_DEFAULT_VALUE
 * \brief Calibration value bit 15
*/
#define INA219_CALIBRATION_FS15_DEFAULT_VALUE 0


/*!
 * \macro INA219_CALIBRATION_FS15_VALID(val)
 * \brief Validates if a value matches any of the predefined valid values for ina219_calibration_t_fs15 type.
 *
 * \param val The value to be validated.
 * \return True if the value matches any of the predefined valid values, false otherwise.
 */
 #define INA219_CALIBRATION_FS15_VALID(val) (\
  (val) == INA219_CALIBRATION_FS15_DEFAULT_VALUE ||\
  0)

#pragma pack(pop)
/*!
 * \def INA219_WRITE_MESSAGE_MAX_SIZE
 * \brief Max buffer size required for write operations
 */
 #define INA219_WRITE_MESSAGE_MAX_SIZE 3

/*!
 * \def INA219_READ_MESSAGE_MAX_SIZE
 * \brief Max buffer size required for read operations
 */
#define INA219_READ_MESSAGE_MAX_SIZE 3

/*!
 * \struct ina219_data_t
 * \brief Staticaly allocated data used by the device for read/write operations.
 *
 * \var in_buf    staticaly allocated buffer for input data
 * \var out_buf   staticaly allocated buffer for out data
 */
 typedef struct {
     uint8_t out_buf[INA219_WRITE_MESSAGE_MAX_SIZE];
     uint8_t in_buf[INA219_READ_MESSAGE_MAX_SIZE];
 } ina219_data_t;


/*!
 * \struct ina219_api_t
 * \brief The device's API structure containing pointers to all device's API functions
 *
 * \var ina219_write_reg contains pointer to ina219_write_reg API's function
 * \var ina219_read_reg contains pointer to ina219_read_reg API's function

 */
typedef struct {
  EMBEDD_RESULT (*ina219_write_reg)(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay);
  EMBEDD_RESULT (*ina219_read_reg)(embedd_device_t* dev, uint32_t reg_addr, void* reg, uint32_t reg_size, uint32_t delay);
} ina219_api_t;

#endif//_SRC_INA219_DATA_TYPES_H
