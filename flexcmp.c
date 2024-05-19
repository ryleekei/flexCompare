#include "flexint.h"
#include <stdio.h>

//helper function to convert to signed long
static signed long toLong(flexint* f)
{
        unsigned long value, sign;
        signed long result;
        int shift = 64 - f->width;

        value = *(unsigned long*)&f->val;
        value = (value << shift) >> shift;
        sign = value >> (f->width - 1);

        if (sign == 1)
        {
                result = *(signed long*) &value;
                result = (result << shift) >> shift;
        }
        else
        {
                result = *(signed long*)&value;
        }

        return result;
}
//compare the two values
int flexcmp(flexint *xp, flexint *yp)
{
        long x, y;
        x = toLong(xp);
        y = toLong(yp);

        printf("\nComparing a: %ld , to b: %ld\n", x,y);

        if (x < y)
        {
                return -1;
        }
        else if (x > y)
        {
                return 1;
        }
        else if (x == y)
        {
                return 0;
        }
}