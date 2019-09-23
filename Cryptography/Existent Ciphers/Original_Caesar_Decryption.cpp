#include <bits/stdc++.h>

using namespace std;

int main() {
    // Prompt the user to input the key to use during decryption
    int key;
    cout << "Please enter the key: ";
    cin >> key;

    // Specify the input and output files
    freopen("original_caesar_decryption_ciphertext.txt","r",stdin);
    freopen("original_caesar_decryption_plaintext.txt","w",stdout);

    // Read input from the ciphertext file and remove all whitespace characters
    string ciphertext = "";
    string inputString;
    while (cin >> inputString) {
        ciphertext += inputString;
    }

    // Decrypt the message
    string plaintext = "";
    for (char letter : ciphertext) {
        int ciphertextNumber = letter - ((int) 'a');
        int plaintextNumber = ((ciphertextNumber - key) % 26 + 26) % 26;

        char plaintextChar = plaintextNumber + ((int) 'a');
        plaintext += plaintextChar;
    }

    // Output the decrypted text
    cout << plaintext << endl;

    return 0;
}