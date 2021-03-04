
#include <iostream>
using namespace std;

void nChar(int n, char c) 
{
	for (int i = 0; i < n; i++)
		cout << c;
}

int main(){
	for(int k = 1; k <= 3; k++){ //display 3 times
        for(int i = 1; i <= 5 ;i++){    //display 1 triangle
            nChar(5-i,' ');	
            nChar(i * 2 - 1, '*');
            cout << endl;	//Open a new line
        }
    }
	return 0;
}   