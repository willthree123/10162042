#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
float baseValue, exponentValue; //To store user inputs
float answer = 0; //To store answer

int main(){
    //Ask user to input an integer
    cout << "Enter the base value: ";
    cin >> baseValue;
    cout << "Enter the exponent value: ";
    cin >> exponentValue;

    answer = baseValue;
    //Perform calculate
    if(exponentValue<0){
        exponentValue = sqrt(exponentValue * exponentValue);
        for(int i = 1; i < exponentValue; i++){
            answer = answer * baseValue;
        }
        exponentValue = exponentValue * -1;
        answer = 1 / answer;
    }
    else{
        for(int i = 1; i < exponentValue; i++){
            answer = answer * baseValue;
        }
    }
    //Display the result with proper format
    cout << baseValue << " to the power " << exponentValue << " is " << answer;
     
    //Code indicates the end of program
    return 0;
}   