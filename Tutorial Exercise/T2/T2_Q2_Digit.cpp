#include <iostream>
#include <cmath>
using namespace std;

//Declare the necessary variables
int digitalOne, digitalTwo, input;

int main()
{
    //Ask user to input an integer within 00-99
    cout << "Enter a two-digit integer (00-99) : " ;
    cin >> input;

    // Calculate the two digits
    digitalOne = input / 10; 
    digitalTwo = input % 10;
    
    // Display result
    cout << "The two digits are " << digitalOne << " and " << digitalTwo;

    // Code indicates the end of program
    return 0;
}
