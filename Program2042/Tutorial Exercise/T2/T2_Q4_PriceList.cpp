#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Declare the necessary variables
string productName1, productName2, productName3;
int productPrice1, productPrice2, productPrice3;

int main()
{
    //Ask user to input the product information one by one
    cout << "Name of product 1: " ;
    cin >> productName1;
    cout << "Price of " << productName1<<": " ;
    cin >> productPrice1;
    cout << "\n";

    cout << "Name of product 2: " ;
    cin >> productName2;
    cout << "Price of " << productName2<<": " ;
    cin >> productPrice2;    
    cout << "\n";

    cout << "Name of product 3: " ;
    cin >> productName3;
    cout << "Price of " << productName3<<": " ;
    cin >> productPrice3;    
    cout << "\n";

    // Perform calculate
    // Display the result with proper format
    cout << left;
    cout << setw(15) << "Product" << setw(5) << "Price" <<"\n" << "--------------------";
    cout << "\n" << setw(15) << productName1 << setw(5) << productPrice1;
    cout << "\n" << setw(15) <<productName2 << setw(5) << productPrice2;
    cout << "\n"<< setw(15) << productName3 << setw(5) << productPrice3;
        
    // Code indicates the end of program
    return 0;
}

