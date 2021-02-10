#include <iostream>
#include <cmath>
using namespace std;

//Declare the necessary variables
int day, month, year;

void IncorrectDisplay(){
    // Display the result with proper format
    cout<<day<<"-"<<month<<"-"<<year<<" is incorrect";
    // Code indicates the end of program
}

void CorrectDisplay(){
    //Display the result with proper format
    cout<<day<<"-"<<month<<"-"<<year<<" is correct";
    //Code indicates the end of program
}

int main(){
    //Ask user to input a number
    cout << "Input day month year : " ;
    cin >> day;
    cin >> month;
    cin >> year;

    // Perform conditional operator
    cout << day << month << year;
    if (day>=32|| day<=0 || month>=13 || month <= 0 ){ 
        IncorrectDisplay();

    }
    else{
        if (year%4==0){     //This year is leap year
            if (day >=30){
                IncorrectDisplay();
            }
            else{

                if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){   //This month has 31 days
                    CorrectDisplay();
                }
                else {  //This month does not has 31 days

                    if (day == 31){
                        IncorrectDisplay();
                    }
                    else{
                        CorrectDisplay();
                    }
                }

            }
        }
        else{   //This year is not leap year
            if(day >=29){
                IncorrectDisplay();
            }
            else{

                if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){   //This month has 31 days
                    CorrectDisplay();
                }
                else {  //This month does not has 31 days

                    if (day == 31){
                        IncorrectDisplay();
                    }
                    else{
                        CorrectDisplay();
                    }
                }

            }
        }
    }
    return 0;
}