#include <iostream>
#include <iomanip>
using namespace std;

// (a) Implementation of class Account should be inserted here
class Account
{
public:
double balance;
	Account(double b)
	{
		balance = b;
	}
	void credit(double p)
	{
		balance += p;
	}
	void debit(double d)
	{
		balance -= d;
	}
	double getBalance()
	{
		return balance;
	}

	// Transfer money from a1 to a2, why pass-by-reference?
private:
	
};

void transfer(Account &a1, Account &a2)
{
	double tmp;
	cout << "How much to transfer:";
	cin >> tmp;
	if (a1.balance >= tmp)
	{
		cout << "Transfer completed." << endl;
		a1.balance -= tmp;
		a2.balance += tmp;
	}
	else
	{
		cout << "Insufficient balance." << endl;
	}
}
int main()
{
	Account peter(1000), mary(1500);
	int option;

	cout << fixed << setprecision(2); // 2 decimal places

	do
	{
		cout << "\n";
		cout << "Peter's balance: " << peter.getBalance() << endl;
		cout << "Mary's balance:  " << mary.getBalance() << endl;
		cout << "------\n";
		cout << "(1) Transfer money from Peter to Mary\n";
		cout << "(2) Transfer money from Mary to Peter\n";
		cout << "(3) Quit\n";
		cout << "Option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			transfer(peter, mary);
			break;
		case 2:
			transfer(mary, peter);
			break;
		case 3:
			cout << "Bye Bye.\n";
			break;
		default:
			cout << "Incorrect option.\n";
		}
	} while (option != 3);

	return 0;
}
