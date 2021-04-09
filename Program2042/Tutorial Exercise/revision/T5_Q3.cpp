#include <iostream>
#include <iomanip>

using namespace std;
double bv;
int ev;
double integerPower()
{
    double answer = bv;
    if (ev == 0)
    {
        answer = 1;
        
    }
    else if (ev > 0)
    {
        for (int i = 1; i <= ev; i++)
        {
            answer *= bv;
        }
        answer /= bv;
    }
    else if (ev < 0)
    {
        for (int i = -1; i >= ev; i--)
        {
            answer *= bv;
        }
        answer /= bv;
        answer = 1 / answer;
    }

    return answer;
}

int main()
{
    cout << "Enter the base value: ";
    cin >> bv;
    cout << "Enter the exponent value: ";
    cin >> ev;
    cout << bv << " to the power " << ev << " is " << integerPower();
    return 0;
}