/* Copyright (c) Microsoft Corporation. All rights reserved. */

/* Portable 64-bit integer math functions for MMLite
 */
#define __NO_BUILTIN_INT64 1
#if defined(MMLITE)
#include <mmlite.h>
#include <machdep.h>
#include <assert.h>
#else
#define INT64 MYINT64
#define UINT64 MYUINT64
#include <windows.h>
#undef INT64
#undef UINT64
typedef struct _INT64 INT64;
typedef struct _UINT64 UINT64;
#define EXTERN_C extern
#include "int64.h"
#endif
#include <stdio.h>

#undef Int64SquareRoot
#undef Uint64SquareRoot
#undef IntSquareRoot
#undef UintSquareRoot

#if defined(_MSC_VER)
#pragma warning(disable:4146)  /* unary minus to unsigned type, result still unsigned */
#endif

#if 1
#define __NUM_INT_BITS 32
#else
#define __NUM_INT_BITS 64
#endif

static UINT ffs(UINT x)
{
    UINT i;
    for (i = 0; i < __NUM_INT_BITS; i++) {
        if (!x)
            return i;
        x >>= 1;
    }
    return __NUM_INT_BITS;
}

/* MMLite runtime library function -- take the square root 
   of an unsigned integer. The return value is an unsigned 
   integer. Used for 32-bit integers. Could also be used 
   for 64-bit integers on platforms with native 64-bit support 
 */
UINT UintSquareRoot(UINT x)
{
    /* Binary search... */
    UINT hi, lo, a, b;
    if (x < 2)
        return x;
    a = ffs(x);
    // printf("ffs=%d\n", a);

    hi = 1 << a/2;
    lo = 1 << (a-1)/2;

    for(;;) {
        a = (hi - lo + 1) / 2;
        if (a == 0) {
            assert(hi == lo); /* TUNE, but I can't come up w/ test case */
            return lo;
        }
        b = lo + a;
        b *= b;
        // printf("lo=%d hi=%d x=%d a=%d b=%d\n", lo, hi, x, a, b);

        if (b <= x)
            lo += a;
        else
            hi -= a;
    };
}

UINT UintNRoot(UINT x, UINT n)
{
    /* Binary search... */
    UINT hi, lo, a, b, c, d, i, L, H;
    if (x < 2)
        return x;
    a = ffs(x);
    //printf("ffs=%d\n", a);

    hi = 1 << a/2;
    H = ~0;
    L = lo = 1;

    //printf("lo=%d hi=%d x=%d\n", lo, hi, x);

    for(;;) {
        a = (hi - lo + 1) / 2 - 1;
        if (a == 0) {
            /* Make sure we get the last bits right */
            while (lo < hi) {
                //printf("TUNE lo=%d != hi=%d\n", lo, hi);

                b = c = lo;
                for (i = 1; i < n; i++)
                    b *= c;
                d = c = hi;
                for (i = 1; i < n; i++) {
                    if (d > x) {
                        hi--;
                        continue;
                    }
                    d *= c;
                }
                if (x-b < d-x)
                    hi--;
                else
                    lo++;
            }
            return lo;
        }

        b = c = lo + a;
        for (i = 1; i < n; i++) {
            if (b > x)
                break;
            b *= c;
        }

        if (b <= x)
            lo += a, L = b;
        else
            hi -= a, H = b;

        //printf("lo=%d hi=%d x=%d a=%d b=%d\n", lo, hi, x, a, b);

    };
}

/* MMLite runtime library function -- take the square root 
   of a signed integer. The return value is a signed
   integer. The return value for a negative parameter
   is -re(sqrt(i)) */
INT IntSquareRoot(INT x) 
{
    if (x < 0) {
        return -(INT) UintSquareRoot((UINT) -x);
    } else {
        return (INT) UintSquareRoot((UINT) x);
    }
}

/* MMLite runtime library function -- take the square root 
   of an unsigned, 64-bit integer. The return value is an 
   unsigned 64-bit integer */
UINT64 Uint64SquareRoot(UINT64 x)
{
    UINT64 sqrt;

    if (0 == Uint64High32Bits(x)) {
        Uint32ToUint64(sqrt, UintSquareRoot(Uint64Low32Bits(x)));
        return sqrt;
    }

    //printf("In 64-bit version of Uint64SquareRoot\n");


    /* 64-bit version of the square root search algorithm below.
       See tests below. This code tends to deliver results that 
       are off by small values */
    {
        UINT s;
        UINT64 hi, lo, a, b, d;

        s = (ffs(Uint64High32Bits(x)) + 32) >> 1;
        //printf("ffs=%d\n", s);

        Int32ToInt64(a, 1);
        hi = Uint64LShift(a, s);
        lo = Uint64LShift(Uint64SubtractUint32(a, 1), s);

        for (;;) {
            a = Uint64RShift(Uint64Subtract(hi, Uint64AddUint32(lo, 1)), 1);
            if (Int64Equal(a, UINT64_ZERO)) {
                /* Make sure we get the last bits right */
                while (Uint64Less(lo, hi)) {
                    //printf("TUNE lo=%lld != hi=%lld\n", lo, hi);

                    b = Uint64TimesUint64(lo, lo);
                    d = Uint64TimesUint64(hi, hi);
                    if (Uint64Less(Uint64Subtract(x,b), Uint64Subtract(d,x)))
                        hi = Uint64SubtractUint32(hi, 1);
                    else
                        lo = Uint64AddUint32(lo, 1);
                }
                return lo;
            }
            b = Uint64Add(lo, a);
            b = Uint64TimesUint64(b, b);
            //printf("lo=%lld hi=%lld x=%lld a=%lld b=%lld\n", lo,hi, x, a,b);

            if (!Uint64Less(b, x))
                hi = Uint64Subtract(hi, a);
            else
                lo = Uint64Add(lo, a);
        }
    }
}

/* MMLite runtime library function -- take the square root 
   of a signed, 64-bit integer. The return value is a signed
   64-bit integer. The return value for a negative parameter
   is the real part of the result multiplied by -1. That is -re(sqrt(x)) */
INT64 Int64SquareRoot(INT64 x)
{
    UINT64 u;
    INT64 b;
    INT a;
    if (0 == Uint64High32Bits(x)) {
        a = UintSquareRoot(Uint64Low32Bits(x));
        Int32ToInt64(b, a);
        //printf("LowRoot %llx -> %d -> %lld\n", x, a, b);

        return b;
    } else if (Int64IsNegative(x)) {
        x = Int64Subtract(INT64_ZERO, x);
        u = Int64ToUint64(x);
        u = Uint64SquareRoot(u);
        x = Uint64ToInt64(u);
        x = Int64Subtract(INT64_ZERO, x);
        return x;
    } else {
        u = Int64ToUint64(x);
        u = Uint64SquareRoot(u);
        x = Uint64ToInt64(u);
        return x;
    }
}