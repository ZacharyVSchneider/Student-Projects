#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Normal printf*/
    printf("Hello world!\n");
    /*Prints a quotation mark*/
    printf("Hello\"world!\n");
    /*Tells printf to print an integer, then specifies an integer*/
    printf("%d \n ", 500);
    /*Tells printf to print a character and an integer, then specifies the character and the integer*/
    printf("My favorite %s is %d \n ", "number", 500);
    return 0;
}
