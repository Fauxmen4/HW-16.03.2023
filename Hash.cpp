#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string HashFunctionASCII(const string &input) {
    unsigned long long hashValue = 1;
    for (auto i = input.begin(); i != input.end(); i++) {
        hashValue *= (int)(*i);
    }
    return to_string(hashValue);
}

string HashFunctionStatistics(const string &input) {
    string hashValue = "";
    int *charStatistics = new int[128];
    for (auto i = input.begin(); i != input.end(); i++) {
        charStatistics[(int)(*i)]++;
    }
    for (int i = 0; i < 128; i++) {
        if (charStatistics[i] != 0) {
            hashValue.append(to_string(charStatistics[i]));
        }
    }
    return hashValue;
}

int main()
{
    ifstream myFile_Handler;
    string myLine;

    // File Open in the Read Mode
    myFile_Handler.open("flag.txt");

    if(myFile_Handler.is_open())
    {
        // Keep reading the file
        while(getline(myFile_Handler, myLine))
        {
            // print the line on the standard output
            cout << myLine << endl;
        }
    // File Close
    myFile_Handler.close();
    }
    else
    {
        cout << "Unable to open the file!";
    }
    return 0;
}