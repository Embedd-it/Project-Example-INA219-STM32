/******************************************************************************
* Company: Embedd Limited
*
* File: embedd_utils.c
*
* Description: Implementaton of miscellaneous functions
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

#include  "embedd_utils.h"


size_t  embedd_copy(void* dst, void* src, size_t Size) {
    memcpy( dst, src, Size );
    return Size;
}

size_t embedd_pack(void* dst, void* src, size_t Size) {
    if (dst == NULL || src == NULL) {
        return 0;
    }
    if (Size == 0) {
        return 0;
    }

    const uint8_t *srcPtr = (const uint8_t *)src + Size - 1;
    uint8_t *dstPtr = (uint8_t *)dst;

    for (size_t i = 0; i < Size; ++i) {
        *dstPtr++ = *srcPtr--;
    }

    return Size;
}
