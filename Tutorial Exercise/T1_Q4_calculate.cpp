#include <iostream>
#include <cmath>  
using namespace std;

//Declare the necessary variables
int x;
float firsthalf;
float secondhalf;
float answer;

int main()
{
    //Assign values to the variables
    x=5;
    
    // Perform the calculation
    firsthalf = (3+4*x)/10.00;
    secondhalf = (10*pow((x-2),2)/(x-3.00));
    answer =  pow((firsthalf-secondhalf),2);

    // Display the answer
    cout << "The answer when x="<< x << " is " << answer;

    // Code indicates the end of program
    return 0;
}