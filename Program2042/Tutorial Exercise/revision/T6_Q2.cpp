#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void sumAvg(int lower, int upper, int &sum, float &average)
{
    int count=0;
    sum=0;
    for (int j = lower; j <= upper; j++)
    {
        sum = sum + j;
        count++;
    }
    average = sum / (double)count;
}
int main()
{
    int lower, upper, sum;
    float average;
    cout << "Enter the lower bound: ";
    cin >> lower;
    cout << "Enter the upper bound: ";
    cin >> upper;
    sumAvg(lower, upper, sum, average);
    cout << "From " << lower << " to " << upper << ":\n";
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    return 0;
}
