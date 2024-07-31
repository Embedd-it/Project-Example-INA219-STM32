# Description

An Embedd device driver consists of a set of files generated from a device datasheet. It allows users to access the functionality of the device.
The final archive contains two types of files: 

- Library files providing common structures, data types, etc.
- Generated files providing specific device implementation

# Get started

To get started with generated driver perform the following actions:
 1. Unzip the downloaded archive to a preferable location in your project and add them to your build system.
 2. Include the main driver's header file. It is named like **device.h**. For example: the name of this file for TMP112 looks like **tmp112.h**
```c
// ------------------------ Including header file related to the device ----------------------- //
#include  "dev.h"
```
 3. Use the Macro to create all the components of the device's object. For an I2C device this Macro looks like **DEVICE\_I2C\_DEVICE\_DEFINE**
```c
// ---------------------------------- Device object creation ---------------------------------- //
DEV_I2C_DEVICE_DEFINE(dev0, "DEV_0")
```
 4. Init device's bus object.
```c
// ------------------------------- Device's bus object creation ------------------------------- //
static EMBEDD_RESULT dev0_bus_write(const struct embedd_device_t* dev, const uint8_t* data_ptr, uint32_t data_size);
static EMBEDD_RESULT dev0_bus_read(const struct embedd_device_t* dev, uint8_t* data_ptr, uint32_t data_size);
static embedd_bus_t dev0_bus = { .write = dev0_bus_write, .read = dev0_bus_read };

// ----------------------------- Device's initialization function ------------------------------ //
EMBEDD_RESULT dev0_init()
{
    EMBEDD_RESULT res = EMBEDD_RESULT_OK;

    // device's bus initialization 
    dev0.bus = &dev0_bus;
    
    // Set device's configuration
    embedd_i2c_dev_cfg_t dev0_i2c_cfg = { .addr = I2C_ADDR_DEV0 };
    res &= embedd_i2c_set_dev_config( &dev0, &dev0_i2c_cfg );

    return res;
}

// ---------------------------- Implementation of device's bus API ---------------------------- //
EMBEDD_RESULT dev0_bus_write(const struct embedd_device_t* dev, const uint8_t* data_ptr, uint32_t data_size)
{
    if( ( data_ptr == NULL ) || ( data_size == 0 ) )
    {
        return EMBEDD_RESULT_ERR; 
    }
    embedd_i2c_dev_cfg_t * i2c_cfg = embedd_i2c_get_dev_config( dev );
    if( i2c_cfg != NULL )
    {
        return EMBEDD_RESULT_ERR;
    }
    /* USER CODE BEGIN */

    /* USER CODE END */
    return EMBEDD_RESULT_OK;
}

EMBEDD_RESULT dev0_bus_read(const struct embedd_device_t* dev, uint8_t* data_ptr, uint32_t data_size)
{
    if( ( data_ptr == NULL ) || ( data_size == 0 ) )
    {
        return EMBEDD_RESULT_ERR; 
    }
    embedd_i2c_dev_cfg_t * i2c_cfg = embedd_i2c_get_dev_config( dev );
    if( i2c_cfg != NULL )
    {
        return EMBEDD_RESULT_ERR;
    }
    /* USER CODE BEGIN */

    /* USER CODE END */
    return EMBEDD_RESULT_OK;
}
```

 5. Check all "weak" functions and add implementation if it is needed.
```c
// ----------------------- Weak functions' implementation for STM32 HAL ----------------------- //
void embedd_hal_sleep( uint32_t mseconds )
{
    /* USER CODE BEGIN */

    HAL_Delay( mseconds );

    /* USER CODE END */
}
```

## Device usage

### Registers

Registers are small storage locations that manage specific functions or data within the device. Each register has a unique address that allows it to be accessed and modified. These registers can store configuration settings, calibration data, or measurement outputs, controlling device behavior and facilitating communication between the peripheral device and the processor it's connected to. They play a crucial role in setting operational modes, initiating actions, and reading sensor data, effectively acting as the interface for the internal state and operations of the device.

The file **device\_registers.h** provides information about all the reagisters a device has.
Imagine we have an **XYZ123** device which contains a register **TEST\_BAUDRATE** storing a test baud rate configuration.
The file **xyz123\_data\_types.h** contains all the information about the type of data a register contains.
Here is the information about data type contained in **TEST\_REGISTER** register:

```c
// Test baudrate. Baudrate value for debug info
typedef int8_t xyz123_test_baudrate_t;

#define XYZ123_TEST_BAUDRATE_4K8   0
#define XYZ123_TEST_BAUDRATE_9K6   1
#define XYZ123_TEST_BAUDRATE_19K2  2
#define XYZ123_TEST_BAUDRATE_38K4  3
#define XYZ123_TEST_BAUDRATE_57K6  4
#define XYZ123_TEST_BAUDRATE_115K2 5
#define XYZ123_TEST_BAUDRATE_460K8 6
#define XYZ123_TEST_BAUDRATE_921K6 7

#define XYZ123_TEST_BAUDRATE_DEFAULT 1

#define XYZ123_TEST_BAUDRATE_VALID(val) (\
  (val) == XYZ123_TEST_BAUDRATE_4K8   ||\
  (val) == XYZ123_TEST_BAUDRATE_9K6   ||\
  (val) == XYZ123_TEST_BAUDRATE_19K2  ||\
  (val) == XYZ123_TEST_BAUDRATE_38K4  ||\
  (val) == XYZ123_TEST_BAUDRATE_57K6  ||\
  (val) == XYZ123_TEST_BAUDRATE_115K2 ||\
  (val) == XYZ123_TEST_BAUDRATE_460K8 ||\
  (val) == XYZ123_TEST_BAUDRATE_921K6 ||\
  0)
```

The file **xyz123\_registers.h** contains all the information about the registers device has.
Here is information about **TEST\_BAUDRATE** register and its declaration:

```c
// Test register
#define xyz123_test_baudrate_read_reg_addr 0x09
#define xyz123_test_baudrate_write_reg_addr 0x09
#define xyz123_test_baudrate_delay 0
typedef xyz123_test_baudrate_t xyz123_test_baudrate;
```

Here are the Macros providing an access to the device's registers:

```c
/*!
 *  \brief Write data to the register
 *  
 *  \param dev pointer to the device whose register should be written with data
 *  \param _typename register type
 *  \param var variable containing data to be written
 *  \return EMBEDD_RESULT operation result code
 */
#define XYZ123_WRITE_REG(dev, _typename, var) \
        ((xyz123_api_t*)(dev).api)->xyz123_write_reg(&(dev), \
        _typename##_write_reg_addr, &(var), sizeof(_typename), _typename##_delay)

/*!
 *  \brief Read data from the register
 *  
 *  \param dev pointer to the device from whose register data should be read
 *  \param _typename register type
 *  \param var Variable into which the data from the register will be copied
 *  \return EMBEDD_RESULT operation result code
 */
#define XYZ123_READ_REG(dev, _typename, var) \
        ((xyz123_api_t*)(dev).api)->xyz123_read_reg(&(dev), \
        _typename##_read_reg_addr, &(var), sizeof(_typename), _typename##_delay)
```

Finally, to demonstrate writing to and reading from the **TEST\_BAUDRATE** register, consider the following C code snippet:

```c
extern embedd_device_t xyz123;

bool set_test_baudrate( void ) {
    xyz123_test_baudrate_t baudrate = XYZ123_TEST_BAUDRATE_115K2;
    
    // Write the test baud rate value
    XYZ123_WRITE_REG( &xyz123, xyz123_test_baudrate, baudrate);

    // Read back the test baud rate value to verify
    xyz123_test_baudrate_t read_back_baudrate;
    XYZ123_READ_REG( &xyz123, xyz123_test_baudrate, read_back_baudrate);
    
    return (read_back_baudrate == baudrate) ? true : false;
}
```
