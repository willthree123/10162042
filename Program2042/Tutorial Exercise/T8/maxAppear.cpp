#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int RANGE = 10;
    const int SIZE = 100;

    int val[SIZE] = {}, freq[RANGE + 1] = {}; //ignore freq[0]
    int seed, max;

    cout << "Please enter the seed value: ";
    cin >> seed;
    srand(seed);

    for (int i = 0; i < SIZE; i++)
    {
        val[i] = 1 + rand() % RANGE; //generating numbers ranging from 1 to 10
    }

    cout << "The random integers are: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(5) << val[i];
        freq[val[i]]++; //frequency counting
        if ((i + 1) % 10 == 0)
            cout << endl; //10 numbers every row
    }

    max = 1;
    for (int i = 2; i <= RANGE; i++)
    {
        if (freq[max] < freq[i])
            max = i;
    }
    cout << max << " appears the most with " << freq[max] << " times\n";
    return 0;
}