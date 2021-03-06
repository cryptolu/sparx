/*
 * SPARX source code package
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

#ifndef ARM_MACROS_H
#define ARM_MACROS_H


#include "stringify.h"


#define HALFWORD_MASK #0x0000ffff

#define CV2 #2
#define CV7 #7
#define CV8 #8
#define CV9 #9
#define CV14 #14
#define CV16 #16
#define CV24 #24


#define SET_MASK_(mask)           \
    ldr mask, =HALFWORD_MASK \n\t


#define EKS_STORE_ROUND_KEYS_(k0, k1, k2) \
    stm r1!, {k0, k1, k2}            \n\t


#define EKS_ROUND_KEYS_(k0, k1, k2, k3, t0, t1, t2, t3, mask, c) \
    and t0, mask, k3                                        \n\t \
    and t1, mask, k3, lsr CV16                              \n\t \
    add t1, c                                               \n\t \
    and t1, t1, mask                                        \n\t \
                                                                 \
                                                                 \
    mov k3, k2                                              \n\t \
                                                                 \
                                                                 \
    and t2, mask, k0                                        \n\t \
    and t3, mask, k0, lsr CV16                              \n\t \
                                                                 \
    lsr k2, t2, CV7                                         \n\t \
    orr t2, k2, t2, lsl CV9                                 \n\t \
    add t2, t2, t3                                          \n\t \
                                                                 \
    lsr k2, t3, CV14                                        \n\t \
    orr t3, k2, t3, lsl CV2                                 \n\t \
    eor t3, t2, t3                                          \n\t \
                                                                 \
    and t2, t2, mask                                        \n\t \
    and t3, t3, mask                                        \n\t \
                                                                 \
                                                                 \
    orr k0, t0, t1, lsl CV16                                \n\t \
                                                                 \
                                                                 \
    and t0, mask, k1                                        \n\t \
    and t1, mask, k1, lsr CV16                              \n\t \
                                                                 \
                                                                 \
    add t0, t0, t2                                          \n\t \
    and t0, mask, t0                                        \n\t \
                                                                 \
    add t1, t1, t3                                          \n\t \
    and t1, mask, t1                                        \n\t \
                                                                 \
                                                                 \
    orr k1, t2, t3, lsl CV16                                \n\t \
                                                                 \
                                                                 \
    orr k2, t0, t1, lsl CV16                                \n\t



#define EKS_WHITENING_KEYS_(k0, k1, k2, k3, t0, t1, mask, c) \
    and t0, mask, k0                                    \n\t \
    and t1, mask, k0, lsr CV16                          \n\t \
                                                             \
    lsr k2, t0, CV7                                     \n\t \
    orr t0, k2, t0, lsl CV9                             \n\t \
    add t0, t0, t1                                      \n\t \
                                                             \
    lsr k2, t1, CV14                                    \n\t \
    orr t1, k2, t1, lsl CV2                             \n\t \
    eor t1, t0, t1                                      \n\t \
                                                             \
    and t0, t0, mask                                    \n\t \
    and t1, t1, mask                                    \n\t \
                                                             \
    orr k1, t0, t1, lsl CV16                            \n\t \
                                                             \
    and t0, mask, k3                                    \n\t \
    and t1, mask, k3, lsr CV16                          \n\t \
    add t1, c                                           \n\t \
    and t1, t1, mask                                    \n\t \
                                                             \
    orr k0, t0, t1, lsl CV16                            \n\t


#define ENC_ADD_ROUND_KEY_(b, rk) \
    ldm r1!, {rk}            \n\t \
    eor b, b, rk             \n\t

#define DEC_ADD_ROUND_KEY_(b, rk) \
    ldmdb r1!, {rk}          \n\t \
    eor b, b, rk             \n\t


#define ENC_A_(b, left, right, mask)   \
    and left, mask, b             \n\t \
    and right, mask, b, lsr CV16  \n\t \
                                       \
    lsr b, left, CV7              \n\t \
    orr left, b, left, lsl CV9    \n\t \
    add left, left, right         \n\t \
                                       \
    lsr b, right, CV14            \n\t \
    orr right, b, right, lsl CV2  \n\t \
    eor right, left, right        \n\t \
                                       \
    and left, left, mask          \n\t \
    and right, right, mask        \n\t \
                                       \
    orr b, left, right, lsl CV16  \n\t

#define DEC_A_(b, left, right, mask)   \
    and left, mask, b             \n\t \
    and right, mask, b, lsr CV16  \n\t \
                                       \
    eor right, left, right        \n\t \
    lsr b, right, CV2             \n\t \
    orr right, b, right, lsl CV14 \n\t \
    and right, right, mask        \n\t \
                                       \
    sub left, left, right         \n\t \
    and left, left, mask          \n\t \
    lsr b, left, CV9              \n\t \
    orr left, b, left, lsl CV7    \n\t \
    and left, left, mask          \n\t \
                                       \
    orr b, left, right, lsl CV16  \n\t


#define L_(b, temp)               \
    eor b, b, temp, ror CV8  \n\t \
    eor b, b, temp, ror CV24 \n\t

#define ENC_L_(b0, b1, temp) \
    mov temp, b0        \n\t \
                             \
    L_(b0, temp)             \
                             \
    eor b0, b0, b1      \n\t \
    mov b1, temp        \n\t \

#define DEC_L_(b0, b1, temp) \
    mov temp, b1        \n\t \
                             \
    L_(b1, temp)             \
                             \
    eor b1, b1, b0      \n\t \
    mov b0, temp        \n\t


#define ENC_ADD_WHITENING_KEY_(b0, b1, rk) \
    ldm r1!, {rk}                     \n\t \
    eor b0, b0, rk                    \n\t \
                                           \
    ldm r1!, {rk}                     \n\t \
    eor b1, b1, rk                    \n\t

#define DEC_ADD_WHITENING_KEY_(b0, b1, rk) \
    ldmdb r1!, {rk}                   \n\t \
    eor b1, b1, rk                    \n\t \
                                           \
    ldmdb r1!, {rk}                   \n\t \
    eor b0, b0, rk                    \n\t


#define SET_MASK(mask) \
    STR(SET_MASK_(mask))


#define EKS_STORE_ROUND_KEYS(k0, k1, k2) \
    STR(EKS_STORE_ROUND_KEYS_(k0, k1, k2))


#define EKS_ROUND_KEYS(k0, k1, k2, k3, t0, t1, t2, t3, mask, c) \
    STR(EKS_ROUND_KEYS_(k0, k1, k2, k3, t0, t1, t2, t3, mask, c))


#define EKS_WHITENING_KEYS(k0, k1, k2, k3, t0, t1, mask, c) \
    STR(EKS_WHITENING_KEYS_(k0, k1, k2, k3, t0, t1, mask, c))


#define ENC_ADD_ROUND_KEY(b, rk) \
    STR(ENC_ADD_ROUND_KEY_(b, rk))

#define DEC_ADD_ROUND_KEY(b, rk) \
    STR(DEC_ADD_ROUND_KEY_(b, rk))


#define ENC_A(b, left, right, mask) \
    STR(ENC_A_(b, left, right, mask))

#define DEC_A(b, left, right, mask) \
    STR(DEC_A_(b, left, right, mask))


#define L(b, temp) \
    STR(L_(b, temp))

#define ENC_L(b0, b1, temp) \
    STR(ENC_L_(b0, b1, temp))

#define DEC_L(b0, b1, temp) \
    STR(DEC_L_(b0, b1, temp))


#define ENC_ADD_WHITENING_KEY(bo, b1, rk) \
    STR(ENC_ADD_WHITENING_KEY_(bo, b1, rk))

#define DEC_ADD_WHITENING_KEY(bo, b1, rk) \
    STR(DEC_ADD_WHITENING_KEY_(bo, b1, rk))


#endif /* ARM_MACROS_H */
