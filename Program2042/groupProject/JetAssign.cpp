#include <iostream>

// This library is used for string
#include <string>

// This library is used for system like clear screen and pause
#include <unistd.h>

// This library is used for read write file
#include <fstream>

// This library is used for vector and vector is like an array which can be managed better than array
#include <vector>

// This library  is used for formatting
#include <iomanip>

using namespace std;

string breaking(string &);

int find(string);

// This is for animation delay which gives how many microsecond it will delay
unsigned int microsecond = 1000000; 

// This is each customer record which has 3 string name , id , location
class Cus_info {
    public:

    // string name is use to store customer's name
    string name;

    // string id is used to store the passport id of the customer
    string id;

    // string location is used to store the seat location of the customer
    string location;
};

// This is a vector which stores the vector of Name/PassportID/SeatLocation
vector<string> all_cus_info;

// This is a fuction which checks if the file store.txt open or not, if not it will automatically open a store.txt file
void open_file(){
	bool check; // his variable is use to store if the file is opened or not
	fstream file; // This is for file operation

    // check store.txt is open or not 
	file.open("store.txt");
		check = file.is_open();
	file.close();

    // if the file is not opened yet it will open a store.txt file so that when doing read write file it won't have error
	if(!check){
		file.open("store.txt");
		file.close();
	}
}

// This fuction is used for reading the data in store.txt to the vector all_cus_info
void read_file(){
	fstream file;  // This is for file operation
	string input;  // This is a temp variable which need are used for the push back the information of data

    // As if when it pushed back we don't know if the all_cus_info is empty or not so we make sure the vector is empty before reading the file
    // So that the vector will not have duplicate data
	all_cus_info.clear();

    // Operation of reading the file
	file.open("store.txt", fstream :: in);

        // This loop will get the whole line in the store.txt and store into the tempory input variable until its end of file
		while (getline(file,input)){

            // Push the input variable to the back of the vector
			all_cus_info.push_back(input);
		}
}

// This function is used for writing a string to the file the_line is the variable that we want to store in the txt file
void write_file(string the_line){
	fstream file;  // This is for file operation 

    // This is used for adding the text to the store .txt file
	file.open("store.txt", fstream :: app);

        // write the wanted line to the file
		file << the_line << endl;
	file.close();
}

// This function is used for checking the if the name have any inappropriate characters
bool check_name(string b){
    int s_length = 0; // this is a variable that store the length of string
	s_length = b.length(); // put the length of the string value into s_length

	char check[s_length]; // this is a character array
	for (int i = 0; i < s_length; i++)
	{
		check[i] = b[i]; // put each of the string character into the array

        // check if it contains any inappropriate character
		if (((check[i] < 'A') || (check[i] > 'Z')) && ((check[i] < 'a') || (check[i] > 'z')) && (!(check[i] == ' ')) ){ 

            // if yes cut the loop and return 0 which is false
			return 0;
		}
	}
	return 1; // if it successfully run through all it that means it is valid so return 1 which is true
}

// This fuction is used to change the wanted string with capital letters in wanted places
string cap_name(string change){
    int s_length = 0; // this is a variable that store the length of string
    string combine;   // store the changed string

    s_length = change.length();

	char to_cap[s_length]; // this is a character array

    // this is a for loop to put each cahracter of the string to array
	for (int i = 0; i < s_length; i++)
	{
		to_cap[i] = change[i];

        // to make change all capital letters to small letters so that capital letters will no appear in unsuitable places
        if ((to_cap[i] >= 'A') && (to_cap[i] <= 'Z')){
            to_cap[i] = char(int(to_cap[i]) + 32);
        }

        // find the place that need to change the caputal letters
        if ((i == 0) || (change[i-1] == ' ')){

            // check if it is small letters
            if ((to_cap[i] >= char(97)) && (to_cap[i] <= char(122))){

                // if yes change to capital letters
                to_cap[i] = char(int(to_cap[i]) - 32);
            }
        }
	}
    // finally combine all the character into the combine string
    for (int i = 0; i < s_length; i++)
	{
		combine = combine + to_cap[i];
	}

    // return the changed string back
    return combine;
}


// This fuction is used change all the small letters to capital letters
string cap(string change){
    int s_length = 0; // this is a variable that store the length of string
    string combine;   // The combined will be returned in the end of this function

    s_length = change.length();

	char to_cap[s_length]; // this is a character array

    // This is a loop that stores every character of string to the array and then find the small letters and change to capital letters
	for (int i = 0; i < s_length; i++)
	{
		to_cap[i] = change[i];

        // check if it is small english letters
		if ((to_cap[i] >= char(97)) && (to_cap[i] <= char(122))){

            // if yes then change to capital letters
			to_cap[i] = char(int(to_cap[i]) - 32);
		}
	}

    // this is a loop that put all the char in the array together to form a combined string
    for (int i = 0; i < s_length; i++)
	{
		combine = combine + to_cap[i];
	}

    // return the changed version of the string
    return combine;
}

// this function is used to check if the passport id is valid or not 
bool check_id(string change){
	int s_length = 0; // this is a variable that store the length of string
	s_length = change.length(); 

	char check[s_length]; // this is a character array

    // this is put each character in the string and check if it has inapproriate characters
	for (int i = 0; i < s_length; i++)
	{
		check[i] = change[i];

        // check if there are any inappropriate chaeracters like symbol or other that are not number and english letters
		if (((check[i] < '0') || (check[i] > '9')) && ((check[i] < 'A') || (check[i] > 'Z')) && ((check[i] < 'a') || (check[i] > 'z')) ){

            // if yes stopped the loop and return 0 which is false
			return 0;
		}
	}
    // after run the whole program and does not get stopped by return 0 that means the passport ID is valid so return true
	return 1;
	
}

// This is a function that used to check if the seat location is valid or not
bool check_location(string b){
    int s_length = 0; // this is a variable that store the length of string
	s_length = b.length();

    // if the location length is not 2 or 3 this is an invalid seat location number
	if((!((s_length == 2) || (s_length == 3)))){
        // return 0 which is false
		return 0;
	}

    // check if the last character of the string is English character or not and check if it is between a and f
	if (((b[s_length -1] < 'A') || (b[s_length -1] > 'F'))&&((b[s_length -1] < 'a') || (b[s_length -1] > 'f'))){
        // return 0 which is false
		return 0;
	}

    // if the length of the sting is two
	if(s_length == 2){
        
        // check the first is non zero integer cuz it is not valid to have 0C as seat location
        // check if it is between 1 and 9 
		if ((b[0]<'1') || (b[0]>'9')){

            // if no then return 0 which is false
			return 0;
		}
	}

    // otherwise as the string length is definitely 3 
	else{

        // then check if the first chracter is one and the second cahracter is between 0 and three as 13 is the maximum
		if ((!(b[0]=='1'))||(b[1] < '0')||(b[1]>'3')){

            // if no then return 0 which is false
			return 0;
		}
	}
	
    // if it successfully run through the program and not interperated by any return 0 then the seat location is true and it will return 1 which is true
	return 1;
}

// This function is used to check if there are any duplicate location
// As it is only used after each time at read file so that it already updated to the newest information and stored in the vector
// the string location is the seat location that will be checked if that particular location have been taken by someone
bool check_dup_location (string location){

    // character a will store character of the location that are working at the moment
    // character b will store the character that are working at that moment in
	char a , b;

    // it is a booleam array that checks location[i] = vector's one data's [i]
	bool check[location.length()];

    // this for loop will store the current all_cus_info string and put it into the temp variable
    // it will stop until it run through all the string in all_cus_info
	for (string temp : all_cus_info ){

        // run x times depending on the length of the variable location
		for(int i = 0; i < location.length() ; i++){

			a = location[i]; // store the current location character into a
			b = temp[temp.length() - location.length() + i]; // store the temp current working on cahracter into b
			
            // check if it is the same
            if (a == b){
                
                // if yes than the array number i array will return true 
				check[i] = 1;
			}

            // otherwise return false
			else {
                check[i] = 0;
            }
		}

        // create an integer count to count how many a==b is occured
		int count = 0;

        // count how many times does a==b is the same
		for (int j = 0 ; j < location.length() ; j++){
				if (check[j]){
					count ++ ;
				}
			}

        // if count == location then that means the location is duplicate so it will return flase
		if (count == location.length()){

            // if yes it will return 0, which is false
			return 0 ;
		}
	}
    // if it runned to here that means there are no indentical seat location had been taken
    // return 1 which is true
	return 1;
}

// this fuction is rewrite the whole file which will clear the whole file and write new things to it
void write_whole_file(){
	fstream file; // This is for file operation

    // fstream :: out will delte the words in the txt file and write the words in the file
	file.open("store.txt", fstream :: out);

        // The string temp will store the data of the all_cus_info feild that stored into the string temp
        // it will run the the size of the all_cus_info times
		for (string temp : all_cus_info){

            // put the temp string into the file and open a new line
			file << temp << endl;
		}
	file.close();
}


// find the primary key which is Name/PassportID and return the ith data in the vector
int find(string pk){
	int i = 0; // this is the use to store the the number of the vector
	string::size_type position;

    // The string temp will store the data of the all_cus_info feild that stored into the string temp
    // it will run the the size of the all_cus_info times
	for (string temp : all_cus_info){
		i++;
		position = temp.find(pk); // find the position of the string where pk at

        // if not found it will ruturn certain number which means not found
        // if found
		if (!(position == temp.npos)){

            // return i which is the number which ith term of the vector is the target
			return i;
		}
	}
    // if not found then return -1 why -1 is because there are no -1th feild in the vector
	return -1;
}

string breaking(string &a)
{
    int pos = 0;
    pos = a.find("/"); // find / location
    if (pos != string::npos)
    {
        string temp = a.substr(0, pos); // extract the useful string
        a.erase(0, pos + 1); //update the string with the useful after used
        return temp;
    }
    else 
        return "";
}


// This fuction is use to add a new record to the file
void add(){
    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // add_new is a variable of the class type Cus_info which store the customer's name, passport id and seat location which about to write into the file
    Cus_info add_new;

    // store the boolean to check the input validation
    bool check = 0;

    // store the combined record like Name/PassportID/SeatLocation
    string all;

    // open a store.txt file if haven't create one
    open_file();

    // update the value of the all_cus_info vector
    read_file();

    // introduction of what fuction is the user using 
    cout << "This is the fuction of add assignment!"<< endl;

    // it will repeat it until the customer write an valid name or press q to quit
    do{
        cout << "Please type in your username" << endl;
        cout << "If this is not the fuction you want please type q instead : ";


        cin.ignore();
        getline(cin ,add_new.name );      // user input the customer's name

        // if the user input q then it will automatically skipped the whole program
        if (add_new.name == "q"){
            return;
        }

        // check if the input is valid or not and store it in the check value
        check = check_name(add_new.name);

        // if check is false then will appear an instruction for users to input again
        if(!(check)){
            cout << "You typed in inappropriate letters, please type in again" << endl;
        }
    }while(!(check));

    // reset the check to false
    check = 0;

    // change certain letters to capital letters
    add_new.name = cap_name(add_new.name);

    // it will loop until the user input a valid passport id
    do{
        // user input the passport id
        cout << "Please enter your passport ID, it is ok if you input lower case characters : ";
        getline(cin , add_new.id);

        // check if the input is valid or not and store to the bool check
        check = check_id(add_new.id);

        // if not check show an instruction to them to type the passport id again
        if(!(check)){
            cout << "You typed in inappropriate letters, please type in again" << endl;
        }

    } while(!(check)); // until the check is true

    // reset the check value
    check = 0;

    // all english small letters change to capital letters
    add_new.id = cap(add_new.id);

    // this will loop until the user enter valid seat location
    do
    {
        // user input seat location
        cout << "Please enter your seat location, it is ok if you input lower case characters : ";
        getline(cin , add_new.location);

        // change all english small letters to capital letters
        add_new.location = cap(add_new.location);

        // check if the user input is valid and store it in check
        check = check_location(add_new.location);

        // if check is false give an instruction for user to type the seat location again
        if(!(check)){
            cout << "You does not type a valid seat location, please type again" << endl;

            // if this is already false then can skip the behind check because it is already false no need to validate below
            goto skipcheck;
        }

        // check if the seat loaction has been taken or not and store it in check
        check = check_dup_location(add_new.location);

        // if check is false then give instruction that the seat position has been taken and need to enter again
        if(!(check)){
            cout << "The seat location has been taken, please type another seat location" << endl;
        }

    // the place that skipcheck will go to
    skipcheck:
    cout << "";

    } while (!(check)); // until the check is true

    // as all of the feild is correct so need to combine it to one
    all = add_new.name + "/" + add_new.id + "/" + add_new.location;

    // write the record into the file
    write_file(all);

    // give indication that user input is already saved
    cout << "input successful!"<< endl;

    // user need to press any button to quit this function so user can watch the input successful line and not quit to the menu
    system("pause");
}

// This function is to let user to input name and passport id to find the record and delete the record
void del(){

    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // this is a variable of class type Cus_info so that they can find the wanted record and delete it
    Cus_info find_del;

    // check is check user input is correct or not
    bool check = 0;

    // all is combined the find_del together
    string all;

    // this is a string that use for people to make sure they want to delete that particular record
    string sure;

    // this is a loop if cannot find user input 
    do{

        del_start:cout << ""; 

        // this will loop until the user enter a valid name format
        do{
            // user input name
            cout << "Please type in your username" << endl;
            cout << "If this is not the fuction you want please type q instead : ";
            cin.ignore();
            getline(cin ,find_del.name );

            // user press q that means they want to quit so it will end this function
            if (find_del.name == "q"){
                return;
            }

            // check if the name is valid or not
            check = check_name(find_del.name);

            // if it is not valid, give instruction to tell them they need to enter it again
            if(!(check)){
                cout << "You typed in inappropriate letters, please type in again" << endl;
            }

        }while(!(check)); // until check is true

        // reset the check value
        check = 0;

        // cahnge suitable amall english letters to capital english letters
        find_del.name = cap_name(find_del.name);

        // this will loop until the user input passport id is valid or not
        do{

            // user input the passport id
            cout << "Please enter your passport ID, it is ok if you input lower case characters : ";
            getline(cin , find_del.id);

            // check if the passport id is valid or not
            check = check_id(find_del.id);

            // it is not valid then give instruction to them that they need to type the passport id again
            if(!(check)){
                cout << "You typed in inappropriate letters, please type in again" << endl;
            }

        } while(!(check)); // loop until check is true

        // change the small english letters in the user input to capital letters
        find_del.id = cap(find_del.id);

        // combine the name and id together
        all = find_del.name + "/" + find_del.id;

        // make sure the txt file is open so it won't be error
        open_file();

        // read the txt file to update the all_cus_info vector
        read_file();

        // check if it can be found in the vectorand give the result for user to know
        if(find(all)==-1){
            cout << "Not found! Please check your input and type again" << endl;
        }else {
            cout << "Found!" << endl;  // or else it would be found
        }

    // if the particular record can't find, give instruction to user to repeat the process again
    // as they can press q to quit the fuction when inputting the name so here can be looped
    } while(find(all)==-1);

    // here to let people to make sure  they want to delete the record that found 
	if (!(find(all)==-1)){
        
        // this will be looped until they input 1 or input 2
        do{
            // as the record will be deleted forever so this just to make sure that they want to delete the record
            cout << "Are you sure that you want to delete this record?"<< endl;
            cout << "Type 1 for yes. Type 2 for no" << endl;
            cin >> sure;

            // make sure the user input only one character
            if (!(sure.length() == 1)){
                cout << "Invalid input"<<endl;

            }else{
                // make sure that they type 1 or 2 instead of other character
                if((!(sure[0] == '1'))&&(!(sure[0] == '2'))){
                    cout << "Invalid input"<<endl;
                }
            }

        } while((!(sure.length() == 1))||((!(sure[0] == '1'))&&(!(sure[0] == '2')))); // until the input is valid

        // after passing the part that valid user input
        // this situation is when user type 1
        if(sure[0] == '1'){

            // delete the particular vector record which is the record that user want to delete
            all_cus_info.erase(all_cus_info.begin()+find(all)-1);

            // rewrite the file using the updated vector
            write_whole_file();

            // give instruction that the particular item is deleted for user to know
            cout << all << " is successfully deleted"<<endl;

        } else {
            goto del_start; // otherwise go to the start of the program and type anothe record
        }
	}
    
    // when the fuction is ended they can see the input and out put until they press a button so they know what is successfully deleted
    system ("pause");
}

// this fuction is for people to enter multiple record at the same time
void batch_addition()
{
    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // this is used to store the unsuccessfully save record
    vector <string> unsuccessful;

    // this is used to store the successful record
    vector <string> successful;

    // this is used for storing user input
    string input;

    // make sure store.txt file is opened so it won't have any error occur
    open_file();

    //update the all_cus_info using the data stored in store.txt
    read_file();

    // give user instruction of format that they need to type in
    cout << "Please enter the users' details as following Format:\nName/PassportID/Seat\n";
    cin.ignore();

    // while the user does not input string 0 it will loop
    do{
        // now_succuess is a boolean that is for input validation
        bool now_success = 1;
        
        // user input
        getline(cin, input);

        // break a to name , passport id and location
        string a = input;
        string name = breaking(a);
        string id = breaking(a);
        string location = a;

        // if the breaking does not work then the now_success is false
        if( name == "error" || id == "error" || location == "error")
            {
                now_success = 0;
            }
        
        // passed the first layer of validation now check the name, passport id and seat location is valid or not
        // if one of them are false then now_success is flase
        else{
            if ((!check_name(name)) || (!check_id(id))|| (!check_location(location))){
                    now_success = 0;
            }
            // then it passed the second layer of validation
            else{
                    // cahnge suitable amall english letters to capital english letters
                    name = cap_name(name);

                    // change all small english letters to the capital letters
                    id = cap(id);

                    // change all small english letters to the capital letters
                    location = cap(location);

                    // check if the seat location has been taken yet
                    if (check_dup_location(location)){

                    // if it has not been taken then combine name, passport id and seat location to a
                    a = name + "/" + id + "/" + location;
                    }

                    // otherwise it is not valid
                    else{
                        now_success = 0;
                    }
            }
        }
        // check if now_success is true or not
        // if true, push to successful vector
        if (now_success){

            // push the combined valid string to successful vector
            successful.push_back(a);
        }

        // otherwise push to unsuccessful vector
        else{

            // push the output to the back of the unsuccessful vector
            unsuccessful.push_back(input);
        }

    }while(!((input.length() == 1) && (input[0] == '0'))); // this will loop until user only type 0 as the input

    // store the current working term of vector successful to temp and this loop will loop the size of vector times
    for (string temp : successful){
    
       // write all the string in the successful list to the store.txt file
       write_file(temp); 
    }

    // give instruction to users that this is displayed for successful list
    cout << "Successful list:" << endl;

    // store the current working term of vector successful to temp and this loop will loop the size of vector times
    for (string temp : successful){

        // output the successful vector data
        cout << temp << endl;
    }

    // open some new rows to make sure the two list can be seperated and displayed clearly
    cout << endl << endl << endl; 

    // give instruction to users that this is displayed for the unsuccessful list
    cout << "Unuccessful list:" << endl;

    // store the current working term of vector unsuccessful to temp and this loop will loop the size of vector times
    for (string temp : unsuccessful){
        
        // As the 0 input will also push to this unsuccessful list 
        if (!((temp.length() == 1) && (temp[0] == '0'))){

            // output the unsuccessful vector data
            cout << temp << endl;
        }
    }

    // when the fuction is ended they can see the input and out put until they press a button so they know what is successfully deleted
    system("pause");
}


void display_info(int a)
{
    if (a == 1)
    {
        for (int row = 1; row < 3; row++) // show row
        {
            for (int col = 65; col < 70; col++) //show col, col is in ascii code for looping
            {
                string temp = to_string(row);
                char temp1 = (char)col;
                string location = temp + temp1; //merge the row and col into 1 string
                int i = find(location);//search by id
                if (i == 1000)
                    cout << right << row << (char)col << ": " << left << setw(25) << "vacant ";
                else
                    cout << right << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i-1]);
            }
            cout << "\n";
        }
    }
    else if (a == 2)
    {
        for (int row = 3; row < 8; row++)
        {
            for (int col = 65; col < 70; col++)
            {
                string temp = to_string(row);
                char temp1 = (char)col;
                string location = temp + temp1;
                int i = find(location);//search by id
                if (i == -1)
                    cout << right << row << (char)col << ": " << left << setw(25) << "vacant ";
                else
                    cout << right << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i]);
            }
            cout << "\n";
        }
    }
    else
    {
        for (int row = 8; row < 14; row++)
        {
            for (int col = 65; col < 70; col++)
            {
                string temp = to_string(row);
                char temp1 = (char)col;
                string location = temp + temp1;
                int i = find(location);//search by id
                if (i == -1)
                    cout << right <<setw(2) << row << (char)col << ": " << left << setw(25) << "vacant ";
                else
                    cout << right <<setw(2) << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i]);
            }
            cout << "\n";
        }
    }
}


int class_indentifier(string a) // return class type for searching
{
    if (a == "first" || a == "first")
        return 1;
    else if (a == "business" || a == "Business")
        return 2;
    else if (a == "economy" || a == "Economy")
        return 3;
    else
        return -1;
}

void find_passenger()
{
    string temp;
    cout << "Please enter the passport id: ";
    cin >> temp;
    temp = cap(temp);
    int i= find(temp);
    if(i == -1)
        cout << "no required passenger id found";
    else
        {
            string temp_info = all_cus_info[i-1];
            cout << "Name: " << breaking(temp_info) << "\n";
            cout << "Passport id: " << breaking(temp_info) << "\n";
            cout << "Location: " << temp_info <<"\n";
        }
}

void find_class()
{
    top:
    cout << "Please enter the class: ";
    string class_search;
    cin >> class_search;

    int temp = class_indentifier(class_search);  //identify class line 54
    if (temp == -1)
        {
            cout << "Wrong input, please try again.\n";
            goto top;
        }
    else
        display_info(temp); //search the name by class 20
}

void show_details()
{
    system("CLS");
    open_file();
    read_file();
    cout << "*** Details ***\n";
    cout << "[1] Passenger\n";
    cout << "[2] Class\n";
    cout << "[3] Back\n";
    cout << "*****************\n";
    top:
    cout << "Option (1-3): ";
    string user_input;
    cin >> user_input;
    if (user_input == "1")
        find_passenger();
    else if (user_input == "2")
        find_class();
    else if (user_input == "3")
        return;
    else
        {
            cout << "Wrong input, please try again.";
            goto top;
        }
    system("pause");
}
void latest_seating_plan ()
{
    system("CLS");
    open_file();
    read_file();
    for (int row = 1; row < 14; row++) // show row
    {
        for (int col = 65; col < 71; col++) //show col, col is in ascii code for looping
        {
            string temp = to_string(row);
            char temp1 = (char)col;
            string location = temp + temp1; //merge the row and col into 1 string
            int temp3 = find(location);//search by id
            if (temp3 == 1000)
                cout << setw(2) << row << (char)col <<" availible ";
            else
                cout << setw(2)<< row << (char)col << " occupied  "; //show with the related passenger
        }
        cout << "\n";
    }
    system("pause");
}

// This fuction is the intro of the program which print welcome and the logo of hkcc airline
void show_intro(){

    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // change the color of the word so it can catch customers eyeball
    system("Color 03");

    // print the welcome 
    cout << "*************************"<<endl;

    // used delay to create some kind of aniamtion to catch users' eyeball
    usleep(microsecond/5);
    cout << "*Welcome to HKCC Airline*"<<endl;
    usleep(microsecond/5);
    cout << "*************************"<<endl;
    usleep(microsecond);

    // print the logo
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

    // change back the font color so that the whole program will display in normal color
    system("Color 07");


}

// this function is used to simulate the loading in the system so it seems to be a legit system
void loading_animation(){

        // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
        system("CLS");

        cout <<"Loading";

        // use the delay to simulate the loading bar
        usleep(microsecond/5);
        cout << "." ;
        usleep(microsecond/5);
        cout << "." ;
        usleep(microsecond/5);
        cout << "." << endl;
        usleep(microsecond/2);
}


// this is the function of the main menu which display the menu and people can go to their wanted function of this program
void menu(){

    // This is a string variable that stores users input
    string user_input = "-1"; 

    // this is a variable that used to store the converted user input to character
    char user_input_char ='p';

    // the loop won't stop until user type 6 which is the exit fuction
    do{

         // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
        system("CLS");

        // Displays the main menu and gives instructions which input will go to which fuction
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

        // user input
        cin >> user_input;

        // check if user only input one character
        if (!(user_input.length()== 1)){

            // if users input more than one character than it will show invalid input and start to display main menu
            cout << "Invalid input, please input again"<< endl;

            // to let user see the invalid input , here put in delay
            usleep(microsecond);
        }

        // otherwise
        else{

            // store the first character of the string to user_input_char
            user_input_char = user_input[0];

            // do a switch so it will do different things in different situation
            switch (user_input_char) {

                // Add an assignment
                case '1': add(); usleep(microsecond); break; 

                // Delete an assignment
                case '2': del(); usleep(microsecond); break;

                // Add assignments in batch
                case '3': batch_addition(); usleep(microsecond); break;

                // Show latest seating plan
                case '4': latest_seating_plan(); usleep(microsecond); break;

                // Show details
                case '5': show_details();  usleep(microsecond);break;

                // thank people using this system
                case '6': cout << "Thank you for using this system";               
                                  usleep(2*microsecond);
                                  system("CLS");
                                  break;

                // other than 1-6 others are all invalid input and user need to type again
                default : cout << "Invalid input, please input again"<< endl;
                          usleep(microsecond); break;
            }
        }
    }while ((!(user_input.length()== 1))||(!(user_input_char=='6'))); // until the user type in 6 to end the program
}


int main(){ 

    // show the introduction to people
    show_intro();

    // simulate loading screen
    loading_animation();

    // go to the main menu
    menu();

    // give a sign for the computer that this is the end of the program
    return 0;
}