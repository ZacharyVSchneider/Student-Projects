#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name [20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is %s \n", name);
    /*Or*/
    char Tname [20];
    printf("Enter your name ");
    fgets(Tname, 20, stdin);
    printf("Your name is %s", Tname);
    return 0;
}
