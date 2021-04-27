#include <iostream>
#include <cstring>
using namespace std;

void swapString(char[], char[]); // prototype

int main()
{

	char w1[20], w2[20];

	cout << "Enter the two words (separated by space): ";
	cin >> w1;
	cin >> w2;

	cout << "Before swapping, words are:\n";
	cout << w1 << endl
		 << w2 << endl;

	// Function call on swapString
	// Insert your code here
	swapString(w1, w2);

	cout << "After swapping, words are:\n";
	cout << w1 << endl
		 << w2 << endl;

	return 0;
}

// Function definition of swapString
// Insert your codes here
void swapString(char s1[], char s2[])
{
	int i=0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		char t = s1[i];
		s1[i] = s2[i];
		s2[i] = t;
		i++;
	}
	//C string method
	/*strcpy (t,w1);
	strcpy (w1,w2);
	strcpy (w2,t);*/
}