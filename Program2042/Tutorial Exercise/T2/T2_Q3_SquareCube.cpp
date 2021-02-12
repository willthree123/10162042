#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
float x;

int main()
{
    //Ask user to input a number
    cout << "Input a number : " ;
    cin >> x;

    // Perform calculate
    // Display the result with proper format
    cout << fixed << setprecision(3) << right; 
    cout << setw(6) << "x : " << setw(10) << x << "\n";
    cout << setw(6) << "x^2 : " << setw(10) << pow(x,2) << "\n";
    cout << setw(6) << "x^3 : " << setw(10) << pow(x,3) << "\n";
    
    // Code indicates the end of program
    return 0;
}

