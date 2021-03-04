#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int inputA, inputB; //To store user inputs
int largerNum, smallerNum; //To store largerNumber and smallerNumber
int answer = 0; //To store answer

int main(){
    //Ask user to input an integer
    cout << "Please input value A: ";
    cin >> inputA;
    cout << "Please input value B: ";
    cin >> inputB;

    //Sort two input and store them into largerNumber and smallerNumber
    if (inputA > inputB){
        largerNum = inputA;
        smallerNum = inputB; 
    }
    else{
        largerNum = inputB;
        smallerNum = inputA; 
    }
    
    //Perform calculate 
    for (int i = smallerNum; i <= largerNum; i ++){
        if(i%2==1){
            answer += i;
        }
    }

    //Display the result with proper format
    cout << "Sum of odd integers " << inputA << " to " << inputB << " is " << answer;
     
    //Code indicates the end of program
    return 0;
}   
