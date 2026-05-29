#include <stdio.h>
#include <stdlib.h>

int main(){
char input[100];
float points;
while(1){
printf("Please input the score:\n");
scanf("%s",&input);
points = strtof(input,NULL);
if (points <=1){
        return 0;
}
int T_2=0, T_1=0,T,F=0,Safe=0;
T_2 = points/8;
T_1 = points/7;
T = points/6;
F = points/3;
Safe = points/2;
for (int i=0;i<=T_2;i++){
    for(int j=0;j<=T_1;j++){
        for(int k=0;k<=T;k++){
            for(int e=0;e<=F;e++){
                for(int a=0;a<=Safe;a++){
                    if(i*8+j*7+k*6+e*3+a*2==points){
                        printf("Possible Combinations of Scoring Plays:\n");
                        printf("%d TD + 2pt,\t%d TD + FG,\t%d TD,\t %d Three-pt FG, %d Safety\n",i,j,k,e,a);
                }
        }
}
}
}
}
}
}
