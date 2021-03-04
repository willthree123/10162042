#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calcPI(int terms)
{
    int low = 1;
    int high = terms;
    double PI;
    bool reverse; //true is +
    for (int i = low; i <= high; i++)
    {
        int divide = i * 2 - 1;
        double tmpTermsValue = 4.0 / divide;
        //cout << tmpTermsValue << " ";
        if (i == 1)
        {
            PI = 4.0;
            reverse = false;
        }
        else
        {
            if (reverse == false)
            {
                PI = PI - tmpTermsValue;
                reverse = true;
            }
            else
            {
                PI = PI + tmpTermsValue;
                reverse = false;
            }
        }
    }
    return PI;
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