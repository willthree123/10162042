#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int SIZE=20;
    int val[SIZE];
    int num;

    cout << "How many integers to enter? ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cout << "? ";
        cin >> val[i];
    }

    cout << "The input integers are: " << endl;
    for (int i = 0; i < num; i++)
    {
        cout << setw(5) << val[i];
        if ((i + 1) % 5 == 0)
            cout << endl;

    }
    cout<<endl;
    return 0;
}