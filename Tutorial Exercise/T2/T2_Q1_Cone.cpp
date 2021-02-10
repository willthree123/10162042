#include <iostream>
#include <cmath>
using namespace std;

//Declare PI and other necessary variables
const double PI = 3.14159265;
double radius, height, volume;

int main()
{
    //Ask user to input radius and height
    cout << "Enter the radius (in cm) : " ;
    cin >> radius;
    cout << "Enter the height (in cm) : ";
    cin >> height;

    // Calculate the cone volume 
    volume = PI * pow(radius,2) * height * 1 / 3;

    // Display result
    cout << "The volume of the cone is " << volume << " cm^3";

    // Code indicates the end of program
    return 0;
}
