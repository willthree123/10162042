#include <iostream>
using namespace std;

// Function prototype is inserted here
int count;

float sumAvg(int &a, int &b, int &s, float &div)
{
	s = 0;
	div = 0;
	for (int i = a; i <= b; i++)
	{
		s += i;
	}
	div = (a + b)/2.00000;
	return div, s;
}

int main()
{
	int lower, upper, sum;
	float average;

	cout << "Enter the lower bound: ";
	cin >> lower;
	cout << "Enter the upper bound: ";
	cin >> upper;

	sumAvg(lower, upper, sum, average);

	cout << "From " << lower << " to " << upper << ":\n";
	cout << "Sum     = " << sum << endl;
	cout << "Average = " << average << endl;

	return 0;
}

// Function definition is inserted here