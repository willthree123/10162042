#include <iostream>
#include <cmath>
using namespace std;

//Declare the necessary variables
int year;

int main(){
    //Ask user to input a number
    cout << "Input a year : " ;
    cin >> year;

    // Perform conditional operator
    // Display the result with proper format
    cout << "Is " << year << " a leap year? ";
    
    if ( ( (year%4==0) && (year%100!=0) ) || (year%400==0) ){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    


    // Code indicates the end of program
    return 0;
}

