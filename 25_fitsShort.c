#include <stdio.h>

/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    return !((x>>15) ^ (x>>16)); 
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

int main(void)
{
    int x = 0xFF;
    printf("expected: %x\n", fitsShort(x));
    printf("actual  : %x\n", test_fitsShort(x));
}

/*
1111 1111 1111 1111 (-1) (TMin)
0000 0000 0000 0000 (zero)
0000 0000 0000 0001 (one)
0111 1111 1111 1111 (TMAX)

extend to int;
1111 1111 1111 1111 1000 0000 0000 0000 (short Tmin)
...
1111 1111 1111 1111 1111 1111 1111 1111 (-1)
0000 0000 0000 0000 0000 0000 0000 0000 (zero)
0000 0000 0000 0000 0000 0000 0000 0001 (one)
...
0000 0000 0000 0000 0111 1111 1111 1111 (short TMax)

whenever the upper 17 bits are the same, the int can fit in the short
*/