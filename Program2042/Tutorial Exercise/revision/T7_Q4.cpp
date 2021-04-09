#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Implement the Phone class here
class Phone
{
public:
	Phone(string n, string v)
	{
		b = n;
		os = v;
	}
	void setPrice(int p)
	{
		price = p;
	}
	void showConfig()
	{
		cout << left << setprecision(2) << fixed;
		cout << setw(8) << "Brand:" << b << endl;
		cout << setw(8) << "OS:" << os << endl;
		cout << setw(8) << "Price:"
			 << "$" << (float)price * 1.0 << endl;
	}

private:
	int price;
	string b;
	string os;
};

int main()
{
	Phone iPhone("Apple", "iOS version 6");
	Phone noteTwo("Samsung", "Android 4.1");

	iPhone.setPrice(5588);
	noteTwo.setPrice(4630);

	cout << "Specification of iPhone:" << endl;
	iPhone.showConfig();
	cout << "\nSpecification of Note 2:" << endl;
	noteTwo.showConfig();

	return 0;
}