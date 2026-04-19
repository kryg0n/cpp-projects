#include <iostream>
#include <vector>

using namespace std;

int main() {
    int memorysize;
    int wordcount;

    cin >> memorysize >> wordcount;
    // array to store the words
    vector<int> memory;

    // count how many times we need to use the external dict
    int dictionarycount = 0;

    // process each word one by one as it comes
    for (int i = 0; i < wordcount; i++) {
        int currentword;
        cin >> currentword;

        // check if this word is already in memory
        bool found = false;
        for (int j = 0; j < memory.size(); j++) {
            if (memory[j] == currentword) {
                found = true;
                break;
            }
        }

        // if word is not in mmery, need to look in dict
        if (!found) {
            dictionarycount++;

            // if there is space in memory, just add the new word
            if (memory.size() < memorysize) {
                memory.push_back(currentword);
            }
            // if memory full, remove the oldest word 
            else {
                // remove the oldest/first word
                for (int j = 0; j < memory.size() - 1; j++) {
                    memory[j] = memory[j + 1];
                }
                memory.pop_back();

                // add the new word at the end
                memory.push_back(currentword);
            }
        }
    }

    cout << dictionarycount << endl;

    return 0;
}