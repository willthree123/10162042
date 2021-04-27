#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NMSG = 3;    // (Global) maximum no. of messages
const int MAXLEN = 80; // (Global) maximum length of each message

void printReverse(char[][MAXLEN]); //prototype

int main()
{
    char message[NMSG][MAXLEN];

    // Your code should be inserted here
    for (int i = 0; i < NMSG; i++) // NMSG = 3
    {
        cout << "Enter message" << i << ": ";
        cin.getline(message[i], MAXLEN, '\n');
    }

    printReverse(message);

    return 0;
}

void printReverse(char msg[][MAXLEN])
{
    cout << "\nThe messages are printed in a last-in-first-out sequence. \n";
    cout << "Characters in each message are printed in a reverse order. \n";
    for (int i = NMSG - 1; i >= 0; i--)
    {
        cout << "Message " << i << ": ";
        for (int j = strlen(msg[i]) - 1; j >= 0; j--)
        {
            cout << msg[i][j];
        }
        cout << endl;
    }
}