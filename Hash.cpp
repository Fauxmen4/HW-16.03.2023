#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string HashFunctionASCII(string input) {
    unsigned long long hashValue = 1;
    for (auto i = input.begin(); i != input.end(); i++) {
        hashValue *= (int)(*i);
    }
    return to_string(hashValue);
}

string HashFunctionStatistics(string input) {
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

int main() {
    
}