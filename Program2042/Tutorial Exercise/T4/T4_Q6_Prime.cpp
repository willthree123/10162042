#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int counter = 4;
int array[counter] = {12377, 723, 39, 43};

void print(){
    for(int i = 0; i <= counter; i++){
        
        cout << array[i];
        if( i % 10 == 0 ){
            cout << "\n";
        }
    }
}

int main(){
    cout << right;
    
    //Perform calculate

    //Display the result with proper format
    cout << baseValue << " to the power " << exponentValue << " is " << answer;
     
    //Code indicates the end of program
    return 0;
}   