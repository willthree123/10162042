#include <iomanip>
#include <iostream>

using namespace std;

class Account
{
public:
    Account(double money)
    {
        balance = money;
    }

    void credit(double money)
    {
        balance += money;
    }

    void debit(double money)
    {
        if (balance > money)
            balance -= money;
    }

    double getBalance()
    {
        return balance;
    }

private:
    double balance;
};
void transfer(Account &a1, Account &a2)
{
    double money;

    cout << "How much to transfer: ";
    cin >> money;

    if (a1.getBalance() >= money)
    {
        a1.debit(money);
        a2.credit(money);
        cout << "Transfer completed.\n";
    }
    else
        cout << "Insufficient balance.\n";
}

int main()
{
    Account peter(1000), mary(1500);
    int option;

    cout << fixed << setprecision(2);

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