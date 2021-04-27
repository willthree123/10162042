#include <iomanip>
#include <iostream>
// (a) include necessary header file(s)
using namespace std;
int main()
{
    int min, max, m;
    // (b) prompt for user input of min, max and m
    min = 4;
    max = 10;
    m = 3;
    // (c) find average of specific numbers and display in 2 d.p.
    int count;
    int sum = 0;
    for (int i = min; i <= max; i++)
    {
        sum += min;
        count++;
    }

    else
    {
        cout << setprecision(2) << fixed;
        cout << "Average is " << (min + max) / 2.00;
    }

    return 0;
}
