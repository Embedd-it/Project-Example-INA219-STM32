/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_utils.h
*
* Description: Provides miscellaneous functions and structures
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

#ifndef EMBEDD_MISC_H__
#define EMBEDD_MISC_H__

#include  <stdint.h>
#include  <stdbool.h>
#include  <string.h>
#include  <stdlib.h>

#define   MAX(A, B) ( (A) >= (B)  ? (A) : (B) )


/*!
 * \brief Copies data from one memory location to another.
 * 
 * This function performs a byte-wise copy of data from the source (\a src) to the 
 * destination (\a dst) memory regions. The number of bytes copied is specified 
 * by the \a Size parameter.
 *
 * \param dst Pointer to the destination memory location.
 * \param src Pointer to the source memory location.
 * \param Size The number of bytes to copy.
 * 
 * \return The number of bytes copied, which should match the input \a Size 
 *         parameter.
 */
size_t  embedd_copy(void* dst, void* src, size_t Size);

/*!
 * \brief Copy data in reverse order.
 *
 * This function takes data from a source buffer, reverses its order,
 * and stores it in a destination buffer.
 *
 * \param dst Pointer to the destination buffer.
 * \param src Pointer to the source buffer.
 * \param Size The size of the data to be packed (in bytes).
 *
 * \return The size of the data that was packed.
 */
size_t  embedd_pack(void* dst, void* src, size_t Size);

/*!
 *  \struct table_t
 *  \brief  struct for common type of table data
 *
 *  \param  item_count  count of items in table
 *  \param  pItems      pointer to data of table
 */
typedef struct { 
  size_t item_count;
  void  *pItems; 
} table_t;

#define CountOfArray(val) (sizeof((val))/sizeof((val)[0]))

// ------------------------------------------------------------------------- //

#endif //EMBEDD_MISC_H__
