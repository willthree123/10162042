#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
int counter = 0;
int storeArray [] = {};

void print(){
    for(int i = 0; i < counter; i++){
        if( i % 10 == 0 && i != 0){
            cout << "\n";
        }
        cout << setw(5) << storeArray [i];
    }
}

void getPrimeNumber(){  
    for(int k = 1; k <= 200; k++){
        int tmp = k/2;  
        bool primeSta;
        primeSta = true;
        for(int i = 2; i <= tmp; i++){  
            if(k % i == 0){  
                primeSta = false;    
                break;  
            }
        }
        if (primeSta == true && k != 1){
            storeArray [counter] = k;
            counter++;
        }
    }
}

int main(){
    cout << right;
    getPrimeNumber();
    print();
     
    //Code indicates the end of program
    return 0;
}   