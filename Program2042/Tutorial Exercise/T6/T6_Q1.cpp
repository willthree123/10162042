#include <iostream>
#include <cmath>
using namespace std;
// Function prototype is inserted here
double x, y, result;

double hypoten(double a, double b){
    double tmp = (a * a) + (b * b);
    tmp = sqrt(tmp);
    return tmp;
}

int main(){
    cout << "Please enter the length of first side: ";
    cin >> x;
    cout << "Please enter the length of second side: ";
    cin >> y;
    result = hypoten(x, y);
    cout << "Hypotenuse of a "<< x <<" by "<< y <<" right triangle is "<< result;
	return 0;
}

// Function definition is inserted here