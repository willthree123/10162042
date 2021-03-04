#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

double PI, tmpTermsValue;
int terms = 1;
int low, high;
int runTime = 0;
bool reverse; //true is +

void calPI()
{
    if (terms == 1)
    {
        low = terms;
    }
    else
    {
        low = terms + 1;
    }
    terms = terms * 10;
    high = terms;

    for (int i = low; i <= high; i++)
    {
        int divide = i * 2 - 1;
        tmpTermsValue = 4.0 / divide;
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
}

int main()
{
    cout << "How many terms for PI: ";
    cin >> terms;
    cout << fixed << setprecision(15);
    calPI();
    cout << PI;
    //Code indicates the end of program
    return 0;
}