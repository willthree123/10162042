#include <iostream>
#include <iomanip>
using namespace std;

// For Q1: from getinteger.cpp (print out array)
void printData(int list[], int size)
{
    cout << "The input integers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << list[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
}

// For Q2: from modified integer.cpp (print out array in bar)
void printBar(int list[], int size)
{
    cout << "The bar chart is: " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < list[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

//For Q2: from modified integer.cpp (print out array in bar)
void printData(int list[], int size)
{
    cout << "The random integers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << list[i];
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

//For Q3: from randomInteger.cpp (find the largest and the average of 100 random integers)
int sum = 0;

void printData(int list[], int size)
{
    cout << "The input integers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << list[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
}

int largest(int list[], int size)
{
    int ans = list[0];
    for (int i = 0; i < size; i++)
    {
        sum += list[i];
        if (ans < list[i])
            ans = list[i];
    }
    return ans;
}

double average(int list[], int size)
{
    double ans;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += list[i];
    ans = (double)sum / size;
    return ans;
}

// For Q4; from maxAppear.cpp (showing the most frequently appeared random integers)
void printData(int list[], int size)
{
    cout << "The input integers are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(5) << list[i];
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
}

void maxAppear(int list[], int size, int &max, int f[])
{

    for (int i = 0; i < size; i++)
    {
        f[list[i]]++; //frequency counting
    }

    max = 1;
    for (int i = 2; i <= 10; i++)
    {
        if (f[max] < f[i])
            max = i;
    }
}
