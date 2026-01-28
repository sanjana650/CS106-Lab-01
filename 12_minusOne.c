#include <stdio.h>

/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    // return ~0;
    return (1<<31)>>31; //CAN USE ANY CONSTANT BUT BEST IS 1 or 0.
    //send 1 to LSB to MSB and then right shift 
}

int test_minusOne(void)
{
    return -1;
}

int main(void)
{
    printf("expected: %x\n", minusOne());
    printf("actual  : %x\n", test_minusOne());
}
