#include <iostream>
#include <cmath>
using namespace std;

double hypoten(double x, double y)
{
    double tmp = sqrt(x*x + y*y);
    return tmp;
}
double x, y, a;
int main()
{
    cout << "Please enter the length of first side: ";
    cin >> x;
    cout << "Please enter the length of second side: ";
    cin >> y;

    a = hypoten(x, y);
    cout << "Hypotenuse of a " << x << " by " << y << " right triangle is " << a;
    return 0;
}