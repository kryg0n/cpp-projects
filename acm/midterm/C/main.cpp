#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cacheSize, numObjects, numAccesses;

    while (cin >> cacheSize >> numObjects >> numAccesses) {
        vector<int> accesses;

        for (int i = 0; i < numAccesses; i++) {
            int obj;
            cin >> obj;
            accesses.push_back(obj);
        }

        vector<int> cache;
        int reads = 0;

        for (int i = 0; i < numAccesses; i++) {
            int obj = accesses.at(i);

            bool found = false;
            for (int j = 0; j < (int)cache.size(); j++) {
                if (cache.at(j) == obj) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                reads++;
                if ((int)cache.size() < cacheSize) {
                    cache.push_back(obj);
                } else {
                    int evictIndex = -1;
                    int farthest = -1;

                    for (int j = 0; j < (int)cache.size(); j++) {
                        int nextUse = -1;
                        for (int k = i + 1; k < numAccesses; k++) {
                            if (accesses.at(k) == cache.at(j)) {
                                nextUse = k;
                                break;
                            }
                        }

                        if (nextUse == -1) {
                            evictIndex = j;
                            break;
                        }

                        if (nextUse > farthest) {
                            farthest = nextUse;
                            evictIndex = j;
                        }
                    }

                    cache.at(evictIndex) = obj;
                }
            }
        }
        cout << reads << endl;
    }

    return 0;
}