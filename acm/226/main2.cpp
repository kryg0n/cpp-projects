#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {

        vector<char> chars;

        // array for ease
        for (int i = 0; i < line.length(); i++) {
            chars.push_back(line[i]);
        }

        // reverse order
        for (int i = chars.size() - 1; i >= 0; i--) {

            char ch = chars[i];

            // switch case of the letter
            if (ch >= 'a' && ch <= 'z') {
                ch = ch - 32;     // small to big
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;     // big to small
            }

            cout << ch;
        }
        cout << endl;
    }

    return 0;
}