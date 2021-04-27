// To uppercase, this program turns lower case to upper case by means of ASCII dec calculation

#include <iostream>
using namespace std;

int main()
{

    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
        i++;
    }
    cout << "Converted string is: " << str << endl;
    
    return 0;
}