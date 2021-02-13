#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double PI;
int terms = 1;
int low, high;
int perviousPI = 0;
int runTime = 0;
bool reverse = true; //true is +

void firstColumnPrint(String x){
    cout << right << setw(10) << x ;
}
void secondeColumnPrint(String x){
    cout << right << setw(20) << x << endl;
}
void headerPrint(){
    firstColumnPrint("Terms");
    secondeColumnPrint("Value of PI");
    firstColumnPrint("-----");
    secondeColumnPrint("-----------");
}

int calPI(){
    //perviousPI = ;
    low = terms;
    terms = terms*10;
    high = terms;
    
    for(int i = low; i < high; i++){
        int divide = i * 2 - 1;
        if( low == 1){
            PI = 4 / low;
        }
        else{
        PI = PI - 4 / divide;
        }
    }
    perviousPI = PI;
}

int main(){
    cout << setprecision(15);
    headerPrint();
    calPI();
    firstColumnPrint(terms);
    secondeColumnPrint(PI);


    //Code indicates the end of program
    return 0;
}   