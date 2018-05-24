#ifndef _BIG_NUMBER_H_
#define _BIG_NUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>

/**
 * implementation about big number operation.
 * add minus multiply divide power factorial model.
 * use uint32_t, 32 bits as base unit, that is
 *  1, 2, 3, 4, ..., 32
 * but the 32th bit uses to mark as carry or borrow,
 *   so, clear it after each using.
 * so, the biggest number is MAX_INT*BigInteger.length.
 */

typedef struct BigInteger{
    uint32_t length;
    uint32_t base;
    uint32_t unitBits;
    uint32_t *number;
}BigInteger;


BigInteger getBigInteger(uint32_t length);
void releaseBigInteger(BigInteger b);
BigInteger BigAdd(BigInteger a, BigInteger b);
int BigAddRecursion(BigInteger a, BigInteger b, BigInteger c);
void BigPrintBits(BigInteger b);

void test();
void test2();
void test3();
void test4();


#endif

