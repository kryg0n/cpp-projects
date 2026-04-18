#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;

    // keep reading lines until end of input
    while (getline(cin, line)) {

        // start from the last character and go backwards
        for (int i = line.length() - 1; i >= 0; i--) {

            char ch = line[i];

            // switch case of the letter
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 32;     // small letter becomes big
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;     // big letter becomes small
            }

            // print the character right away
            cout << ch;
        }

        // after finishing one line, go to next line
        cout << endl;
    }

    return 0;
}