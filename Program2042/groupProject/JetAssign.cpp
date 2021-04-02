#include <iostream>
#include <string>
#include <unistd.h>
//#include <fstream>
using namespace std;
unsigned int microsecond = 1000000; 

class Cus_info {
    public:
    string name;
    string id;
    string location;
};

string cap(string change){
    int s_length = 0;
    string combine;
    s_length = change.length();
	char to_cap[s_length];
	for (int i = 0; i < s_length; i++)
	{
		to_cap[i] = change[i];
		if ((to_cap[i] >= char(97)) && (to_cap[i] <= char(122))){
			to_cap[i] = char(int(to_cap[i]) - 32);
		}
		cout << to_cap[i];
	}
    for (int i = 0; i < s_length; i++)
	{
		combine = combine + to_cap[i];
	}
    return combine;
}

bool check_id(string change){
	int s_length = 0;
	s_length = change.length();
	char check[s_length];
	for (int i = 0; i < s_length; i++)
	{
		check[i] = change[i];
		if (((check[i] < '0') || (check[i] > '9')) && ((check[i] < 'A') || (check[i] > 'Z')) && ((check[i] < 'a') || (check[i] > 'z')) ){
			return 0;
		}
	}
	return 1;
	
}

void add(){
    system("CLS");
    Cus_info add_new;
    bool check = 0;
    cout << "This is the fuction of add assignment!"<< endl;
    cout << "Please type in your username" << endl;
    cout << "If this is not the fuction you want please type q instead : ";
    cin.ignore();
    getline(cin ,add_new.name );
    if (add_new.name == "q"){
		return;
    }
    do{
        cout << "Please enter your passport ID, it is ok if you input lower case characters : ";
        getline(cin , add_new.id);
        cout << "You typed in inappropriate letters, please type in again";
        check = check_id(add_new.id);
    } while(!(check));
    check = 0;
    add_new.id = cap(add_new.id);

}


void show_intro(){
    system("CLS");
    system("Color 03");
    cout << "*************************"<<endl;
    usleep(microsecond/5);
    cout << "*Welcome to HKCC Airline*"<<endl;
    usleep(microsecond/5);
    cout << "*************************"<<endl;
    usleep(microsecond);
    cout << R"(
,ggg,        gg ,ggg,        gg      ,gggg,       ,gggg,  
dP""Y8b       88dP""Y8b       dP    ,88"""Y8b,   ,88"""Y8b,
Yb, `88       88Yb, `88      d8'   d8"     `Y8  d8"     `Y8
`"  88       88 `"  88    ,dP'   d8'   8b  d8 d8'   8b  d8
     88aaaaaaa88     88aaad8"    ,8I    "Y88P',8I    "Y88P'
    88"""""""88     88""""Yb,   I8'          I8'          
    88       88     88     "8b  d8           d8           
     88       88     88      `8i Y8,          Y8,          
    88       Y8,    88       Yb,`Yba,,_____, `Yba,,_____, 
     88       `Y8    88        Y8  `"Y8888888   `"Y8888888        
        )" << '\n';
        usleep(1*microsecond);
    system("Color 07");


}

void loading_animation(){
        system("CLS");
        cout <<"Loading";
        usleep(microsecond/5);
        cout << "." ;
        usleep(microsecond/5);
        cout << "." ;
        usleep(microsecond/5);
        cout << "." << endl;
        usleep(microsecond/2);
}

void menu(){
    string user_input = "-1"; 
    char user_input_char ='p';
    do{
        system("CLS");
        cout << "Welcome to the HKCC Airline's Airplane seating assignment system" << endl;
        cout << "*** main menu ***" << endl;
        cout << "[1] Add an assignment" << endl;
        cout << "[2] Delete an assignment" << endl;
        cout << "[3] Add assignments in batch" << endl;
        cout << "[4] Show latest seating plan" << endl;
        cout << "[5] Show details" << endl;
        cout << "[6] Exit" << endl;
        cout << "*****************"<< endl;
        cout << "Option (1-6): ";
        cin >> user_input;
        if (!(user_input.length()== 1)){
            cout << "Invalid input, please input again"<< endl;
            usleep(microsecond);
        }
        else{
            user_input_char = user_input[0];
            switch (user_input_char) {
                case '1': add(); usleep(microsecond); break;
                case '2': cout << "don't"; usleep(microsecond); break;
                case '3': cout << "show"; usleep(microsecond); break;
                case '4': cout << "this"; usleep(microsecond); break;
                case '5': cout << "shit";  usleep(microsecond);break;
                case '6': cout << "Thank you for using this system";               
                                  usleep(2*microsecond);
                                  system("CLS");
                                  break;
                default : cout << "Invalid input, please input again"<< endl;
                          usleep(microsecond); break;
            }
        }
    }while ((!(user_input.length()== 1))||(!(user_input_char=='6')));
}

int main(){ 
    show_intro();
    loading_animation();
    menu();
    return 0;
}