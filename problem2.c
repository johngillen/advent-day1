#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int sum = 0;

    FILE * file;
    file = fopen("input", "r");

    for (;;)
    {
        int input;
        int line = fscanf(file, "%d", &input);
        printf("%d\n", input);
        if (line == EOF) { break; }
        sum += fuel(input);
    }

    /* only works for typed input
    for (;;)
    {
        int input;
        printf("Enter module mass (^D to sum): ");
        int line = scanf("%d", &input);
        if (line == EOF) { break; }
        sum += fuel(input);
    }
    */

    printf("Total fuel required: %d\n", sum);
    
    return 0;
}

/*
Fuel required to launch a given module is based on its mass. Specifically, to
find the fuel required for a module, take its mass, divide by three, round down,
and subtract 2.
*/

int fuel(int mass)
{
    if (mass <= 0) { return 0; }
    int n = (int) floor((double) mass / 3) - 2;
    if (n < 0) { return 0; }
    return n += fuel(n);
    
}