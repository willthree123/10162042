#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//Declare the necessary variables
int degree;
double sinValue, cosValue;
double radian;


void printValue(double x){
    //Display the result with proper format
    cout << left << showpos << "\t\t" << x;
}

int main(){
    //Display header
    cout << setw(5) << setprecision(4) << fixed << right;
    cout << "Degree" << "\t\t" << "Sin" << "\t\t" << "Cos" << endl;
    do
    {
        cout << setw(3) << right << noshowpos << degree;
        //Perform calculate
        radian = degree * (M_PI/180);
        sinValue = sin(radian);
        cosValue = cos(radian);
        
        //Display the result with proper format
        printValue(sinValue);
        printValue(cosValue);
        cout << endl;
        degree += 10;
    } while (degree <= 360 );
    
    


    //Code indicates the end of program
    return 0;
}