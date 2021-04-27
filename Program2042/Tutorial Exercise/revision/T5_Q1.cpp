#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;
int main(){
    cout<<"Degree\t\t"<<"Sin\t\t"<<"Cos\t\t"<<endl;
    for (int i=0; i<=360;i+=10){
        double tmp;
        tmp=i*(PI/180);
        cout<<i<<"\t\t"<<sin(tmp)<<"\t\t"<<cos(tmp);
        cout<<endl;
    }    
}
