#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

double PI, tmpTermsValue;
double perviousPI = 0;
int terms = 1;
int low, high;
int runTime = 0;
bool reverse ; //true is +

void firstColumnPrint(string x){
    cout << right << setw(10) << x ;
}
void secondeColumnPrint(string x){
    cout << right << setw(20) << x << endl;
}
void secondeColumnDounlePrint(double x){
    cout << setprecision(15);
    cout << right << setw(20) << x << endl;
}

void headerPrint(){
    firstColumnPrint("Terms");
    secondeColumnPrint("Value of PI");
    firstColumnPrint("-----");
    secondeColumnPrint("-----------");
}

void calPI(){
    if( terms == 1 ){
        low = terms;
    }    
    else{
        low = terms + 1;
    }
    terms = terms*10;
    high = terms;

    for(int i = low; i <= high; i++){
        int divide = i * 2 - 1;
        tmpTermsValue = 4.0 / divide;
        //cout << tmpTermsValue << " ";
        if( i == 1 ){
            PI = 4.0;
            reverse = false;
        }
        else{
            if(reverse == false){
                PI = PI - tmpTermsValue;
                reverse = true;
            }
            else{
                PI = PI + tmpTermsValue;
                reverse = false;
            }
        }
    }
}

int main(){
    cout << fixed;
    headerPrint();
    calPI(); //Terms: 10
    firstColumnPrint(to_string(terms));
    secondeColumnDounlePrint(PI);
    calPI(); //Terms: 100
    firstColumnPrint(to_string(terms));
    secondeColumnDounlePrint(PI);    
    calPI(); //Terms: 1000
    firstColumnPrint(to_string(terms));
    secondeColumnDounlePrint(PI);
    calPI(); //Terms: 10000
    firstColumnPrint(to_string(terms));
    secondeColumnDounlePrint(PI);
    calPI(); //Terms: 100000
    firstColumnPrint(to_string(terms));
    secondeColumnDounlePrint(PI);        

    //Code indicates the end of program
    return 0;
}   