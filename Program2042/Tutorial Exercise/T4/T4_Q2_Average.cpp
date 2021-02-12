#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int input; //User input
float answer; //Output answer
float counter = 0.000; //Count how many positive number(s) was/were typed
int exitNum = 0; //The exitNumber is 0

int main(){
    cout << fixed << setprecision(3); 
    
    //Ask user to input an integer
    cout << "Input an integer: ";
    cin >> input;

    while(input != exitNum){ //while user input incorrect answer
        if(input > 0){ //If user input a positive number
            counter += 1.000; //positive counter + 1
            answer += input; //puts the input number to answer
        }
        //Ask user to input an integer
        cout << "Input an integer: ";
        cin >> input;
    }
    //Perform calculate (Average)
    //Display the result with proper format
    answer = answer / counter;
    cout << "Average of all positive values is " << answer;
     
    //Code indicates the end of program
    return 0;
}