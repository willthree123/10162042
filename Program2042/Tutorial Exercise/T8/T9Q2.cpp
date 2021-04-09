#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int SIZE = 20;
    int val[SIZE];
    int num;

    cout << "How many integers to enter? ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "? ";
        cin >> val[i];
    }

    cout << "The bar chart is: " << endl;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < val[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}