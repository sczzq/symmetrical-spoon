
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "bigInteger.h"

//uint32_t bit32 = 0x1<<31;
//uint32_t bits31 = 0x7FFFFFFF;

void BigPrintDecimal(BigInteger b);
uint32_t bit[] = {
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
    0x00000000,
    0x00000001, 0x00000002, 0x00000004, 0x00000008,
    0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800,
    0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000,
    0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000,
    0x10000000, 0x20000000, 0x40000000, 0x80000000,
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
};

uint32_t ibit[] = {
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
    0xFFFFFFFF,
    0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFB, 0xFFFFFFF7,
    0xFFFFFFEF, 0xFFFFFFDF, 0xFFFFFFBF, 0xFFFFFF7F,
    0xFFFFFEFF, 0xFFFFFDFF, 0xFFFFFBFF, 0xFFFFF7FF,
    0xFFFFEFFF, 0xFFFFDFFF, 0xFFFFBFFF, 0xFFFF7FFF,
    0xFFFEFFFF, 0xFFFDFFFF, 0xFFFBFFFF, 0xFFF7FFFF,
    0xFFEFFFFF, 0xFFDFFFFF, 0xFFBFFFFF, 0xFF7FFFFF,
    0xFEFFFFFF, 0xFDFFFFFF, 0xFBFFFFFF, 0xF7FFFFFF,
    0xEFFFFFFF, 0xDFFFFFFF, 0xBFFFFFFF, 0x7FFFFFFF,
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
};

uint32_t bits[] = {
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
    0x00000000,
    0x00000001, 0x00000003, 0x00000007, 0x0000000F,
    0x0000001F, 0x0000003F, 0x0000007F, 0x000000FF,
    0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF,
    0x00001FFF, 0x00003FFF, 0x00007FFF, 0x0000FFFF,
    0x0001FFFF, 0x0003FFFF, 0x0007FFFF, 0x000FFFFF,
    0x001FFFFF, 0x003FFFFF, 0x007FFFFF, 0x00FFFFFF,
    0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF,
    0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF, 0xFFFFFFFF,
//  0x12345678, 0x12345678, 0x12345678, 0x12345678.
};
int debug = 0;
uint32_t unitBits = 31;

BigInteger getBigInteger(uint32_t length){
    BigInteger b;
    b.number = (uint32_t *)malloc(length * sizeof(uint32_t));
    memset(b.number, 0, length * sizeof(uint32_t));
    b.length = length;
    b.unitBits = unitBits;
    return b;
}

void releaseBigInteger(BigInteger b){
    free(b.number);
}

// add a and b to new BigInteger.
BigInteger BigAdd(BigInteger a, BigInteger b){
    uint32_t minLength = a.length < b.length ? a.length : b.length;
    uint32_t maxLength = a.length > b.length ? a.length : b.length;
    BigInteger c = getBigInteger(maxLength+1);
    BigAddRecursion(a, b, c);
    return c;
}

// add a and b to c. a + b = c.
int BigAddRecursion(BigInteger a, BigInteger b, BigInteger c){
    uint32_t i;
    uint32_t unitbits = a.unitBits;
    BigInteger d;
    uint32_t minLength = a.length < b.length ? a.length : b.length;
    uint32_t maxLength = a.length > b.length ? a.length : b.length;
    if(c.length < maxLength){
        return -1;
    }
    if(!(a.unitBits == b.unitBits && b.unitBits == c.unitBits)){
        printf("unit bits not same\n");
        return -1;
    }
    a.number[0] = a.number[0] & bits[unitbits];  // clear the most bits.
    b.number[0] = b.number[0] & bits[unitbits];  // clear the most bits.
    if(debug){
        BigPrintBits(a);
        BigPrintBits(b);
    }
    c.number[0] = a.number[0] + b.number[0];
    for(i=1; i<minLength; i++){
        a.number[i] &= bits[unitbits];  // clear the most bits.
        b.number[i] &= bits[unitbits];  // clear the most bits.
        c.number[i] = a.number[i] + b.number[i];
        c.number[i] += ((c.number[i-1] & bit[unitbits+1])>>unitbits);
        c.number[i-1] &= bits[unitbits];  // clear the most bits.
    }
    if(minLength != maxLength){
        if(maxLength == a.length)
            d = a;
        else
            d = b;
        for(i=minLength; i<maxLength; i++){
            d.number[i] &= bits[unitbits];
            c.number[i] = d.number[i];
            c.number[i] += (( c.number[i-1] & bit[unitbits+1] ) >> unitbits);
            c.number[i-1] &= bits[unitbits];
        }
    }
    if(c.number[i-1] & bit[unitbits+1]){
        c.number[i] += 1;
        c.number[i-1] &= bits[unitbits];  // clear the most bits.
    }
    if(debug)
        BigPrintBits(c);

    return 0;
}

// add a to b.
int BigAddRecursive2(BigInteger a, BigInteger b){
    uint32_t i;
    uint32_t unitbits = a.unitBits;
    if(a.length > b.length){
        printf("a.length: %u, b.length: %u\n", a.length, b.length);
        return -1;
    }
    if(a.unitBits != b.unitBits){
        printf("unit bits not same\n");
        return -1;
    }
    i = 0;
    a.number[i] &= bits[unitbits];
    b.number[i] += a.number[i];
    i++;
    while(i<a.length){
        a.number[i] &= bits[unitbits];
        b.number[i] += a.number[i];
        b.number[i] += ((b.number[i-1]&bit[unitbits+1])>>unitbits);
        b.number[i-1] &= bits[unitbits];
        i++;
    }
    while(b.number[i-1]&bit[unitbits+1]){
         b.number[i] += 1;
         b.number[i-1] &= bits[unitbits];
         i++;
    }

     return 0;
}

int BigLeftShift(BigInteger a, uint32_t w){
    uint32_t EU, LB, HB, i;
    EU = w/a.unitBits;
    LB = w%a.unitBits;
    if(LB == 0 && w > 0){
        for(i=a.length-1; i>0; i--)
            a.number[i+EU] = a.number[i];
        a.number[EU] = a.number[0];
        for(i=EU-1; i>0; i--)
            a.number[i] = 0;
        a.number[0] = 0;
    }
    else if(LB > 0){
        HB = (EU + 1) * a.unitBits - w;
        a.number[a.length+EU] = a.number[a.length-1]>>HB;
        for(i=a.length-1; i>0; i--)
             a.number[i+EU] = (a.number[i]<<LB) | (a.number[i-1]>>HB);
        a.number[EU] = a.number[0] << LB;
        i = EU - 1;
        do{
            a.number[i--] = 0;
        }while(i > 0);
    }
     return 0;
}

int BigLeftShift2(BigInteger a, BigInteger b, uint32_t w){
    uint32_t EU, LB, HB;
    uint32_t i;
    EU = w/a.unitBits;
    LB = w%a.unitBits;
    memset(b.number, 0, sizeof(b.base)*b.length);
    if(LB == 0 && w >= 0){
        for(i=0; i<a.length; i++){
            b.number[i+EU] = a.number[i];
        }
    }
    else if(LB > 0){
        HB = (EU + 1) * a.unitBits - w;
        b.number[a.length+EU] = a.number[a.length-1]>>HB;
        for(i=a.length-1; i>0; i--)
             b.number[i+EU] = (a.number[i]<<LB) | (a.number[i-1]>>HB);
        b.number[EU] = a.number[0] << LB;
    }
     return 0;
}

int BigMultiplyRecursive(BigInteger a, BigInteger b, BigInteger c){
    BigInteger t = getBigInteger(c.length-1);
    t.unitBits = b.unitBits;
    uint32_t i=0, j=0;
    for(i=0; i<a.length; i++){
        for(j=0; j<a.unitBits; j++){
            if(a.number[i] & bit[j+1]){
                BigLeftShift2(b, t, i*a.unitBits+j);
                BigAddRecursive2(t, c);
            }
        }
    }
    releaseBigInteger(t);
}

BigInteger BigMultiply(BigInteger a, BigInteger b){
    uint32_t length = a.length > b.length ? a.length : b.length;
     BigInteger c = getBigInteger(length*2 + 1);
     BigMultiplyRecursive(a, b, c);
     return c;
}

int BigMultiplyRecursive2(BigInteger a, BigInteger b, BigInteger tb, BigInteger t){
    uint32_t i, j;
    for(i=0; i<a.length; i++){
        for(j=0; j<a.unitBits; j++){
            if(a.number[i] & bit[j+1]){
                BigLeftShift2(b, t, i*a.unitBits+j);
                BigAddRecursive2(t, tb);
            }
        }
    }
    memcpy(b.number, tb.number, b.length * sizeof(b.base));
//    b.number = tb.number;
    return 0;
}

#ifndef e
#define e (exp(1.0))
#define pi (acos(-1.0))
#endif

uint32_t inline getBitLength(uint32_t fn){
    uint32_t l = log2(2*pi*fn)/2 + fn * log2(fn/e);
    l += 1;
    return l;
}

uint32_t inline getDecimalLength(uint32_t fn){
    uint32_t l = log10(2*pi*fn)/2 + fn * log10(fn/e);
    return l;
}

BigInteger BigFactorial(uint32_t n){
    uint32_t bitlength = getBitLength(n);
    uint32_t length = bitlength/unitBits + 2;
    BigInteger f = getBigInteger(length);
    memset(f.number, 0, length * sizeof(f.base));
    f.number[0] = 0x1;
    BigInteger bn = getBigInteger(2);
    BigInteger t = getBigInteger(f.length);
    BigInteger tb = getBigInteger(f.length);
    bn.number[0] = 0;
    bn.number[1] = 0;
    uint32_t i;
    for(i=1; i<=n; i++){
         printf("n = %u\n", i);
         bn.number[0] = i;
         memset(tb.number, 0, sizeof(tb.base)*tb.length);
         BigMultiplyRecursive2(bn, f, tb, t);
         if(i==n){
             BigPrintBits(f);
//             BigPrintDecimal(f);
         }
    }
    releaseBigInteger(bn);
    releaseBigInteger(t);
    releaseBigInteger(tb);
    return f;
}

void BigPrintBits(BigInteger b){
     int i=0, j=0;
     printf("unit length: %u\t, ", b.length);
     printf("unit bits: %u\t, ", b.unitBits);
     printf("byte length: %lu\t, ", b.length*sizeof(b.base));
     printf("bit space: %lu\t, ", b.length*sizeof(b.base)*8);
     printf("bit length: %u\n", b.length*b.unitBits);
     for(i=b.length-1; i>=0; i--){
         for(j=b.unitBits-1; j>=0; j--){
             printf("%u", (b.number[i]&bit[j+1])>>j);
         }
         printf("  ");
     }
     printf("\n");
}

static int BitToHecimal(int pos, uint8_t *t, int length){
     int i=0,j;
     int tp = 0;
     memset(t, 0, length);
     t[tp] = 1;
     tp++;
     while(i<pos){
         for(j=0; j<tp; j++){
             t[j] *= 2;
         }
         for(j=0; j<tp; j++){
             if(t[j]>9){
                 t[j] -= 10;
                 t[j+1] += 1;
             }
         }
         if(t[tp] > 0)
             tp++;
         i++;
     }
     return tp;
}

static int AddStringDecimal(uint8_t *dst, uint8_t *src, int length){
     int i;
     for(i=0; i<length; i++){
         dst[i] += src[i];
         if(dst[i] > 9){
             dst[i] -= 10;
             dst[i+1] += 1;
         }
     }
     if(dst[i] > 0)
         i++;
     return i;
}

static void printArrayString(uint8_t *a, int length){
    int i=0;
    for(i=length-1; i>=0; i--){
        printf("%d", a[i]);
    }
    printf(";\n length %d\n", length);
}

void BigPrintDecimal(BigInteger b){
     int i=0, j=0, length;
     int need_length;
     need_length = ((b.length * sizeof(b.base) * 8 / 13) + 1) * 4;
     printf("unit length: %u\t, ", b.length);
     printf("unit bits: %u\t, ", b.unitBits);
     printf("byte length: %lu\t, ", b.length*sizeof(b.base));
     printf("bit length: %lu\n", b.length*sizeof(b.base)*8);
     uint8_t *decimal = (uint8_t *)malloc(need_length);
     uint8_t *t = (uint8_t *)malloc(need_length);
     memset(decimal, 0, need_length);
     memset(t, 0, need_length);
     for(i=0; i<b.length; i++){
         for(j=0; j<b.unitBits; j++){
             if(b.number[i] & (0x1<<j)){
                 int pos = i*b.unitBits + j;
                 length = BitToHecimal(pos, t, need_length);
                 length = AddStringDecimal(decimal, t, length);
//                 printf("decimal: ");
//                 printArrayString(decimal, need_length);
             }
         }
         printf("%X ", b.number[i]);
     }
     printf("\n");
     printArrayString(decimal, length);
     printf("\n");
     free(t);
     free(decimal);
}

long long fraction(int n){
    int i;
    long long r=1;
    for(i=1; i<n; i++){
        r *= i;
    }
    return r;
}

void test4(){
    uint32_t n = 70000;
    printf("compute n! = %u!\n", n);
    printf("compute n! = 0x%08X!\n", n);
    struct timeval tv, tv2;
    gettimeofday(&tv, NULL);
    BigInteger f = BigFactorial(n);
    gettimeofday(&tv2, NULL);
    printf("OK\n");
    if(tv2.tv_usec > tv.tv_usec){
        printf("using time: %lu.%lu\n",
                tv2.tv_sec-tv.tv_sec, tv2.tv_usec-tv.tv_usec);
    } else {
        printf("using time: %lu.%lu\n",
                tv2.tv_sec-tv.tv_sec-1, 1000-tv2.tv_usec-tv.tv_usec);
    }

    releaseBigInteger(f);
}

//#define e (exp(1.0))
//#define pi (acos(-1.0))

/*
void test4(){
    double a;
    int i;
    for(i=1; i<700; i++){
        double n = i;
//        a = sqrt(2*pi*n) * (pow(n, n)/pow(e, n));
//        printf("%f\n", a);
//        printf("%f\n", log10(a));
//        printf("%lld\n", fraction(i));
        a = log2(2*pi*n)/2 + n * log2(n/e);
        printf("%f\n", a);
        a = log10(2*pi*n)/2 + n * log10(n/e);
        printf("%f\n", a);
    }
}
*/

void test40(){
    int length = 100;
    uint32_t i;
    uint32_t an = bits[unitBits/2];
    debug = 1;
    debug = 0;

    BigInteger a = getBigInteger(length);
    BigInteger b = getBigInteger(length+1);

    for(i=0; i<length; i+=2){
        a.number[i] = an;
        b.number[i+1] = an;
    }

    BigInteger c = BigMultiply(a, b);

    BigPrintBits(a);
    BigPrintBits(b);
    BigPrintBits(c);

    BigPrintDecimal(a);
    BigPrintDecimal(b);
    BigPrintDecimal(c);

    releaseBigInteger(a);
    releaseBigInteger(b);
    releaseBigInteger(c);
}
void test9(){
    int length = 3;
    uint32_t i;
    uint32_t an = bits[unitBits/2];
    debug = 1;

    BigInteger a = getBigInteger(length);
    BigInteger b = getBigInteger(length*2);
    a.number[0] = an;
    a.number[2] = an;

    for(i=0; i<(length-1)*unitBits; i++){
        memset(a.number, 0, sizeof(uint32_t)*a.length);
        a.number[0] = an;
        a.number[2] = an;
        BigLeftShift2(a, b, i);
        printf("left shift: %u\n", i);
        BigPrintBits(b);
    }

    releaseBigInteger(a);
    releaseBigInteger(b);
}

void test8(){
    int length = 1;
    int i;
    uint32_t an = bits[unitBits];
    uint32_t bn = bits[unitBits/2];
    debug = 1;

    BigInteger a = getBigInteger(length);
    BigInteger b = getBigInteger(length+2);

    for(i=0; i<length; i++){
        a.number[i] = (an << i) & bits[unitBits];
        b.number[i] = (bn << i) & bits[unitBits];
    }

//    BigPrintDecimal(a);
//    BigPrintDecimal(b);

    BigPrintBits(a);
    BigPrintBits(b);

    BigAddRecursive2(a, b);

    BigPrintBits(b);

//    BigPrintDecimal(a);
//    BigPrintDecimal(b);

    releaseBigInteger(a);
    releaseBigInteger(b);
}

void test7(){
    int length = 1;
    int i = 0;
    uint32_t an = bits[unitBits];
    uint32_t bn = bits[unitBits-10];
    debug = 1;
//    debug = 0;

    BigInteger a = getBigInteger(length);
    BigInteger b = getBigInteger(length+2);

    for(i=0; i<length; i++){
        a.number[i] = (an << i) & bits[unitBits];
        b.number[i] = (bn << i) & bits[unitBits];
    }

    b.number[length] = bn;
    b.number[length+1] = bn;

    BigInteger c = BigAdd(a, b);

    BigPrintDecimal(a);
    BigPrintDecimal(b);
    BigPrintDecimal(c);

    releaseBigInteger(a);
    releaseBigInteger(b);
    releaseBigInteger(c);

    printf("OK\n");
}

void test6(){
    int length = 2;
    uint32_t an = bits[unitBits];
    uint32_t bn = 0xF0A0A0A0 & bits[unitBits];

    BigInteger a = getBigInteger(length);
    BigInteger b = getBigInteger(length);

    for(length--; length >= 0; length--){
        a.number[length] = (an << length) & bits[unitBits] ;
        b.number[length] = (bn << length) & bits[unitBits];
    }

    BigInteger c = BigAdd(a, b);

    BigPrintDecimal(a);
    BigPrintDecimal(b);
    BigPrintDecimal(c);

    releaseBigInteger(a);
    releaseBigInteger(b);
    releaseBigInteger(c);
}

void test5(){
    uint8_t a[320] = {0};
    uint8_t decimal[320];
    memset(a, 0, sizeof(a));
    memset(decimal, 0, sizeof(decimal));
    int i=0;

    for(i=0; i<1024; i++){
        printf("%d bits:   ", i);
        int length = BitToHecimal(i, a, 320);
        printArrayString(a, length);
        length = AddStringDecimal(decimal, a, length);
        printArrayString(decimal, length);
    }
}


void test2(){
    int i=0;
    for(i=0; i<32; i++){
        printf("i %d: %u\n", i, 0x1<<i);
    }
}

void test1(){
    int length = 1;
    uint32_t an = bits[unitBits];
    BigInteger a = getBigInteger(length);

    an = bit[unitBits];
    a.number[0] = an;
    printf("%08x=%x\n", bit[unitBits], a.number[0]);
    BigPrintBits(a);
    printf("\n");

    an = 0xA1A1 & bits[unitBits];
    a.number[0] = an;
    printf("0xA1A1=%x\n", a.number[0]);
    BigPrintBits(a);
    printf("\n");

    printf("0xFFFFFFFF&0x7FFFFFFF=%x\n", 0xFFFFFFFF&0x7FFFFFFF);

    releaseBigInteger(a);
}

