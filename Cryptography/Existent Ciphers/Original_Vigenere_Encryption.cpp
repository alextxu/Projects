#include <bits/stdc++.h>

using namespace std;

// A function that returns a string with only the English letters in the string s
string onlyLetters(string s) {
    string letters;

    for (char c : s) {
        if (isalpha(c)) {
            letters += c;
        }
    }

    return letters;
}

// A function that converts all English letters in the string s to lowercase
string lowercase(string s) {
    string lower;

    for (char c : s) {
        if (isalpha(c)) {
            if (islower(c)) {
                lower += c;
            }
            else {
                lower += tolower(c);
            }
        }
        else {
            lower += c;
        }
    }

    return lower;
}

int main() {
    // Prompt the user to input the keyword to use during encryption
    string keyword;
    cout << "Please enter the keyword: ";
    cin >> keyword;
    keyword = onlyLetters(keyword);
    keyword = lowercase(keyword);

    // Specify the input and output files
    freopen("original_vigenere_encryption_plaintext.txt","r",stdin);
    freopen("original_vigenere_encryption_ciphertext.txt","w",stdout);

    // Read input from the plaintext file and remove all whitespace characters
    string plaintext = "";
    string inputString;
    while (cin >> inputString) {
        inputString = onlyLetters(inputString);
        inputString = lowercase(inputString);
        plaintext += inputString;
    }

    // Encrypt the message
    string ciphertext = "";
    for (int i = 0;i < ((int) plaintext.size());i++) {
        char plaintextChar = plaintext[i];
        char keyChar = keyword[i % ((int) keyword.size())];

        int plaintextNumber = plaintextChar - ((int) 'a');
        int keyNumber = keyChar - ((int) 'a');

        int ciphertextNumber = (plaintextNumber + keyNumber) % 26;

        char ciphertextChar = ciphertextNumber + ((int) 'a');
        ciphertext += ciphertextChar;
    }

    // Output the encrypted text
    cout << ciphertext << endl;

    return 0;
}