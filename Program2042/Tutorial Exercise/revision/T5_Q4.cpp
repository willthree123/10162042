#include <iostream>
using namespace std;
char mode;
void nChar(int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        cout << c;
    }
}
void qa()
{
    int size = 5;
    for (int i = 1; i <= size; i++)
    {
        nChar(i, '*');
        cout << endl;
    }
}
void qb()
{
    int size = 5;
    for (int i = 1; i <= size; i += 1)
    {
        if (i != size)
        {
            nChar((size - i), ' ');
        }

        nChar(i, '*');
        cout << endl;
    }
}
void qc()
{
    int size = 9;
    for (int i = 1; i <= size; i += 2)
    {
        nChar(((size - i) / 2 + 0.5), ' ');
        nChar(i, '*');
        cout << endl;
    }
}
void qd()
{
    int size = 9;
    for (int i = 1; i <= size; i += 2)
    {
        nChar(((size - i) / 2 + 0.5), ' ');
        nChar(i, '*');
        cout << endl;
    }
    for (int i = (size - 2); i >= 1; i -= 2)
    {
        nChar(((size - i) / 2), ' ');
        nChar(i, '*');
        cout << endl;
    }
}
void qe()
{
    int size = 9;
    int time = 3;
    for (int j = 1; j <= time; j += 1)
    {
        for (int i = 1; i <= size; i += 2)
        {
            nChar(((size - i) / 2 + 0.5), ' ');
            nChar(i, '*');
            cout << endl;
        }
    }
}
void choose()
{
    cout << "Input (a) to (e)" << endl;
    cout << "Enter Mode: ";
    cin >> mode;
    switch (mode)
    {
    case 'a':
        qa();
        break;
    case 'b':
        qb();
        break;
    case 'c':
        qc();
        break;
    case 'd':
        qd();
        break;
    case 'e':
        qe();
        break;
    case 'q':
        cout<<"bye bye";
        return;
    default:
        cout << "Enter again" << endl;
        break;
    }
    choose();
}
int main()
{
    choose();
}