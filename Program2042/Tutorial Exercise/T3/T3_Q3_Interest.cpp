#include <iostream>
#include <cmath>
using namespace std;

//Declare the necessary variables
int principalValue, customerType, InterestRate;

int main(){
    //Ask user to input a number
    cout << "What is the principal value? " ;
    cin >> principalValue;
    cout << "Please enter the customer type: " ;
    cin >> customerType;

    // Perform conditional operator
    // Display the result with proper format
    cout << "Interest payable after one year: ";
    if (customerType==0){
        cout << "$" << principalValue*0.005;
    }
    else if (customerType == 1){
        cout << "$" << principalValue*0.008;
    }
    else if (customerType == 2){
        cout << "$" << principalValue*0.01;
    }
    else if (customerType == 3){
        cout << "$" << principalValue*0.012;
    }
    else if (customerType == 4){
        cout << "$" << principalValue*0.02;
    }
    else{
        cout << "Error in customer type";
    }   

    // Code indicates the end of program
    return 0;
}

