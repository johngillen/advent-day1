#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int sum = 0;

    // input handling
    for (;;)
    {
        int input;
        printf("Enter module mass (^D to sum): ");
        int line = scanf("%d", &input);
        if (line == EOF) { break; }
        sum += fuel(input);
    }

    printf("\nTotal fuel required: %d\n", sum);
    
    return 0;
}

/*
Fuel required to launch a given module is based on its mass. Specifically, to
find the fuel required for a module, take its mass, divide by three, round down,
and subtract 2.
*/
int fuel(int mass)
{
    return floor(mass / 3) - 2;
}