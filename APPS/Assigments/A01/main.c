#include <stdio.h>

extern int negate();
// extern void negate();

// extern int g_int_output;

int main()
{
    // negate();

    // printf("result: %d\n", g_int_output);
    int result = negate();
    printf("result: %d\n", result);

    return 0;
}