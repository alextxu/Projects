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
    // Prompt the user to input the keyword to use during decryption
    string keyword;
    cout << "Please enter the keyword: ";
    cin >> keyword;
    keyword = onlyLetters(keyword);
    keyword = lowercase(keyword);

    // Specify the input and output files
    freopen("original_vigenere_decryption_ciphertext.txt","r",stdin);
    freopen("original_vigenere_decryption_plaintext.txt","w",stdout);

    // Read input from the ciphertext file and remove all whitespace characters
    string ciphertext = "";
    string inputString;
    while (cin >> inputString) {
        ciphertext += inputString;
    }

    // Decrypt the message
    string plaintext = "";
    for (int i = 0;i < ((int) ciphertext.size());i++) {
        char letter = ciphertext[i];
        char keyChar = keyword[i % ((int) keyword.size())];

        int ciphertextNumber = letter - ((int) 'a');
        int keyNumber = keyChar - ((int) 'a');

        int plaintextNumber = ((ciphertextNumber - keyNumber) % 26 + 26) % 26;

        char plaintextChar = plaintextNumber + ((int) 'a');
        plaintext += plaintextChar;
    }

    // Output the decrypted text
    cout << plaintext << endl;

    return 0;
}