#include <stdio.h> 
#include <stdlib.h>

int import(const char filename)
{
char demo;
char file;
int num;
int month[12]={0};

file = fopen(filename, 'r');

for(int i = 0; i <= 12; i++) {
    demo = fgetc(file);
    if (feof(file)){
    break;}

    num = strod(demo,NULL);
    month[i] = num;
}
return month;
};
int main(){



}