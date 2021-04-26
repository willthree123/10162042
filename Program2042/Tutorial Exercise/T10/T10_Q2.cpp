#include <iostream>
using namespace std;

// Function definition of swapInteger here...
void swapInteger(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main()
{
	int x = 2, y = 5;

	cout << "Before swapping:" << endl;
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;

	// call swapInteger here...
	swapInteger(&x, &y);

	cout << "After swapping:" << endl;
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;

	return 0;
}
