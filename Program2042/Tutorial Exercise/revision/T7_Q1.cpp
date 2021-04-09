#include <iostream>
using namespace std;

class date
{
public:
	void setDate(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void print()
	{
		cout << day << "-" << month << "-" << year;
	}

private:
	// Declare private data members
	int day;
	int month;
	int year;
};

int main()
{
	// Create an object called xmas
	date xmas;
	xmas.setDate(25, 12, 2013);
	cout << "xmas is: ";
	// Use xmas object to call print()
	xmas.print();
	cout << endl;
	return 0;
}
