/*  SEHH2042 Group Project
	 Stundent Name  		  Student Number
	 KOK Siu Chung***   		20190875A
	 HO Chun Hei     			20096776A
	 HONG Chiu Wing Timothy		20168912A
	 MOK Ho Ming				20072190A
	 TO Fui Yin                 20199034A 
*/

#include <iostream>

// This library is used for string
#include <string>

// This library is used for system like clear screen and pause
#include <windows.h>

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
unsigned int microsecond = 800;

// This is each customer record which has 3 string name , id , location
class Cus_info
{
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

// this is used to store the unsuccessfully save record
vector<string> unsuccessful;

// this is used to store the successful record
vector<string> successful;

// This is a function for setting up the color
HANDLE hOut;
void setup_color()
{
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
}

// This is a function which checks if the file store.txt open or not, if not it will automatically open a store.txt file
void open_file()
{
    bool check;   // his variable is use to store if the file is opened or not
    fstream file; // This is for file operation

    // check store.txt is open or not
    file.open("store.txt");
    check = file.is_open();
    file.close();

    // if the file is not opened yet it will open a store.txt file so that when doing read write file it won't have error
    if (!check)
    {
        file.open("store.txt");
        file.close();
    }
}

// This function is used for reading the data in store.txt to the vector all_cus_info
void read_file()
{
    fstream file; // This is for file operation
    string input; // This is a temp variable which need are used for the push back the information of data

    // As if when it pushed back we don't know if the all_cus_info is empty or not so we make sure the vector is empty before reading the file
    // So that the vector will not have duplicate data
    all_cus_info.clear();

    // Operation of reading the file
    file.open("store.txt", fstream::in);

    // This loop will get the whole line in the store.txt and store into the tempory input variable until its end of file
    while (getline(file, input))
    {

        // Push the input variable to the back of the vector
        all_cus_info.push_back(input);
    }
}

// This function is used for writing a string to the file the_line is the variable that we want to store in the txt file
void write_file(string the_line)
{
    fstream file; // This is for file operation

    // This is used for adding the text to the store .txt file
    file.open("store.txt", fstream::app);

    // write the wanted line to the file
    file << the_line << endl;
    file.close();
}

// This function is used for checking the if the name have any inappropriate characters
bool check_name(string b)
{
    int s_length = 0;      // this is a variable that store the length of string
    s_length = b.length(); // put the length of the string value into s_length
    char *check;

    check = new char[s_length]; // this is a character array
    for (int i = 0; i < s_length; i++)
    {
        check[i] = b[i]; // put each of the string character into the array

        // check if it contains any inappropriate character
        if (((check[i] < 'A') || (check[i] > 'Z')) && ((check[i] < 'a') || (check[i] > 'z')) && (!(check[i] == ' ')))
        {
            delete[] check;
            // if yes cut the loop and return 0 which is false
            return 0;
        }
    }
    delete[] check;
    return 1; // if it successfully run through all it that means it is valid so return 1 which is true
}

// This function is used to change the wanted string with capital letters in wanted places
string cap_name(string change)
{
    int s_length = 0; // this is a variable that store the length of string
    string combine;   // store the changed string

    s_length = change.length();
    char *to_cap;

    to_cap = new char[s_length]; // this is a character array

    // this is a for loop to put each cahracter of the string to array
    for (int i = 0; i < s_length; i++)
    {
        to_cap[i] = change[i];

        // to make change all capital letters to small letters so that capital letters will no appear in unsuitable places
        if ((to_cap[i] >= 'A') && (to_cap[i] <= 'Z'))
        {
            to_cap[i] = char(int(to_cap[i]) + 32);
        }

        // find the place that need to change the caputal letters
        if ((i == 0) || (change[i - 1] == ' '))
        {

            // check if it is small letters
            if ((to_cap[i] >= char(97)) && (to_cap[i] <= char(122)))
            {

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
    delete[] to_cap;
    // return the changed string back
    return combine;
}

// This function is used change all the small letters to capital letters
string cap(string change)
{
    int s_length = 0; // this is a variable that store the length of string
    string combine;   // The combined will be returned in the end of this function

    s_length = change.length();
    char *to_cap;

    to_cap = new char[s_length]; // this is a character array

    // This is a loop that stores every character of string to the array and then find the small letters and change to capital letters
    for (int i = 0; i < s_length; i++)
    {
        to_cap[i] = change[i];

        // check if it is small english letters
        if ((to_cap[i] >= char(97)) && (to_cap[i] <= char(122)))
        {

            // if yes then change to capital letters
            to_cap[i] = char(int(to_cap[i]) - 32);
        }
    }

    // this is a loop that put all the char in the array together to form a combined string
    for (int i = 0; i < s_length; i++)
    {
        combine = combine + to_cap[i];
    }
    delete[] to_cap;
    // return the changed version of the string
    return combine;
}

// this function is used to check if the passport id is valid or not
bool check_id(string change)
{
    int s_length = 0; // this is a variable that store the length of string
    s_length = change.length();
    char *check;
    check = new char[s_length]; // this is a character array

    // this is put each character in the string and check if it has inapproriate characters
    for (int i = 0; i < s_length; i++)
    {
        check[i] = change[i];

        // check if there are any inappropriate chaeracters like symbol or other that are not number and english letters
        if (((check[i] < '0') || (check[i] > '9')) && ((check[i] < 'A') || (check[i] > 'Z')) && ((check[i] < 'a') || (check[i] > 'z')))
        {
            delete[] check;
            // if yes stopped the loop and return 0 which is false
            return 0;
        }
    }
    delete[] check;
    // after run the whole program and does not get stopped by return 0 that means the passport ID is valid so return true
    return 1;
}

// This is a function that used to check if the seat location is valid or not
bool check_location(string b)
{
    int s_length = 0; // this is a variable that store the length of string
    s_length = b.length();

    // if the location length is not 2 or 3 this is an invalid seat location number
    if ((!((s_length == 2) || (s_length == 3))))
    {
        // return 0 which is false
        return 0;
    }

    // check if the last character of the string is English character or not and check if it is between a and f
    if (((b[s_length - 1] < 'A') || (b[s_length - 1] > 'F')) && ((b[s_length - 1] < 'a') || (b[s_length - 1] > 'f')))
    {
        // return 0 which is false
        return 0;
    }

    // if the length of the sting is two
    if (s_length == 2)
    {

        // check the first is non zero integer cuz it is not valid to have 0C as seat location
        // check if it is between 1 and 9
        if ((b[0] < '1') || (b[0] > '9'))
        {

            // if no then return 0 which is false
            return 0;
        }
    }

    // otherwise as the string length is definitely 3
    else
    {

        // then check if the first chracter is one and the second cahracter is between 0 and three as 13 is the maximum
        if ((!(b[0] == '1')) || (b[1] < '0') || (b[1] > '3'))
        {

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
bool check_dup_location(string location)
{

    // character a will store character of the location that are working at the moment
    // character b will store the character that are working at that moment in
    char a, b;
    int s_length = location.length();
    // it is a booleam array that checks location[i] = vector's one data's [i]
    bool *check = 0;
    check = new bool[s_length];

    // this for loop will store the current all_cus_info string and put it into the temp variable
    // it will stop until it run through all the string in all_cus_info
    for (string temp : all_cus_info)
    {

        // run x times depending on the length of the variable location
        for (size_t i = 0; i < unsigned(s_length); i++)
        {

            a = location[i];                        // store the current location character into a
            b = temp[temp.length() - s_length + i]; // store the temp current working on cahracter into b

            // check if it is the same
            if (a == b)
            {

                // if yes than the array number i array will return true
                check[i] = 1;
            }

            // otherwise return false
            else
            {
                check[i] = 0;
            }
        }

        // create an integer count to count how many a==b is occured
        int count = 0;

        // count how many times does a==b is the same
        for (size_t j = 0; j < unsigned(s_length); j++)
        {
            if (check[j] == 1)
            {
                count++;
            }
        }

        // if count == location then that means the location is duplicate so it will return flase
        if ((count == s_length) && ((temp[temp.length() - s_length - 1] == '/')))
        {
            delete[] check;
            // if yes it will return 0, which is false
            return 0;
        }
    }
    delete[] check;
    // if it runned to here that means there are no indentical seat location had been taken
    // return 1 which is true
    return 1;
}

bool check_dup_location_success(string location)
{

    // character a will store character of the location that are working at the moment
    // character b will store the character that are working at that moment in
    char a, b;
    int s_length = location.length();
    // it is a booleam array that checks location[i] = vector's one data's [i]
    bool *check = 0;
    check = new bool[s_length];

    // this for loop will store the current successful string and put it into the temp variable
    // it will stop until it run through all the string in successful
    for (string temp : successful)
    {

        // run x times depending on the length of the variable location
        for (size_t i = 0; i < unsigned(s_length); i++)
        {

            a = location[i];                        // store the current location character into a
            b = temp[temp.length() - s_length + i]; // store the temp current working on cahracter into b

            // check if it is the same
            if (a == b)
            {

                // if yes than the array number i array will return true
                check[i] = 1;
            }

            // otherwise return false
            else
            {
                check[i] = 0;
            }
        }

        // create an integer count to count how many a==b is occured
        int count = 0;

        // count how many times does a==b is the same
        for (size_t j = 0; j < unsigned(s_length); j++)
        {
            if (check[j] == 1)
            {
                count++;
            }
        }

        // if count == location then that means the location is duplicate so it will return flase
        if ((count == s_length) && ((temp[temp.length() - s_length - 1] == '/')))
        {
            delete[] check;
            // if yes it will return 0, which is false
            return 0;
        }
    }
    delete[] check;
    // if it runned to here that means there are no indentical seat location had been taken
    // return 1 which is true
    return 1;
}

//it is use for checking if there are the same input that stored in the all_cus_info vector
bool check_dup_id(string idinput)
{

    // use for loop to put each one of the all_cus_id vector
    for (string temp : all_cus_info)
    {

        // break the temp to the three personal information
        string name = breaking(temp);
        string id = breaking(temp);
        string location = temp;

        // if there are same input than return false
        if (id == idinput)
        {
            return 0;
        }
    }

    // otherwise return true
    return 1;
}

// used in batch addition and it is use for checking if there are the same input that stored in the successful vector
bool check_dup_id_success(string idinput)
{

    // use for loop to put each one of the successful vector
    for (string temp : successful)
    {

        // break the temp to the three personal information
        string name = breaking(temp);
        string id = breaking(temp);
        string location = temp;

        // if there are same input than return false
        if (id == idinput)
        {
            return 0;
        }
    }
    // otherwise return true
    return 1;
}

// this function is rewrite the whole file which will clear the whole file and write new things to it
void write_whole_file()
{
    fstream file; // This is for file operation

    // fstream :: out will delte the words in the txt file and write the words in the file
    file.open("store.txt", fstream::out);

    // The string temp will store the data of the all_cus_info feild that stored into the string temp
    // it will run the the size of the all_cus_info times
    for (string temp : all_cus_info)
    {

        // put the temp string into the file and open a new line
        file << temp << endl;
    }
    file.close();
}

// find the primary key which is Name/PassportID and return the ith data in the vector
int find(string pk)
{
    int i = 0; // this is the use to store the the number of the vector
    string::size_type position;

    // The string temp will store the data of the all_cus_info feild that stored into the string temp
    // it will run the the size of the all_cus_info times
    for (string temp : all_cus_info)
    {
        i++;
        position = temp.find(pk); // find the position of the string where pk at

        // if not found it will ruturn certain number which means not found
        // if found
        if (!(position == temp.npos))
        {

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
        a.erase(0, pos + 1);            //update the string with the useful after used
        return temp;
    }
    else
        return "";
}

// This function is use to add a new record to the file
void add()
{
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

    // introduction of what function is the user using
    cout << "This is the function for ";
    SetConsoleTextAttribute(hOut, 11);
    cout << "Adding Assignment";
    SetConsoleTextAttribute(hOut, 15);
    cout << "!" << endl
         << endl;

    // it will repeat it until the customer write an valid name or press q to quit
    do
    {
        SetConsoleTextAttribute(hOut, 7);
        cout << "'q' to go back Main Menu" << endl;
        cout << "*****************" << endl
             << endl;
        SetConsoleTextAttribute(hOut, 15);
        cout << "Please type in your ";
        SetConsoleTextAttribute(hOut, 3);
        cout << "Name" << endl;
        SetConsoleTextAttribute(hOut, 7);
        SetConsoleTextAttribute(hOut, 15);
        cout << "Name: ";
        SetConsoleTextAttribute(hOut, 11);
        getline(cin, add_new.name); // user input the customer's name
        SetConsoleTextAttribute(hOut, 15);

        // if the user input q then it will automatically skipped the whole program
        if (add_new.name == "q")
        {
            return;
        }

        // check if the input is valid or not and store it in the check value
        check = check_name(add_new.name);

        // if check is false then will appear an instruction for users to input again
        if (!(check))
        {
            cout << "You typed in inappropriate letters(only contains english letters and space), please type in again" << endl;
        }
        if (add_new.name == "")
        {
            check = FALSE;
            cout << "Input could not be empty" << endl;
        }
    } while (!(check));

    // reset the check to false
    check = 0;

    // change certain letters to capital letters
    add_new.name = cap_name(add_new.name);

    // it will loop until the user input a valid passport id
    do
    {
        // user input the passport id
        cout << endl
             << "Please enter your ";
        SetConsoleTextAttribute(hOut, 3);
        cout << "Passport ID" << endl;
        SetConsoleTextAttribute(hOut, 7);
        cout << "(Lower case characters are accepted)" << endl;
        cout << "*****************" << endl;
        SetConsoleTextAttribute(hOut, 15);
        cout << "Passport ID: ";
        SetConsoleTextAttribute(hOut, 11);
        getline(cin, add_new.id);
        SetConsoleTextAttribute(hOut, 15);

        // check if the input is valid or not and store to the bool check
        check = check_id(add_new.id);

        // all english small letters change to capital letters
        add_new.id = cap(add_new.id);
        // if not check show an instruction to them to type the passport id again
        if (!(check))
        {
            cout << "You typed in inappropriate letters(only contains english letters and numbers), please type in again" << endl;
        }
        else
        {
            check = check_dup_id(add_new.id);
            if (!(check))
            {
                cout << "This is duplicate passport ID, please make sure you type the right passport id" << endl;
            }
        }
        if (add_new.id == "")
        {
            check = FALSE;
            cout << "Input could not be empty" << endl;
        }
    } while (!(check)); // until the check is true

    // reset the check value
    check = 0;

    // this will loop until the user enter valid seat location
    do
    {
        // user input seat location
        cout << endl
             << "Please enter your ";
        SetConsoleTextAttribute(hOut, 3);
        cout << "Seat Location" << endl;
        SetConsoleTextAttribute(hOut, 7);
        cout << "(Lower case characters are accepted)" << endl;
        cout << "*****************" << endl;
        SetConsoleTextAttribute(hOut, 15);
        cout << "Seat Location: ";
        SetConsoleTextAttribute(hOut, 11);
        getline(cin, add_new.location);
        SetConsoleTextAttribute(hOut, 15);

        // change all english small letters to capital letters
        add_new.location = cap(add_new.location);

        // check if the user input is valid and store it in check
        check = check_location(add_new.location);

        // if check is false give an instruction for user to type the seat location again
        if (!(check))
        {
            cout << "You does not type a valid seat location, please type again" << endl;

            // if this is already false then can skip the behind check because it is already false no need to validate below
            goto skipcheck;
        }

        // check if the seat loaction has been taken or not and store it in check
        check = check_dup_location(add_new.location);

        // if check is false then give instruction that the seat position has been taken and need to enter again
        if (!(check))
        {
            cout << "The seat location has been taken, please type another seat location" << endl;
        }
        
        if (add_new.location == "")
        {
            check = FALSE;
            cout << "Input could not be empty" << endl;
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
    SetConsoleTextAttribute(hOut, 10);
    cout << endl
         << endl
         << "*** Assignment Added Successful! ***" << endl;
    cout << setw(15) << right;
    cout << "Name: " << left << add_new.name << endl;
    cout << setw(15) << right;
    cout << "Passport ID: " << left << add_new.id << endl;
    cout << setw(15) << right;
    cout << "Seat Location: " << left << add_new.location << endl
         << endl;
    SetConsoleTextAttribute(hOut, 15);

    // user need to press any button to quit this function so user can watch the input successful line and not quit to the menu
    system("pause");
}

// This function is to let user to input name and passport id to find the record and delete the record
void del()
{

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

    // Print out what is this function for
    cout << "This is the function for ";
    SetConsoleTextAttribute(hOut, 11);
    cout << "Deleting Assignment";
    SetConsoleTextAttribute(hOut, 15);
    cout << "!" << endl;

    // this is a loop if cannot find user input
    do
    {

    del_start:
        cout << "";

        // this will loop until the user enter a valid name format
        do
        {
            // user input name
            SetConsoleTextAttribute(hOut, 7);
            cout << endl
                 << "'q' to go back Main Menu" << endl;
            cout << "*****************" << endl
                 << endl;
            SetConsoleTextAttribute(hOut, 15);
            cout << "Please type in a ";
            SetConsoleTextAttribute(hOut, 3);
            cout << "Name" << endl;
            SetConsoleTextAttribute(hOut, 7);
            SetConsoleTextAttribute(hOut, 15);
            cout << "Name: ";
            SetConsoleTextAttribute(hOut, 11);
            getline(cin, find_del.name);
            SetConsoleTextAttribute(hOut, 15);
            // user press q that means they want to quit so it will end this function
            if (find_del.name == "q")
            {
                return;
            }

            // check if the name is valid or not
            check = check_name(find_del.name);

            // if it is not valid, give instruction to tell them they need to enter it again
            if (!(check))
            {
                cout << "You typed in inappropriate letters, please type in again." << endl;
            }

            if (find_del.name == "")
            {
                check = FALSE;
                cout << "Input could not be empty" << endl;
            }
        } while (!(check)); // until check is true

        // reset the check value
        check = 0;

        // cahnge suitable amall english letters to capital english letters
        find_del.name = cap_name(find_del.name);

        // this will loop until the user input passport id is valid or not
        do
        {

            // user input the passport id
            cout << endl
                 << "Please enter your ";
            SetConsoleTextAttribute(hOut, 3);
            cout << "Passport ID" << endl;
            SetConsoleTextAttribute(hOut, 7);
            cout << "(Lower case characters are accepted)" << endl;
            cout << "*****************" << endl;
            SetConsoleTextAttribute(hOut, 15);
            cout << "Passport ID: ";
            SetConsoleTextAttribute(hOut, 11);
            getline(cin, find_del.id);
            SetConsoleTextAttribute(hOut, 15);

            // check if the passport id is valid or not
            check = check_id(find_del.id);

            // it is not valid then give instruction to them that they need to type the passport id again
            if (!(check))
            {
                cout << "You typed in inappropriate letters, please type in again" << endl;
            }
            if (find_del.id == "")
            {
                check = FALSE;
                cout << "Input could not be empty" << endl;
            }

        } while (!(check)); // loop until check is true

        // change the small english letters in the user input to capital letters
        find_del.id = cap(find_del.id);

        // combine the name and id together
        all = find_del.name + "/" + find_del.id;
        SetConsoleTextAttribute(hOut, 7);
        system("CLS");
        cout << "Searching for \"" << all << "\"..." << endl
             << endl;
        SetConsoleTextAttribute(hOut, 15);

        // make sure the txt file is open so it won't be error
        open_file();

        // read the txt file to update the all_cus_info vector
        read_file();

        // check if it can be found in the vectorand give the result for user to know
        if (find(all) == -1)
        {
            SetConsoleTextAttribute(hOut, 12);
            cout << "Record Not found!" << endl;
            cout << "Please check your input and try again" << endl;
        }
        else
        {
            SetConsoleTextAttribute(hOut, 10);
            cout << "Record Found!" << endl; // or else it would be found
        }

        // if the particular record can't find, give instruction to user to repeat the process again
        // as they can press q to quit the function when inputting the name so here can be looped
    } while (find(all) == -1);

    // here to let people to make sure  they want to delete the record that found
    if (!(find(all) == -1))
    {

        // this will be looped until they input 1 or input 2
        do
        {
            // as the record will be deleted forever so this just to make sure that they want to delete the record
            SetConsoleTextAttribute(hOut, 15);
            cout << "*****************" << endl;
            cout << "Are you sure that you want to delete this record?" << endl;
            SetConsoleTextAttribute(hOut, 7);
            cout << "(This action could not be undo)" << endl;
            cout << "*****************" << endl;
            SetConsoleTextAttribute(hOut, 12);
            cout << "[1] ";
            cout << "Delete" << endl;
            SetConsoleTextAttribute(hOut, 15);
            cout << "[2] ";
            cout << "Cancel" << endl;
            SetConsoleTextAttribute(hOut, 11);
            cin >> sure;
            SetConsoleTextAttribute(hOut, 11);

            // make sure the user input only one character
            if (!(sure.length() == 1))
            {
                cout << "Invalid input" << endl;
            }
            else
            {
                // make sure that they type 1 or 2 instead of other character
                if ((!(sure[0] == '1')) && (!(sure[0] == '2')))
                {
                    SetConsoleTextAttribute(hOut, 12);
                    cout << endl
                         << "Invalid input" << endl;
                }
                else
                {
                    cin.ignore();
                }
            }

        } while ((!(sure.length() == 1)) || ((!(sure[0] == '1')) && (!(sure[0] == '2')))); // until the input is valid

        // after passing the part that valid user input
        // this situation is when user type 1
        if (sure[0] == '1')
        {

            // delete the particular vector record which is the record that user want to delete
            all_cus_info.erase(all_cus_info.begin() + find(all) - 1);

            // rewrite the file using the updated vector
            write_whole_file();

            // give instruction that the particular item is deleted for user to know
            SetConsoleTextAttribute(hOut, 10);
            cout << endl
                 << "\"" << all << "\""
                 << " Deleted Successfully!" << endl;
            SetConsoleTextAttribute(hOut, 15);
        }
        else if (sure[0] == '2')
        {
            SetConsoleTextAttribute(hOut, 15);
            cout << endl
                 << "Delete Operation Canceled." << endl;
            goto del_start; // otherwise go to the start of the program and type another record
        }

        else
        {
            goto del_start; // otherwise go to the start of the program and type another record
        }
    }

    // when the function is ended they can see the input and out put until they press a button so they know what is successfully deleted
    system("pause");
}

// this function is for people to enter multiple record at the same time
void batch_addition()
{
    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // this is used to store the unsuccessfully save record
    unsuccessful.clear();

    // this is used to store the successful record
    successful.clear();

    // this is used for storing user input
    string input;

    // make sure store.txt file is opened so it won't have any error occur
    open_file();

    //update the all_cus_info using the data stored in store.txt
    read_file();

    // give user instruction of format that they need to type in
    cout << "This is the function for ";
    SetConsoleTextAttribute(hOut, 11);
    cout << "Adding Assignments in Batch";
    SetConsoleTextAttribute(hOut, 15);
    cout << "!" << endl;
    SetConsoleTextAttribute(hOut, 7);
    cout << "(Type '0' at the end of the input)" << endl;
    cout << "(Type '0' to go back Main Menu)" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << endl
         << endl;
    cout << "Please enter the users' details as following format:" << endl;
    cout << "Format: ";
    SetConsoleTextAttribute(hOut, 143);
    cout << "Name/PassportID/Seat" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "*****************" << endl;
    SetConsoleTextAttribute(hOut, 11);

    // while the user does not input string 0 it will loop
    do
    {
        // now_succuess is a boolean that is for input validation
        bool now_success = 1;

        // user input
        getline(cin, input);

        // break a to name , passport id and location, extract imformation by "name/id/location" format
        string a = input;
        string name = breaking(a);
        string id = breaking(a);
        string location = a;

        // if the breaking does not work then the now_success is false
        if (name == "" || id == "" || location == "")
        {
            now_success = 0;
        }

        // passed the first layer of validation now check the name, passport id and seat location is valid or not
        // if one of them are false then now_success is flase
        else
        {
            if ((!check_name(name)) || (!check_id(id)) || (!check_location(location)))
            {
                now_success = 0;
            }
            // then it passed the second layer of validation
            else
            {
                // cahnge suitable amall english letters to capital english letters
                name = cap_name(name);

                // change all small english letters to the capital letters
                id = cap(id);

                // change all small english letters to the capital letters
                location = cap(location);

                // check if the seat location has been taken yet
                if ((check_dup_location(location)) && (check_dup_id(id)) && (check_dup_location_success(location)) && (check_dup_id_success(id)))
                {

                    // if it has not been taken then combine name, passport id and seat location to a
                    a = name + "/" + id + "/" + location;
                }

                // otherwise it is not valid
                else
                {
                    now_success = 0;
                }
            }
        }
        // check if now_success is true or not
        // if true, push to successful vector
        if (now_success)
        {

            // push the combined valid string to successful vector
            successful.push_back(a);
        }

        // otherwise push to unsuccessful vector
        else
        {

            // push the output to the back of the unsuccessful vector
            unsuccessful.push_back(input);
        }

    } while (!((input.length() == 1) && (input[0] == '0'))); // this will loop until user only type 0 as the input

    // store the current working term of vector successful to temp and this loop will loop the size of vector times
    for (string temp : successful)
    {

        // write all the string in the successful list to the store.txt file
        write_file(temp);
    }

    // give instruction to users that this is displayed for successful list
    SetConsoleTextAttribute(hOut, 15);
    system("CLS");
    cout << "Operation Made." << endl
         << endl;
    SetConsoleTextAttribute(hOut, 10);
    cout << endl
         << "*****************" << endl;
    cout << "Successful list:" << endl;

    // store the current working term of vector successful to temp and this loop will loop the size of vector times
    for (string temp : successful)
    {

        // output the successful vector data
        cout << temp << endl;
    }

    // open some new rows to make sure the two list can be seperated and displayed clearly
    cout << "*****************";
    SetConsoleTextAttribute(hOut, 12);
    cout << endl
         << endl;
    cout << "*****************" << endl;

    // give instruction to users that this is displayed for the unsuccessful list
    cout << "Unuccessful list:" << endl;

    // store the current working term of vector unsuccessful to temp and this loop will loop the size of vector times
    for (string temp : unsuccessful)
    {

        // As the 0 input will also push to this unsuccessful list
        if (!((temp.length() == 1) && (temp[0] == '0')))
        {

            // output the unsuccessful vector data
            cout << temp << endl;
        }
    }

    // when the function is ended they can see the input and out put until they press a button so they know what is successfully deleted
    cout << "*****************" << endl
         << endl;
    SetConsoleTextAttribute(hOut, 15);

    // give instruction that users correct it individually
    // we assume people only write it
    cout << endl
         << "Please correct the ";
    SetConsoleTextAttribute(hOut, 12);
    cout << "Unsuccessful Input" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "*****************" << endl
         << endl;

    // let user to correct the unsuccessful list
    for (string temp : unsuccessful)
    {

        // as the successful list may contain 0 in the end so that we return to menu
        if (temp == "0")
        {
            system("pause");
            return;
        }
        // make a user input
        string user_input;

        // said correct which particular record
        SetConsoleTextAttribute(hOut, 15);
        cout << "Please correct this plarticular record ";
        SetConsoleTextAttribute(hOut, 13);
        cout << "\"" << temp << "\"" << endl;
        SetConsoleTextAttribute(hOut, 15);

        // reminds them can only input once
        SetConsoleTextAttribute(hOut, 7);
        cout << "There will not be another chance for you to correct again" << endl;
        SetConsoleTextAttribute(hOut, 13);
        getline(cin, user_input);

        // break it to three different feild to check validation
        string a = user_input;
        string name = breaking(a);
        string id = breaking(a);
        string location = a;

        // change all english letters to the suitable form, small or capital
        name = cap_name(name);
        id = cap(id);
        location = cap(location);

        // validation
        if (check_name(name) && check_id(id) && check_location(location) && check_dup_id(id) && check_dup_location(location))
        {

            // if valid combine three feilds then write to the txt file
            a = name + "/" + id + "/" + location;
            write_file(a);

            // give instructions that this is successfully input, and start the next feild
            cout << endl
                 << "\"" << a << "\"";
            SetConsoleTextAttribute(hOut, 10);
            cout << endl
                 << "Input Successful!" << endl;
            SetConsoleTextAttribute(hOut, 15);
            cout << "*****************" << endl
                 << endl;

            // delay so they can watch if it is successfully input
            Sleep(microsecond);
        }
        else
        {

            // otherwise said it is not successfully input and start the next feild
            SetConsoleTextAttribute(hOut, 12);
            cout << endl
                 << "Input Unsuccessful"
                 << "\t";
            SetConsoleTextAttribute(hOut, 15);
            cout << "\"" << user_input << "\" is not valid" << endl;
            SetConsoleTextAttribute(hOut, 7);
            cout << endl;
            cout << "*****************" << endl;
            SetConsoleTextAttribute(hOut, 15);
        }
    }
}

//This is a function that can return the position of the vector and if not found return -1
int find_position_by_location(string a)
{
    int i = 0; // this is the number of position of the vector
    string::size_type position;
    // The string temp will store the data of the all_cus_info feild that stored into the string temp
    // it will run the the size of the all_cus_info times
    for (string temp : all_cus_info)
    {
        i++;
        int location_length = temp.length() - temp.find_last_of("/") - 1; //find the location length of the stored data by ( total length - the last "/" exist's location - 1)
        temp = temp.substr(temp.find_last_of("/") + 1, location_length);  //extract the location from default format
        position = temp.find(a);                                          //search position by the extracted location
        // if not found it will ruturn certain number which means not found
        // if found
        //the first condititon is indicating found or not found, the second condition is ensure the length is same which preventing "1C" can be found in "11C"
        if ((position != temp.npos) && (temp.length() == a.length()))
        {
            // return i which is the number which ith term of the vector is the target
            return i;
        }
    }
    // if not found then return -1 why -1 is because there are no -1th feild in the vector
    return -1;
}

// This is the function that display the info in part 5 and find class part
void display_info(int a)
{
    // if a is one that means this is first class which will display the first class name
    if (a == 1)
    {

        // As this is a nested loop we use to divided into column and rows
        // there are two rows in the first class so loop two times
        for (int row = 1; row < 3; row++) //for row
        {
            // column has 6, A to F
            // why we start at 65 because char(65) is A and char(70) is F
            for (int col = 65; col < 71; col++) //for col, col is in ascii code for looping
            {
                string temp = to_string(row);                // change the row number to string
                char temp1 = (char)col;                      // change the ascii code to char
                string location = temp + temp1;              //merge the row and col into 1 string
                int i = find_position_by_location(location); //find position by location
                //result display
                // i = -1 that means it is not found and it will display vacant
                if (i == -1)
                {
                    SetConsoleTextAttribute(hOut, 10);
                    cout << right << row << (char)col << ": " << left << setw(25) << "vacant ";
                    SetConsoleTextAttribute(hOut, 15);
                }
                else
                {
                    // if i not = 1 that means we found the seat location and it can display the passenger name
                    SetConsoleTextAttribute(hOut, 12);
                    cout << right << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i - 1]);
                    SetConsoleTextAttribute(hOut, 15);
                    read_file();
                }
            }
            // open a new line to display the width
            cout << "\n";
        }
    }

    // if a = 2 that means it is business
    else if (a == 2)
    {
        // business is from row 3 to row 7
        for (int row = 3; row < 8; row++)
        {
            // why we start at 65 because char(65) is A and char(70) is F
            for (int col = 65; col < 71; col++)
            {
                string temp = to_string(row);                // change the row number to string
                char temp1 = (char)col;                      // change the ascii code to char
                string location = temp + temp1;              //merge the row and col into 1 string
                int i = find_position_by_location(location); //find position by location
                //result display
                // i = -1 that means it is not found and it will display vacant
                if (i == -1)
                {
                    SetConsoleTextAttribute(hOut, 10);
                    cout << right << row << (char)col << ": " << left << setw(25) << "vacant ";
                    SetConsoleTextAttribute(hOut, 15);
                }
                else
                {
                    // if i not = 1 that means we found the seat location and it can display the passenger name
                    SetConsoleTextAttribute(hOut, 12);
                    cout << right << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i - 1]);
                    SetConsoleTextAttribute(hOut, 15);
                    read_file();
                }
            }
            // open a new line to display the width
            cout << "\n";
        }
    }
    else
    {
        // this is economy class as row 8 to row 14
        for (int row = 8; row < 14; row++)
        {
            // why we start at 65 because char(65) is A and char(70) is F
            for (int col = 65; col < 71; col++)
            {
                string temp = to_string(row);                // change the row number to string
                char temp1 = (char)col;                      // change the ascii code to char
                string location = temp + temp1;              //merge the row and col into 1 string
                int i = find_position_by_location(location); //find position by location
                //result display
                // i = -1 that means it is not found and it will display vacant
                if (i == -1)
                {
                    SetConsoleTextAttribute(hOut, 10);
                    cout << setw(2) << right << row << (char)col << ": " << left << setw(25) << "vacant ";
                    SetConsoleTextAttribute(hOut, 15);
                }
                else
                {
                    // if i not = 1 that means we found the seat location and it can display the passenger name
                    SetConsoleTextAttribute(hOut, 12);
                    cout << setw(2) << right << row << (char)col << ": " << left << setw(25) << breaking(all_cus_info[i - 1]);
                    SetConsoleTextAttribute(hOut, 15);
                    read_file();
                }
            }
            // open a new line to display the width
            cout << "\n";
        }
    }
}

int class_indentifier(string a) // return class type for searchin
{
    // first class return 1
    if (a == "FIRST")
        return 1;
    // business class return 2
    else if (a == "BUSINESS")
        return 2;
    // economy class return 3
    else if (a == "ECONOMY")
        return 3;
    else
        // not found -1
        return -1;
}

// it will find the passenger
void find_passenger()
{
    string temp = "";
    int i = 0;
    string none;
    do
    {
        // clear screen so the user interface is cleaner
        system("CLS");

        // user input
        cout << "*** Search By Passenger Passport ID ***" << endl;
        SetConsoleTextAttribute(hOut, 7);
        cout << "'q' to go back Main Menu" << endl;
        cout << "*****************" << endl
             << endl;
        cout << "Please enter a ";
        SetConsoleTextAttribute(hOut, 3);
        cout << "Passport ID" << endl;
        SetConsoleTextAttribute(hOut, 7);
        cout << "(Lower case characters are accepted)" << endl;
        cout << "*****************" << endl;
        SetConsoleTextAttribute(hOut, 15);
        cout << "Passport ID: ";
        SetConsoleTextAttribute(hOut, 11);
        getline(cin, temp);
        SetConsoleTextAttribute(hOut, 15);

        // if user want to quit input q then return to menu
        if (temp == "q")
        {
            return;
        }

        // change all english to capital so they can input the english in different way as long as they spell it right
        temp = cap(temp);

        // find by the user input, where i is the position of the vector
        i = find(temp);
        int id_length = 0;

        // if not found give error message
        if (i == -1)
        {
            cout << "No required passenger id found" << endl;
            Sleep(microsecond);
        }
        else
        {
            // if correct input
            if (!(i == -1))
            {
                // find the passenger from vector
                id_length = all_cus_info[i - 1].find_last_of("/") - all_cus_info[i - 1].find_first_of("/") - 1;
                string temp_info = all_cus_info[i - 1];

                // display the the personal information
                //id_length is to prevent finding "A123" from "BA12345" by ensure the uin id length is same as acutal id length
                if (temp.length() == id_length)
                {
                    //extract information from "name/id/location" format
                    SetConsoleTextAttribute(hOut, 10);
                    cout << endl
                         << setw(9) << "";
                    cout << "Record Found!" << endl; // or else it would be found
                    cout << "****************************" << endl;
                    SetConsoleTextAttribute(hOut, 15);
                    cout << setw(15) << right;
                    cout << "Name: " << left << breaking(temp_info) << "\n";
                    cout << setw(15) << right;
                    cout << "Passport ID: " << left << breaking(temp_info) << "\n";
                    cout << setw(15) << right;
                    cout << "Seat Location: " << left << temp_info << "\n";

                    // try to identify the seat location
                    //3 digit of temp_info which is location must be economy class
                    if (temp_info.length() == 3)
                    {
                        cout << setw(8) << "";
                        cout << "Class: Economy" << endl;
                    }
                    //the first digit of temp_info which is location >=8 is business class
                    else
                    {
                        if (temp_info[0] >= '8')
                        {
                            cout << setw(8) << "";
                            cout << "Class: Economy" << endl;
                        }
                        //the first digit of temp_info which is location >= 3 and <8 is business class
                        else
                        {
                            if (temp_info[0] >= '3')
                            {
                                cout << setw(8) << "";
                                cout << "Class: Business" << endl;
                            }
                            ////the first digit of temp_info which is location "1" and "2" is first class
                            else
                            {
                                cout << setw(8) << "";
                                cout << "Class: First" << endl;
                            }
                        }
                    }
                }
                else
                {

                    // fulfill the loop condition
                    i = -1;

                    // said not found and give error message
                    cout << "No required passenger id found" << endl;
                    cout << "Please do it again!" << endl;
                    Sleep(microsecond);
                }
            }
        }

    } while (i == -1); // loop until found
    cout << endl;
    system("Pause"); // pause to let user have as much time as they wanted to see
}

// this function is to find class which is R5 the second function
void find_class()
{
    // open a file if there is no file
    open_file();

    // read file and store the data to all_cus_info
    read_file();
top:
    // clear screen
    system("CLS");

    // cout the instruction for user to follow
    SetConsoleTextAttribute(hOut, 15);
    cout << "*** Search By Passenger Passport ID ***" << endl;
    SetConsoleTextAttribute(hOut, 7);
    cout << "'q' to go back Main Menu" << endl;
    cout << "*****************" << endl
         << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "Please enter a ";
    SetConsoleTextAttribute(hOut, 3);
    cout << "Class" << endl;
    SetConsoleTextAttribute(hOut, 7);
    cout << "(Lower case characters are accepted)" << endl;
    cout << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "*** Class List ***" << endl;
    cout << "- ";
    SetConsoleTextAttribute(hOut, 3);
    cout << "First" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "- ";
    SetConsoleTextAttribute(hOut, 3);
    cout << "Business" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "- ";
    SetConsoleTextAttribute(hOut, 3);
    cout << "Economy" << endl;
    SetConsoleTextAttribute(hOut, 15);
    cout << "*****************" << endl;
    cout << "Class: ";
    string class_search = "";
    SetConsoleTextAttribute(hOut, 11);
    // user input
    getline(cin, class_search);
    SetConsoleTextAttribute(hOut, 15);

    // open new lines so that the output can be displayed clearly
    cout << endl
         << endl;

    // press q to quit the function
    if (class_search == "q")
    {
        return;
    }

    // capital all string
    class_search = cap(class_search);

    // check the class by class identifier
    int temp = class_indentifier(class_search);

    // if temp not found cout error message and start this function
    if (temp == -1)
    {
        SetConsoleTextAttribute(hOut, 12);
        cout << endl
             << "Invalid input, please input again" << endl;
        SetConsoleTextAttribute(hOut, 15);
        Sleep(microsecond);
        goto top;
    }
    // go to display info
    else
    {
        display_info(temp); //search the information by class
    }
    // so people to can display
    system("Pause");
}

void show_details()
{
    open_file(); // make sure that the file is open
    read_file(); // update the vector all_cus_info

    // set it to string so that it won't have runtime error just in case
    string user_input;
    do
    {
        // clear screen just to make the interface tidier
        system("CLS");

        // Print what is this function is about
        cout << "This is the function for ";
        SetConsoleTextAttribute(hOut, 11);
        cout << "Checking the Details of Passsenger";
        SetConsoleTextAttribute(hOut, 15);
        cout << "!" << endl
             << endl;

        // print the menu
        cout << "*** Search By ***\n";
        SetConsoleTextAttribute(hOut, 11);
        cout << "[1] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Passenger\n";
        SetConsoleTextAttribute(hOut, 11);
        cout << "[2] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Class\n";
        SetConsoleTextAttribute(hOut, 11);
        cout << "[3] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Back\n";
        cout << "*****************\n";

        // tell user what to do
        cout << "Option (1-3): ";

        // get line so that even blank space can be input just for people use it in the wrong way and it may make the program
        // go not the same way
        SetConsoleTextAttribute(hOut, 11);
        getline(cin, user_input);
        SetConsoleTextAttribute(hOut, 15);

        // set the each outcome to different functions
        if (user_input == "1")
            find_passenger();
        else if (user_input == "2")
            find_class();
        else if (user_input == "3")
            return; // exit then go back to the main menu
        else
        {
            // give error message to the user if they type wrong
            SetConsoleTextAttribute(hOut, 12);
            cout << endl
                 << "Invalid input, please input again" << endl;
            SetConsoleTextAttribute(hOut, 15);
            Sleep(microsecond);
        }
        // repeat until they follow instruction
    } while ((!(user_input == "3")));
}

void latest_seating_plan()
{
    // clear screen for the tidy interface
    system("CLS");

    // open the file if not yet opened
    // update the vector
    open_file();
    read_file();

    // the upeer bar to show which is column is each particular column
    cout << "  \tA\tB\tC\tD\tE\tF\n";
    for (int row = 1; row < 14; row++) // show row
    {
        // show the row number
        cout << setw(2) << row << "\t";

        for (int col = 65; col < 71; col++) //show colume, colume is in ascii code for looping, col = 65 is "A", 70 is "F"
        {
            string temp = to_string(row);                    // change the row number to string
            char temp1 = (char)col;                          // change the ascii code to char
            string location = temp + temp1;                  //merge the row and col into 1 string
            int temp3 = find_position_by_location(location); //find position by location
            if (temp3 == -1)
            {
                SetConsoleTextAttribute(hOut, 10);
                cout << "*\t"; // if vacant then show *
                SetConsoleTextAttribute(hOut, 15);
            }
            else
            {
                SetConsoleTextAttribute(hOut, 12);
                cout << "X\t"; //if not vacant then show X
                SetConsoleTextAttribute(hOut, 15);
            }
        }
        cout << "\n"; // open a new line for the loop so it will difplay like a table
    }
    system("pause");
}

// This function is the intro of the program which print welcome and the logo of hkcc airline
void show_intro()
{

    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // change the color of the word so it can catch customers eyeball
    system("Color 03");

    // print the welcome
    cout << "*************************" << endl;

    // used delay to create some kind of aniamtion to catch users' eyeball
    Sleep(microsecond / 5);
    cout << "*Welcome to HKCC Airline*" << endl;
    Sleep(microsecond / 5);
    cout << "*************************" << endl;
    Sleep(microsecond);

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
        )";
    Sleep(1 * microsecond);
}

// this function is used to simulate the loading in the system so it seems to be a legit system
void loading_animation()
{

    // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
    system("CLS");

    // change back the font color so that the whole program will display in normal color
    system("Color 07");

    cout << "Loading";

    // use the delay to simulate the loading bar
    Sleep(microsecond / 5);
    cout << ".";
    Sleep(microsecond / 5);
    cout << ".";
    Sleep(microsecond / 5);
    cout << "." << endl;
    Sleep(microsecond / 2);
}

// this is the function of the main menu which display the menu and people can go to their wanted function of this program
void menu()
{

    // This is a string variable that stores users input
    string user_input = "-1";

    // this is a variable that used to store the converted user input to character
    char user_input_char = 'p';

    int count = 0;

    // the loop won't stop until user type 6 which is the exit function
    do
    {

        // This is system clear screen which is a system function which will clear the terminal screen so it is way more cleaner
        system("CLS");

        // Displays the main menu and gives instructions which input will go to which function
        SetConsoleTextAttribute(hOut, 15);
        cout << "Welcome to the ";
        SetConsoleTextAttribute(hOut, 11);
        cout << "HKCC Airline's ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Airplane Seating Assignment System" << endl
             << endl;
        cout << "*** Main Menu ***" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[1] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Add An Assignment" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[2] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Delete An Assignment" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[3] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Add Assignments in Batch" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[4] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Show Latest Seating Plan" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[5] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Show Details" << endl;
        SetConsoleTextAttribute(hOut, 11);
        cout << "[6] ";
        SetConsoleTextAttribute(hOut, 15);
        cout << "Exit" << endl;
        cout << "*****************" << endl;
        cout << "Option (1-6): ";
        SetConsoleTextAttribute(hOut, 11);

        // user input

        getline(cin, user_input);

        // check if user only input one character
        if (!(user_input.length() == 1))
        {

            // if users input more than one character than it will show invalid input and start to display main menu
            SetConsoleTextAttribute(hOut, 12);
            cout << endl
                 << "Invalid input, please input again" << endl;
            SetConsoleTextAttribute(hOut, 15);

            // to let user see the invalid input , here put in delay
            Sleep(microsecond);
        }

        // otherwise
        else
        {

            // store the first character of the string to user_input_char
            user_input_char = user_input[0];
            SetConsoleTextAttribute(hOut, 15);

            // do a switch so it will do different things in different situation
            switch (user_input_char)
            {

                // Add an assignment
            case '1':
                add();
                Sleep(microsecond);
                break;

                // Delete an assignment
            case '2':
                del();
                Sleep(microsecond);
                break;

                // Add assignments in batch
            case '3':
                batch_addition();
                Sleep(microsecond);
                break;

                // Show latest seating plan
            case '4':
                latest_seating_plan();
                Sleep(microsecond);
                break;

                // Show details
            case '5':
                show_details();
                Sleep(microsecond);
                break;

                // thank people using this system
            case '6':
                cout << endl;
                SetConsoleTextAttribute(hOut, 10);
                cout << "Thank you for using this system.";
                SetConsoleTextAttribute(hOut, 15);
                Sleep(2 * microsecond);
                system("CLS");
                break;

                // other than 1-6 others are all invalid input and user need to type again
            default:
                SetConsoleTextAttribute(hOut, 12);
                cout << endl
                     << "Invalid input, please input again" << endl;
                SetConsoleTextAttribute(hOut, 15);
                Sleep(microsecond);
                break;
            }
        }
    } while ((!(user_input.length() == 1)) || (!(user_input_char == '6'))); // until the user type in 6 to end the program
}

int main()
{
    // set up
    setup_color();

    // show the introduction to people
    show_intro();

    // simulate loading screen
    loading_animation();

    // go to the main menu
    menu();

    // give a sign for the computer that this is the end of the program
    return 0;
}