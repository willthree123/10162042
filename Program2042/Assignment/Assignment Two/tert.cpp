#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
unsigned int number_of_digits = 0;
int n = 1;
do
{
    ++number_of_digits;
    n /= base;
} while (n);
}