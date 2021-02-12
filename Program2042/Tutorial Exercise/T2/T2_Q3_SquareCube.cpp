#include <iostream>
#include <cmath>
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
    cout << fixed << setprecision(3); 
    cout << "x : " << x << "\n";
    cout << "x^2 : " << pow(x,2) << "\n";
    cout << "x^3 : " << pow(x,3) << "\n";
    
    // Code indicates the end of program
    return 0;
}

