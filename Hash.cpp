#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string HashFunctionASCII(string input) {
    unsigned long long hashValue = 1;
    for (auto i = input.begin(); i != input.end(); i++) {
        hashValue += (int)(*i);
    }
    return to_string(hashValue);
}

string HashFunctionStatistics(string input) {
    string hashValue;
    int *charStatistics = new int[128];
    for (auto i = input.begin(); i != input.end(); i++) {
        charStatistics[(int)(*i)]++;
    }
    for (int i = 0; i < 128; i++) {
        if (charStatistics[i] != 0) {
            hashValue += to_string(charStatistics[i]);
        }
    }
    return hashValue;
}

int main() {
    // ifstream myFileHandler;
    // const string FILENAME = "/home/fauxmen4/AMCP/IntroductionToProgramming/HW-16.03.2023/flag.txt";
    // myFileHandler.open(FILENAME);

    // if(myFileHandler.is_open()) {
    //     string myLine;
    //     while(getline(myFileHandler, myLine)) {
    //         cout << myLine << endl;
    //     }
    //     myFileHandler.close();
    // } else {
    //     cout << "Unable to open file";
    // }

    string fileContent = "";
    char ch;
    ifstream fin("/home/fauxmen4/AMCP/IntroductionToProgramming/HW-16.03.2023/TextSample/World-War-Z.txt");
    for (int i = 0; i < 100; i++) {
        fin.get(ch);
        fileContent += ch;
    }
    fin.close();
    cout << HashFunctionStatistics(fileContent) << '\n';
    return 0;
}