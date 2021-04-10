#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int countDigit(int num, int digit)
{
    // (c) implement function countDigit() using recursion
    
    
}
int main()
{
    int num, digit;
    // (a) use current time as seed
    srand(time(0));
    cout << "Enter a non-negative integer: ";
    cin >> num;
    // (b) assign digit with a random number
    digit = 2 * (1 + rand() % 4);
    cout << "Random digit (even 1-9): " << digit << endl;
    cout << digit << " appears " << countDigit(num, digit) << " time(s)";
    return 0;
}