// SEHH2042 Assignment 1
// Program template file: A1Template.cpp
// Do not modify the given codes

// Insert more header files when necessary
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void showInfo()
{
	// Fill in your personal particulars below
	cout << "Name      : Kok Siu Chung\n";
	cout << "Student ID: 20190875A\n";
	cout << "Class     : 202B\n";
}

void Q1() //Question 1
{
    //Declare the necessary variables
    double inputX, inputY, centroidX, centroidY;
    
    //Set cout result in 2 decimal places and use "Fixed-point format"
    cout<< setprecision(2);
    cout<< fixed;

	//Ask user to input the coordinates
    cout <<"Input x: ";
    cin >> inputX; //Input x
    cout << "Input y: ";
    cin >> inputY; //Input y
    
    // Perform calculate
    //The three cooredinates are (0, 0) (inputX, 0) (inputX, inputY)
    centroidX = ( (inputX+0+inputX)/3 );
    centroidY = ( (inputY+0+0)/3 );

    // Display the result with proper format
    cout << "Centroid is at (" << centroidX << "," << centroidY << ")";
    // The end of question
}

void Q2() //Question 2
{
    //Declare the necessary variables
    double a, b, c, ansOne, ansTwo;
    
    //Set cout result in 2 decimal places and use "Default format"
    cout<< defaultfloat;
    cout<< setprecision(6);

	//Ask user to input the coordinates
    cout <<"Enter a b c: ";
    cin >> a >> b >> c; //Input a b c

    //Calcuate if there is/are any solution
    if( pow(b,2)-(4*a*c)>0 ){ //If there is/are any solution

        //Calcuate Answer
        ansOne = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
        ansTwo = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
        // Display the result with proper format
        cout<<ansOne<<" "<<ansTwo;
    }
    else if ( pow(b,2)-(4*a*c)==0 ) { //If there is only one solution
        //Calcuate Answer
        ansOne = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
        // Display the result with proper format
        cout<<ansOne;
    }
    else { //There is/are no solution
        // Display the result with proper format
        cout<<"No solution";
    }
    // The end of question
}

void Q3() //Question 3
{
    //Declare the necessary variables
    int Amount;
    int day = 0;
    
	//Ask user to input the coordinates
    cout <<"Starting money: $";
    cin >> Amount; //Input x
    if(Amount==0){
        cout << "Day " << day <<" you spend $" << day << " so you have $"<<Amount; // Display the result with proper format
    }
    while (Amount >0){//Run until using up all the money
        Amount -= day; //Calcuate Answer
        if(day!=0){
            cout << "\n";
        }
        cout << "Day " << day <<" you spend $" << day << " so you have $"<<Amount; // Display the result with proper format
        day++; //Next day
    }
    // The end of question
}

void Q4() //Question 4
{
	//Declare the necessary variables
    int size, firstNumber, tmpNum, tmpSize;
    char symbol = '*';
	//Ask user to input the coordinates
    cout <<"Size: ";
    cin >> size; //Input size
    cout << "First number: ";
    cin >> firstNumber; //Input first number
    tmpSize = size;
    for(int j=0; j < size; j++){
        if(j!=0){
            cout << "\n";        
        }
        tmpNum=firstNumber;
        for (int k=0; k<(size-tmpSize); k++){
            cout << "  ";
        }
        for (int i=0; i<tmpSize; i++){
            cout << tmpNum << symbol;
            tmpNum -- ;
        }

        tmpSize--;
    }
    // The end of question 
}

// IMPORTANT: DO NOT MODIFY main()
int main()
{
	char prog_choice;

	do {
		cout << "\n\n";
		cout << "Program Selection Menu" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Enter question number ('q' to quit): ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '0': showInfo(); break;
		case '1': Q1(); break;
		case '2': Q2(); break;
		case '3': Q3(); break;
		case '4': Q4(); break;
		case 'q': break;
		default:
			cout << "No such question " << prog_choice << endl;
			break;
		}
	} while (prog_choice != 'q');

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
// END