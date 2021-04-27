#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x = 1;
    int y[5] = {10, 20, 30, 40, 50};

    int *xPtr = &x;
    int *yPtr = &y[0];

    cout << "Address of x = " << &x << endl;
    cout << "Address of x = " << y << endl
         << endl;

    cout << "xPtr = " << xPtr << endl;
    cout << "yPtr = " << yPtr << endl
         << endl;

    cout << "*xPtr = " << *xPtr << endl;
    cout << "*yPtr = " << *yPtr << endl
         << endl;

    cout << "*yPtr + 2 = " << *yPtr + 2 << endl;
    cout << "*(yPtr + 2) = " << *(yPtr + 2) << endl
         << endl;

    xPtr = yPtr + 2;
    (*xPtr)++;
    (*yPtr)++;
    cout << "x = " << x << endl;
    cout << "*xPtr = " << *xPtr << endl;
    cout << "*yPtr = " << *yPtr << endl;
    cout << "*(yPtr + 2) = " << *(yPtr + 2) << endl;

    return 0;
}
