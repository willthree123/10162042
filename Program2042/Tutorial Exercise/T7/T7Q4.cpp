#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
    Phone(string b, string o)
    {
        brand = b;
        os = o;
    }

    void showConfig()
    {
        cout << "Brand:\t" << brand << endl;
        cout << "OS:\t" << os << endl;
        cout << "Price:\t$" << setprecision(2) << fixed << price << endl;
    }

    void setPrice(double p)
    {
        price = p;
    }

private:
    string brand;
    string os;
    double price;
};

int main()
{
    Phone iPhone("Apple", "iOS verison 6");
    Phone noteTwo("Samsung", "Android 4.1");

    iPhone.setPrice(5588);
    noteTwo.setPrice(4630);

    cout << "Specification of iPhone:" << endl;
    iPhone.showConfig();
    cout << "\nSpecification of Note 2:" << endl;
    noteTwo.showConfig();

    return 0;
}