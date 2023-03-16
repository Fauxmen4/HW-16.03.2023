#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string HashFunctionStatistics(string input) {
    string hashValue;
    int *charStatistics = new int[128];
    for (int i = 0; i < 128; i++) {
        charStatistics[i] = 0;
    }
    for (auto i = input.begin(); i != input.end(); i++) {
        charStatistics[(int)(*i)]++;
    }
    for (int i = 0; i < 128; i++) {
        hashValue += to_string(charStatistics[i]);     
    }
    return (string)hashValue;
}

int main() {
    setlocale(LC_ALL, "ru");
    const int HASH_ARR_LENGTH = 6548;
    int hashDublicateCount = 0;
    vector <string> hashArr;
    ifstream fin("/home/fauxmen4/AMCP/IntroductionToProgramming/HW-16.03.2023/TextSample/World-War-Z.txt");

    for(int i = 0; i < HASH_ARR_LENGTH; i++) {
        char tmpCh;
        string tmpString = "";
        for (int j = 0; j < 10; j++) {
            fin.get(tmpCh);
            tmpString += tmpCh;
        }
        hashArr.push_back(HashFunctionStatistics(tmpString));
    }
    fin.close();

    for (int i = 0; i < HASH_ARR_LENGTH; i++) {
        for (int j = 0; j < HASH_ARR_LENGTH; j++) {
            if (hashArr[i] == hashArr[j] && i != j) {
                hashDublicateCount++;
            }
        }
    }
    cout << "Количество совпадений значений хэша при подсчёте статистики символов: " << hashDublicateCount << '\n';

    return 0;
}