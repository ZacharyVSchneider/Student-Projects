#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*you can define variables with this method*/
    int num = 5;
    printf("%d\n", num);
    /*As a cool trick, you can also redefine it halfway through the script.*/
    num = 8;
    printf("%d\n", num);

    /*In the same way you can define a variable, you can define a constant*/
    const int NUMTWO = 5;
    printf("%d\n", NUMTWO);
    /*Constants cant change, if an attempt is made a error happens, devs use constants on values they don't want changing. They also make the constants all caps btw.*/
    /*so NUMTWO = 8 would produce an error*/
    printf("%d\n", NUMTWO);


    return 0;
}
