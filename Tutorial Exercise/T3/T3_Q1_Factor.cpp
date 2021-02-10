#include <iostream>
#include <cmath>
using namespace std;

//Declare the necessary variables
int x, y;

int main(){
    //Ask user to input a number
    cout << "Input x : " ;
    cin >> x;
    cout << "Input y : ";
    cin >> y;

    // Perform conditional operator
    // Display the result with proper format
    if (y%x==0){
        cout << x <<" is a factor of "<< y;
    }
    else{
        cout << x <<" is not a factor of "<< y;
    }
    


    // Code indicates the end of program
    return 0;
}

