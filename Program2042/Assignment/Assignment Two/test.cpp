#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.141592654;
// (c) Prototypes of the two functions

double triangle(double a, double b, double c){
    double answer=0;
    cout<< sin(c)<<" ";
    return (0.5*a*b);
}

double cube(double &l,double &a,double &v){
    a=l*l*6;
    v=l*l*l;
}

int main()
{
    double triA, triB, triC, cuLen, cuArea, cuVol;
    cout<<triangle(12.34,23.45,34.56);
  /*  cout << "Input side A (cm) : ";
    cin >> triA;
    cout << "Input side B (cm) : ";
    cin >> triB;
    cout << "Input angle C (degree): ";
    cin >> triC;
    cout << "Triangle area is " << triangle(triA, triB, triC) << " cm^2\n\n";
    cout << "Input length (cm): ";
    cin >> cuLen;
    cube(cuLen, cuArea, cuVol);
    cout << "Cube surface area is " << cuArea << " cm^2\n";
    cout << "Cube volume is " << cuVol << " cm^3";*/
    return 0;
}

