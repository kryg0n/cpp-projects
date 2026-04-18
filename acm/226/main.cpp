#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {

        // start from the last character and go backwards
        for (int i = line.length() - 1; i >= 0; i--) {

            char ch = line[i];

            // switch case of the letter
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 32;     // small to big
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;     // big to small
            }

            // print the char
            cout << ch;
        }

        // after finishing one line, go to next line
        cout << endl;
    }

    return 0;
}