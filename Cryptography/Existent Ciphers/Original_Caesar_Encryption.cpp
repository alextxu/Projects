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
    // Prompt the user to input the key to use during encryption
    int key;
    cout << "Please enter the key: ";
    cin >> key;

    // Specify the input and output files
    freopen("original_caesar_encryption_plaintext.txt","r",stdin);
    freopen("original_caesar_encryption_ciphertext.txt","w",stdout);

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
    for (char letter : plaintext) {
        int plaintextNumber = letter - ((int) 'a');
        int ciphertextNumber = (plaintextNumber + key) % 26;

        char ciphertextChar = ciphertextNumber + ((int) 'a');
        ciphertext += ciphertextChar;
    }

    // Output the encrypted text
    cout << ciphertext << endl;

    return 0;
}