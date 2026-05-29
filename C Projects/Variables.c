#include <stdio.h>
#include <stdlib.h>

int main()
{
    char characterName[] = "John";
    int characterAge = 35;
    /*%s means we insert a character, we have to state what variable we insert though*/
    printf("There was a man named %s.\n", characterName);
    /*%d means we insert a integer numberU, we still have to state what variable though*/
    printf("He was %d years old.\n", characterAge);
    printf("He liked his name, %s.\n", characterName);
    printf("He did not like his age, %d.\n", characterAge);
    return 0;
}
