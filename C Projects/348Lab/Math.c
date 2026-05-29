#include <stdio.h>
#include <stdlib.h>

int *import(const char filename)
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

    num = strtod(demo,NULL);
    month[i] = num;
}
return month;
};

float min_element(float *report){
float min;
min = report[0];
for (int i=0; i<= 11; i++){
if(report[i]<min){
    min =report[i];
}
}
return min;
}

float max_element(float *report){
float max;
max = report[0];
for (int i=0; i<= 11; i++){
if(report[i]>max){
    max =report[i];
}
}
return max;
}

float average(float *report){
float average;
int total = 0;
for (int i=0; i<= 11; i++){
average += report[i];
total++;
}
average = average/total;
return average;
}

int position(float number,float *report){
int place;
for (int i=0; i<= 11; i++){
if (report[i]==number){
place = i;
break;
}
}
return place;
}

float moving_average(int start,float *report){
float average;
int total = 6;
for (int i=start; i<= start+5; i++){
average += report[i];
}
average = average/total;
return average;
}
float maximizer(int place,float *report){
float comparelist[12];
float newlist[12];
for (int i=0; i<= 11; i++){
comparelist[i]=report[i];
}
for (int j=0; j<=11;j++){
newlist[j] = max_element(comparelist);
comparelist[position(newlist[j],report)] = 0;
}
return newlist[place];
}

void salesreport(float *report){
printf("Monthly Sales Report for 2022:\n");
printf("Month\t\tSales\n");
char names[12][20] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
for (int i=0; i<= 11; i++){
    printf("%-10s\t$%f\n",names[i],report[i]);
}
printf("Sales Summary:\n");
printf("Minimum sales:$\t%-20f\t(%s)\n",min_element(report),names[position(min_element(report),report)]);
printf("Maximum sales:$\t%-20f\t(%s)\n",max_element(report),names[position(max_element(report),report)]);
printf("Average sales:$\t%-20f\n", average(report));

printf("Six-Month Moving Average Report:\n");
printf("%-20s\t%-20s\t$%f\n",names[0],names[5],moving_average(0,report));
printf("%-20s\t%-20s\t$%f\n",names[1],names[6],moving_average(1,report));
printf("%-20s\t%-20s\t$%f\n",names[2],names[7],moving_average(2,report));
printf("%-20s\t%-20s\t$%f\n",names[3],names[8],moving_average(3,report));
printf("%-20s\t%-20s\t$%f\n",names[4],names[9],moving_average(4,report));
printf("%-20s\t%-20s\t$%f\n",names[5],names[10],moving_average(5,report));
printf("%-20s\t%-20s\t$%f\n",names[6],names[11],moving_average(6,report));


printf("Sales Report(Highest to Lowest):\n");
printf("Month\t\tSales\n");
for (int i=0; i<= 11; i++){
float organized = maximizer(i,report);
printf("%-10s\t$%f\n",names[position(organized,report)],organized);
}
}

float salestest[] = {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};

int main()
{
char sales[100];
float saleslist[12];
float month;
printf("Please input file name for sales report:\n");
scanf("%s",&sales);
FILE* ptr = fopen(sales,"r");
if(ptr == NULL) {
    printf("No File Found.");
    return 0;
}
int i = 0;
while(fgets(sales,100,ptr)){
if (i<=11){
    month = strtof(sales,NULL);
    saleslist[i] = month;
    i++;
}
}
fclose(ptr);
salesreport(saleslist);
/*int i =0;
    while(fscanf(ptr,"%f",month)==1){
        if(i<=11){
        saleslist[i] = month;
        i++;}
        else{
            break;
            }
            }
*/
//salesreport(saleslist);
char dummy;
printf("Press any button to close");
scanf("%c",dummy);
return 0;

}
