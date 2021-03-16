#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double PI;

double calcPI(int terms)
{
    if (terms == 1)
    {
        return 4.0 / 1;
    }
    else if (terms % 2 == 0)
    {
        return calcPI(terms - 1) - 4.0 / (terms * 2 - 1);
    }
    else
    {
        return calcPI(terms - 1) + 4.0 / (terms * 2 - 1);
    }
}

int main()
{
    int input;
    double result;
    cout << "How many terms for PI: ";
    cin >> input;
    cout << fixed << setprecision(15);
    result = calcPI(input);
    cout << "PI with " << input << " terms is " << result;
    //Code indicates the end of program
    return 0;
}