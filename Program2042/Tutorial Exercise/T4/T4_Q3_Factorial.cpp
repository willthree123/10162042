#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int input;
int answer = 0;

int main(){
    //Ask user to input an integer
    cout << "n: ";
    cin >> input;
    //Perform calculate 
    if (input == 0 || input == 1){ //If n = 0 or n = 1
        answer = 1;    
    }
    else{
        answer = input; 
        for(int i=1; i<input; i++){ //If n != 0 and n != 1
            answer = answer * i;
        }
    }
    //Display the result with proper format
    cout << input << "! = " << answer;
     
    //Code indicates the end of program
    return 0;
}   