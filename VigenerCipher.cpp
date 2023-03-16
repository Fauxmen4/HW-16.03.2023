#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_LENGTH = 26;
const int FIRST_ALPHABET_LETTER_IN_ASCII = 97;

int CharCode(char s) {
    return (int)s - FIRST_ALPHABET_LETTER_IN_ASCII;
}

string VigenerEncrypt(const string &input, const string &key) {
    string output;
    for(int i = 0; i < input.length(); i++) {
        output += (char)((CharCode(input[i]) + CharCode(key[i % key.length()])) % ALPHABET_LENGTH + FIRST_ALPHABET_LETTER_IN_ASCII);
    }
    return output;
}

string VigenerDecrypt(const string &input, const string &key) {
    string output = "";
    for(int i = 0; i < input.length(); i++) {
        output += (char)((CharCode(input[i]) - CharCode(key[i % key.length()]) + ALPHABET_LENGTH) % ALPHABET_LENGTH + FIRST_ALPHABET_LETTER_IN_ASCII);
    }
    return output;
}

int main() {
    string text, key;
    int option;
    cout << "Options:" << '\n' << "1. Encryption" << '\n' << "2. Decryption" << '\n';
    cin >> option;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter key: ";
    cin >> key;
    if (option == 1) cout << "Encrypted text: " << VigenerEncrypt(text, key) << '\n';
    else cout << "Original text: " << VigenerDecrypt(text, key) << '\n';
}