#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int change_value(int& v){
int choice;
cin >> choice;
v = choice;
return choice;
}
int findn(string filename1)
{
ifstream file1(filename1);
string line;

int num;

int place=0;
    int j = 0;
    int k = 0;
ifstream file1B(filename1);
    while(file1B>>num)
    {
    j = j +1;
    }
j = j/2;
k = sqrt(j);
cout<<"These are: " << k << " by " << k << " Matrices";
return k;
}
calc(string filename1,int N){
    //Getting Matrix 1
int run = 1;
ifstream file1(filename1);
int num;

int place=0;
    cout << endl;
    int Mat3[N][N];
    int Copy[N][N];
    int Array1[N][N];
    int Array2[N][N];
    int* ptr;
    int j = 0;
    int k = 0;
    int x = 0;
    int z = 0;
ifstream file1B(filename1);
    while(file1B>>num)
    {
        if (place<N){
        Array1[j][k] = num;
        k= k + 1;
        if (k>=N)
        {
            k = 0;
            j = j + 1;

        place = place + 1;
        }
        }


        else{
        Array2[x][z] = num;
        z = z+1;
        if(z>=N)
        {
            z = 0;
            x = x + 1;
        }
        }
    }
while(run==1){


cout<<"What would you like to do now?"<<endl<<"1: Print the Matrices" <<endl<<"2: Add the input Matrices"<<endl<<"3: Multiply the input Matrices"<<endl<<"4: Subtract the input Matrices"<<endl<<"5:Change the first value of the first input Matrix"<<endl<<"6:Get the Max Value of the first input Matrix"<<endl<<"7:Transpose the First input Matrix"<<endl<<"8: Quit"<<endl;
string choice;
cin >> choice;
if (choice == "1"){
    cout<<endl;
    cout<<"1rst Matrix Below: " << endl;
    for(int i = 0; i < N; i++){
            cout<< endl;
        for (int z = 0; z < N; z++){
            cout<<Array1[i][z]<<" ";
        }
    }
    cout<<endl;
    cout<<"2nd Matrix Below: " << endl;
    for(int i = 0; i < N; i++){
            cout<< endl;
        for (int z = 0; z < N; z++){
            cout<<Array2[i][z]<<" ";
        }

    }
        cout<<""<<endl;
}
if (choice == "2"){
cout<<endl;
cout<<"Sum of the Matrices: "<<endl;
for(int i = 0; i < N; i++){
    cout<< endl;
    for (int z = 0; z < N; z++){
        Mat3[i][z] = Array1[i][z] + Array2[i][z];
        cout<< Mat3[i][z]<<" ";
    }

}
    cout<<""<<endl;
}
if (choice == "3"){
        cout<<endl;
cout<<"Product of the Matrices: "<<endl;
for(int i = 0; i < N; i++){
    cout<< endl;
    for (int z = 0; z < N; z++){
        Mat3[i][z] = Array1[i][z] * Array2[i][z];
        cout<<Mat3[i][z]<<" ";
    }
}

    cout<<""<<endl;
}
if (choice == "4"){
        cout<<endl;
cout<<"Difference of the Matrices: "<<endl;
for(int i = 0; i < N; i++){
    cout<< endl;
    for (int z = 0; z < N; z++){
        Mat3[i][z] = Array1[i][z] - Array2[i][z];
        cout<<Mat3[i][z]<<" ";
    }
    cout<<""<<endl;
}
}
if (choice == "5"){
            cout<<endl;
int col;
int row;
cout<<"Enter row:"<<endl;
cin >> row;
cout<<"Enter Col:"<<endl;
cin >> col;
cout<<endl;
if (col+row > 2*N){
    cout<<"Row or Column is outside the bounds!"<<endl;
}
else{
cout<<"The New First Matrix is: "<<endl;
change_value(Array1[row-1][col-1]);
cout<<""<<endl;
for(int i = 0; i < N; i++){
        cout<<endl;
    for (int z = 0; z < N; z++){
        cout<<Array1[i][z]<<" ";

}
}
}
}
if (choice == "6") {
int maxvalue = 0;
for(int i = 0; i < N; i++){
    for (int z = 0; z < N; z++){
        if(Array1[i][z]>maxvalue){
            maxvalue = Array1[i][z];
        }

    }
}
cout<<"Max Value is:"<<endl;
cout<<maxvalue<<endl;
}
if (choice == "7") {
cout << "The Transposed First array is:"<<endl;
for(int i = 0; i < N; i++){
    for (int z = 0; z < N; z++){
        Mat3[z][i] = Array1[i][z];
    }
}
for(int i = 0; i < N; i++){
        cout<<endl;
    for (int z = 0; z < N; z++){
        Array1[i][z] = Mat3[i][z];
        cout<<Array1[i][z]<<" ";

    }
}
cout<<endl;
}
if (choice == "8") {
run = 0;
}
}
return 0;
}


int main()
{
cout<<"Enter Filename: ";
string str;
cin >> str;
int N = findn(str);
calc(str,N);

return 0;
}
