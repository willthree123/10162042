#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
using namespace std;

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
    Cus_info add_new;
    bool check = 0;
    cout << "This is the fuction of add assignment!"<< endl;
    cout << "Please type in your username" << endl;
    cout << "If this is not the fuction you want please type q instead : ";
    getline(cin , add_new.name);
    if (add_new.name == "q"){
		return;
    }
    do{
        cout << "Please enter your passport ID, it is ok if you input lower case characters : ";
        getline(cin , add_new.id);
        check = check_id(add_new.id);
    } while(!(check));
    check = 0;
    add_new.id = cap(add_new.id);

}

int main(){
	add();
using namespace std;    // std::cout, std::cin
int a; // fyt

}