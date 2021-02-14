#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int input;
int answer = 31; //assume the answer is 31

int main(){
    //UI cout
    cout << "I have a number between 1 and 100.\n" << "Can you guess my number?";

    while(input!=answer){ //while user input incorrect answer
    //Ask user to input a number
    cout << "\nGuess : " ;
    cin >> input;
        if(input>answer){ //If user input a number larger than the answer
            cout << "Too high. Try again.";
        }
        else if(input<answer){ //If user input a number smaller than the answer
            cout << "Too low. Try again.";
        }
        else{ //If user input the correct answer
            cout << "Excellent! Correct guess.";
        }
    }

    // Perform conditional operator
    return 0;
}