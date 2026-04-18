#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// check if a number is a prime number
bool isprime(int num) {
    if (num < 2) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// make a list of all four digit prime numbers
vector<int> makeprimelist() {
    vector<int> primelist;
    for (int i = 1000; i <= 9999; ++i) {
        if (isprime(i)) {
            primelist.push_back(i);
        }
    }
    return primelist;
}

// check if two numbers are different in exactly one digit
bool differbyone(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int countdiff = 0;
    for (int i = 0; i < 4; ++i) {
        if (sa[i] != sb[i]) {
            countdiff++;
        }
        if (countdiff > 1) return false;
    }
    return countdiff == 1;
}

int main() {
    // make the list of all four digit primes once
    vector<int> primelist = makeprimelist();
    int totalsize = primelist.size();

    // make connection list for each prime
    vector<vector<int>> connections(totalsize);

    // connect primes that differ by exactly one digit
    for (int i = 0; i < totalsize; ++i) {
        for (int j = i + 1; j < totalsize; ++j) {
            if (differbyone(primelist[i], primelist[j])) {
                connections[i].push_back(j);
                connections[j].push_back(i);
            }
        }
    }

    int testcases;
    cin >> testcases;

    for (int t = 0; t < testcases; ++t) {
        int startnum, goalnum;
        cin >> startnum >> goalnum;

        // if both numbers are same then cost is zero
        if (startnum == goalnum) {
            cout << 0 << endl;
            continue;
        }

        // find position of start and goal in the prime list
        int startpos = -1;
        int goalpos = -1;
        for (int i = 0; i < totalsize; ++i) {
            if (primelist[i] == startnum) startpos = i;
            if (primelist[i] == goalnum) goalpos = i;
        }

        // if any number is not prime then impossible
        if (startpos == -1 || goalpos == -1) {
            cout << "Impossible" << endl;
            continue;
        }

        // use bfs to find shortest path
        vector<int> steps(totalsize, -1);
        queue<int> q;

        q.push(startpos);
        steps[startpos] = 0;

        bool found = false;

        while (!q.empty() && !found) {
            int current = q.front();
            q.pop();

            for (int nextprime : connections[current]) {
                if (steps[nextprime] == -1) {
                    steps[nextprime] = steps[current] + 1;
                    q.push(nextprime);

                    if (nextprime == goalpos) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) {
            cout << steps[goalpos] << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}