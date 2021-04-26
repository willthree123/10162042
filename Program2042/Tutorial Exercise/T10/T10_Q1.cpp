#include <iostream>
#include <iomanip>
using namespace std;

int x = 1;
int y[5] = {10, 20, 40, 50};

int *xPtr = &x;
int *yPtr = &y[0];

int main()
{
    cout << "1a)" << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << y << endl;
    cout << endl;
    cout << endl;

    cout << "1b)" << endl;
    cout << "Value stored in xPtr: " << xPtr << endl;
    cout << "Value stored in yPtr: " << yPtr << endl;
    cout << endl;
    cout << endl;

    cout << "1c)" << endl;
    cout << "'*' means that pointer and de-pointer" << endl;
    cout << endl;
    cout << endl;

    cout << "1d)" << endl;
    cout << "(*yPtr + 2): " << (*yPtr + 2) << endl;
    cout << "*(yPtr + 2): " << *(yPtr + 2) << endl;
    cout << endl;
    cout << endl;

    cout << "1e)" << endl;

    cout << "Before: " << endl;
    cout << "xPtr:" << xPtr << "\t";
    cout << "yPtr:" << yPtr << endl;
    cout << "*xPtr:" << *xPtr << "\t";
    cout << "*yPtr:" << *yPtr << endl;
    xPtr = yPtr + 2;
    (*xPtr)++;
    (*yPtr)++;

    cout << endl;
    cout << "After: " << endl;
    cout << "xPtr:" << xPtr << "\t";
    cout << "yPtr:" << yPtr << endl;
    cout << "*xPtr:" << *xPtr << "\t";
    cout << "*yPtr:" << *yPtr << endl
         << endl;

    cout << "value of y[2]:" << y[2] << "\t";
    cout << "address of y[2]:" << &y[2] << "\t" << endl;

    return 0;
}
