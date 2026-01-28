#include <stdio.h>

/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n)
{
    // find TMin 
    return ((1<<31)>>(n+(~0))) >> 31); //wrong answer fix it later
}
//cannot shift negative number: (1<<31)>>(-1) -> unpredictable

int test_upperBits(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < x; i++)
        result |= (1 << (31 - i));
    return result;
}

int main(void)
{
    int x = 32;
    printf("expected: %x\n", upperBits(x));
    printf("actual  : %x\n", test_upperBits(x));
}
