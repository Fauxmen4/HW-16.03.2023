#include <iostream>
#include <string>
#include <fstream>

using namespace std;

unsigned long long HashFunctionASCII(string input) {
    unsigned long long hashValue = 1;
    for (auto i = input.begin(); i != input.end(); i++) {
        if ((int)(*i) != 0) {
        hashValue *= (unsigned long long)(*i);
        }
    }
    return hashValue;
}

int main() {    
    setlocale(LC_ALL, "ru");
    const int HASH_ARR_LENGTH = 6548;
    int hashDublicateCount = 0;
    unsigned long long *hashArr = new unsigned long long[HASH_ARR_LENGTH];
    ifstream fin("/home/fauxmen4/AMCP/IntroductionToProgramming/HW-16.03.2023/TextSample/World-War-Z.txt");

    for(int i = 0; i < HASH_ARR_LENGTH; i++) {
        char tmpCh;
        string tmpString = "";
        for (int j = 0; j < 10; j++) {
            fin.get(tmpCh);
            tmpString += tmpCh;
        }
        hashArr[i] = HashFunctionASCII(tmpString);
    }
    fin.close();

    for (int i = 0; i < HASH_ARR_LENGTH; i++) {
        for (int j = 0; j < HASH_ARR_LENGTH; j++) {
            if (hashArr[i] == hashArr[j] && i != j) {
                hashDublicateCount++;
            }
        }
    }
    cout << "Количество совпадений значений хэша при подсчёте произведения символов ASCII: " << hashDublicateCount << '\n';

    return 0;
}