#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265;
int main(){
    cout<<setprecision(4)<<fixed;
    cout<<"Degree\t\t"<<"Sin\t\t"<<"Cos\t\t"<<endl;
    for (int i=0; i<=360;i+=10){
        double tmp;
        tmp=i*(PI/180);
        cout<<noshowpos<<right<<setw(3)<<i<<"\t\t"<<showpos<<left<<sin(tmp)<<"\t\t"<<cos(tmp);
        cout<<endl;
    }    
}
