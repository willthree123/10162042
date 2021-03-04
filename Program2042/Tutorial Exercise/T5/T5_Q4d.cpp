
#include <iostream>
using namespace std;

void nChar(int n, char c) 
{
	for (int i = 0; i < n; i++)
		cout << c;
}

int main(){
	for(int i = 1; i <= 5 ;i++){ //display the upper part of the triangle
        //Display the result with proper format
		nChar(5-i,' ');	
		nChar(i * 2 - 1, '*');
		cout << endl;	//Open a new line
	}
	for(int i = 4; i >= 1 ;i--){ //display the lower part of the triangle
        //Display the result with proper format
		nChar(5-i,' ');	
		nChar(i * 2 - 1, '*');
		cout << endl;	//Open a new line
	}

	return 0;
}   