#include <iostream>
using namespace std;

//Declare the necessary variables
int day;
int month;
int year;
float average;

int main()
{
    //Assign values to the variables
    day = 25;
    month = 12;
    year = 2020;
    
    // Perform the calculation
    average = (day + month + year) / 3.000;

    // Display the answer
    cout << "The average of "<<day<< "-" << month << "-" << year << " is " << average;

    // Code indicates the end of program
    return 0;
}
