#include <stdio.h>
#include <stdint.h>

extern int combineColors(char *rgba);

extern void decodeThermo(
    uint64_t data,
    int *isValid,
     int *wholePart,
    unsigned int *decimalPart);

int main()
{
    char rgba[4] = {120, 15, (char)255, 100};

    int combined = combineColors(rgba);

    printf("Combined RGBA: 0x%08X\n", combined);
    // printf("alpha after zeroing: %d\n", rgba[3]);


    // thermometer part

    uint64_t rawData = 0x0000000180500001ULL;

    int isValid;
    int whole;
    unsigned int decimal;

    decodeThermo(rawData, &isValid, &whole, &decimal);

    if (isValid)
    {
        printf("Temperature: %d.%u C\n", whole, decimal);
    }
    else
    {
        printf("Temperature is not valid\n");
    }

    return 0;
}