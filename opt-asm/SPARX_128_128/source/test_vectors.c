/*
 * SPARX reference source code package
 *
 * Copyright (C) 2016, 2017 CryptoLUX (https://www.cryptolux.org)
 *
 * Written by Daniel Dinu <dumitru-daniel.dinu@uni.lu>
 *
 * You may use this work under the terms of a Creative Commons CC0 1.0 
 * License/Waiver or the Apache Public License 2.0, at your option. The terms of
 * these licenses can be found at:
 *
 * - CC0 1.0 Universal : http://creativecommons.org/publicdomain/zero/1.0
 * - Apache 2.0        : http://www.apache.org/licenses/LICENSE-2.0
 *
 * You should have received a copy of both of these licenses along with this
 * software. If not, they may be obtained at the above URLs.
 */

#include <stdint.h>

#include "test_vectors.h"


/*
 *
 * Test vectors
 *
 */
//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x78, 0xd9, 0xe4, 0xd4, 0xc8, 0x19, 0x16, 0x8b, 0xdc, 0x4b, 0x77, 0x39, 0x28, 0xf6, 0xad, 0xa8};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedKey[KEY_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0xfb, 0xee, 0x91, 0xe2, 0x72, 0x4e, 0xd9, 0xf5, 0x6c, 0xe9, 0xe5, 0xfd, 0xb7, 0x46, 0x22, 0xb6};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x6c, 0x03, 0x66, 0xb5, 0x7a, 0xd2, 0x78, 0x67, 0x46, 0x4d, 0xff, 0x40, 0xa3, 0x9c, 0xfe, 0x60};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedKey[KEY_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x25, 0xcd, 0x60, 0x2b, 0x18, 0xba, 0x63, 0xad, 0x48, 0x76, 0x96, 0xf8, 0x08, 0x4c, 0xcc, 0xd3};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x99, 0xfc, 0xc9, 0x61, 0x91, 0xaa, 0xcb, 0x46, 0x93, 0x53, 0x17, 0x25, 0x58, 0xa5, 0x6a, 0x6e};

/* paper */
const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x23, 0x01, 0x67, 0x45, 0xab, 0x89, 0xef, 0xcd, 0xdc, 0xfe, 0x98, 0xba, 0x54, 0x76, 0x10, 0x32};
const uint8_t expectedKey[KEY_SIZE] = {0x11, 0x00, 0x33, 0x22, 0x55, 0x44, 0x77, 0x66, 0x99, 0x88, 0xbb, 0xaa, 0xdd, 0xcc, 0xff, 0xee};
const uint8_t expectedCiphertext[BLOCK_SIZE] = {0xee, 0x1c, 0x40, 0x75, 0xbf, 0x7d, 0xd8, 0x23, 0xee, 0xe0, 0x97, 0x15, 0x28, 0xf4, 0xd8, 0x52};
