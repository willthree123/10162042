#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int counter = 0;
int storeArray [] = {};

void print(){ //to print out every prime number
    for(int i = 0; i < counter; i++){ //for every NOTNULL address
        if( i % 10 == 0 && i != 0){ //if its the 10th number print
            cout << "\n"; //print a new line
        }
        cout << setw(5) << storeArray [i]; //print the current address prime number
    }
}

void getPrimeNumber(){  //get all the prime number between 1 to 200
    for(int k = 1; k <= 200; k++){ //check every number between 1 to 200
        int tmp = k/2;  //divide and store the current checking number 
        bool primeSta; //true if the number is a prime number
        primeSta = true; //assume its a prime number
        for(int i = 2; i <= tmp; i++){   //for every
            if(k % i == 0){   
                primeSta = false;    //if it has factor(s), then its not a prime number
                break;  //break the current for loop
            }
        }
        if (primeSta == true && k != 1){ //if the current checking number is a prime number and the current number is not 1
            storeArray [counter] = k; //store the current checking number to "storeArray"
            counter++; //counter++, array address++
        }
    }
}

int main(){
    cout << right; //setting the cout to align right
    getPrimeNumber(); //get all prime number between 1 to 200
    print(); //print all prime numbers
     
    //Code indicates the end of program
    return 0;
}   