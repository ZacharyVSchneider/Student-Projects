#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*You can use print to show numbers, %f allows us to put in a decimal number.*/
    printf("%f \n", 8.9);
    /*You can use print to show sums, differences, etc.*/
    printf("%f \n", 4 + 5.50);
    /*You can also divide, but dividing with whole numbers cuts out any decimal from the answer*/
    printf("%d \n", 5 / 4 );
    /*A way to brute force the decimals is to add decimals to one of the initial numbers.*/
    printf("%f \n", 5 / 4.00);
    /* There is also power functions, which use their own slang*/
    printf("%f \n", pow(2, 3));
    /*Same goes for square roots.*/
    printf("%f \n", sqrt(36) );
    /*There are other misc. ones, like ceil, which rounds up.*/
    printf("%f \n", ceil(36.890));
    /*And its other, floor.*/
    printf("%f \n", floor(36.890));
    /*And dozens of other niche functions*/
    return 0;
}
