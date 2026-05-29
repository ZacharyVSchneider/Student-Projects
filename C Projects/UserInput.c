#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*To set up an input function, define a variable, state how much characters it can . Then print a question out*/
    int age [3];
    printf("Enter your age: ");
    /*This function accepts and digests the input with the &*/
    scanf("%d", &age);
    printf("You are %d years old", age);

    double gpa [4];
    printf("Enter your gpa: ");
    scanf("%lf", &gpa);
    printf("Your gpa is %f", gpa);

    char grade [5];
    printf("Enter your grade: ");
    scanf("%c", &grade);
    printf("Your grade is %c", grade);

    char name [12];
    printf:("Enter your name: ");


    return 0;
}
