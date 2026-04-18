/*
 * All 4 methods to find the most frequent duplicate element.
 * Compile:  g++ -std=c++11 -O2 -lm all_methods.cpp -o all_methods
 * Run:      ./all_methods                (reads test cases from stdin)
 *           ./all_methods bench          (runs benchmark on generated data)
 *
 * Tie-breaking rule: if two elements share the highest frequency,
 * return the one that appears FIRST in the original list.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <random>
#include <cassert>
using namespace std;
using ms = chrono::duration<double, milli>;

// ---------------------------------------------------------------------------
// Method 1 — Brute Force
// Time:  O(n²)   Space: O(1)
// For every position i, count how many times nums[i] appears in the whole
// array.  Track the maximum count and the first index where it was seen.
// ---------------------------------------------------------------------------
int method1_brute(const vector<int>& nums) {
    int n = (int)nums.size();
    int maxFreq = 1, result = 0, bestIdx = n;
    for (int i = 0; i < n; i++) {
        // skip if we already processed this value at an earlier index
        bool seen = false;
        for (int j = 0; j < i; j++) if (nums[j] == nums[i]) { seen = true; break; }
        if (seen) continue;

        int freq = 0;
        for (int j = 0; j < n; j++) if (nums[j] == nums[i]) freq++;

        if (freq >= 2 && (freq > maxFreq || (freq == maxFreq && i < bestIdx))) {
            maxFreq = freq;
            result  = nums[i];
            bestIdx = i;
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// Method 2 — Hash Map
// Time:  O(n) average   Space: O(n)
// One pass to count frequencies and record first-seen index, then one pass
// over the map to find the winner.
// ---------------------------------------------------------------------------
int method2_hashmap(const vector<int>& nums) {
    unordered_map<int, int> freq, firstIdx;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
        if (!firstIdx.count(nums[i])) firstIdx[nums[i]] = i;
    }

    int maxFreq = 1, result = 0, bestIdx = n;
    for (auto& [val, cnt] : freq) {
        if (cnt < 2) continue;
        if (cnt > maxFreq || (cnt == maxFreq && firstIdx[val] < bestIdx)) {
            maxFreq = cnt; result = val; bestIdx = firstIdx[val];
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// Method 3 — Sort-based
// Time:  O(n log n)   Space: O(n)
// Pair each value with its original index, sort by value so identical values
// group together, then scan groups to find the max-frequency duplicate.
// ---------------------------------------------------------------------------
int method3_sort(const vector<int>& nums) {
    int n = (int)nums.size();
    vector<pair<int,int>> indexed(n);
    for (int i = 0; i < n; i++) indexed[i] = {nums[i], i};
    sort(indexed.begin(), indexed.end());   // stable by value, then by index

    int maxFreq = 1, result = 0, bestIdx = n;
    int i = 0;
    while (i < n) {
        int j = i;
        int minOrigIdx = n;
        while (j < n && indexed[j].first == indexed[i].first) {
            minOrigIdx = min(minOrigIdx, indexed[j].second);
            j++;
        }
        int freq = j - i;
        if (freq >= 2 && (freq > maxFreq || (freq == maxFreq && minOrigIdx < bestIdx))) {
            maxFreq = freq; result = indexed[i].first; bestIdx = minOrigIdx;
        }
        i = j;
    }
    return result;
}

// ---------------------------------------------------------------------------
// Method 4 — Counting Array (Bucket)
// Time:  O(n)   Space: O(range) = O(2×10^5)
// Values are bounded to (-10^5, 10^5), so we use a direct-address array
// as the frequency table.  Two passes: count, then scan for best.
// ---------------------------------------------------------------------------
static const int OFFSET = 100000;      // shift so negatives become non-negative
static const int RANGE  = 200001;

int method4_bucket(const vector<int>& nums) {
    static int freq[RANGE];
    static int firstIdx[RANGE];
    fill(freq,     freq     + RANGE, 0);
    fill(firstIdx, firstIdx + RANGE, -1);

    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
        int idx = nums[i] + OFFSET;
        freq[idx]++;
        if (firstIdx[idx] == -1) firstIdx[idx] = i;
    }

    int maxFreq = 1, result = 0, bestIdx = n;
    for (int i = 0; i < RANGE; i++) {
        if (freq[i] < 2) continue;
        if (freq[i] > maxFreq || (freq[i] == maxFreq && firstIdx[i] < bestIdx)) {
            maxFreq = freq[i]; result = i - OFFSET; bestIdx = firstIdx[i];
        }
    }
    return result;
}

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------
double timeMethod(int (*fn)(const vector<int>&), const vector<int>& data, int reps = 5) {
    auto t0 = chrono::high_resolution_clock::now();
    volatile int sink = 0;
    for (int r = 0; r < reps; r++) sink = fn(data);
    auto t1 = chrono::high_resolution_clock::now();
    (void)sink;
    return chrono::duration_cast<ms>(t1 - t0).count() / reps;
}

vector<int> generate(int n, int range = 100000, unsigned seed = 42) {
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(-range + 1, range - 1);
    vector<int> v(n);
    for (auto& x : v) x = dist(rng);
    return v;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    // ----- Benchmark mode -----
    if (argc > 1 && string(argv[1]) == "bench") {
        cout << "Benchmark — average over 5 runs each\n";
        cout << string(55, '-') << "\n";
        printf("%-10s  %12s  %12s  %12s  %12s\n",
               "n", "Brute O(n²)", "HashMap O(n)", "Sort O(nlgn)", "Bucket O(n)");
        cout << string(55, '-') << "\n";

        for (int n : {1000, 10000, 50000, 100000}) {
            auto data = generate(n);

            double t1 = (n <= 10000) ? timeMethod(method1_brute,   data) : -1;
            double t2 = timeMethod(method2_hashmap, data);
            double t3 = timeMethod(method3_sort,    data);
            double t4 = timeMethod(method4_bucket,  data);

            printf("%-10d  ", n);
            if (t1 < 0) printf("%12s  ", "skip");
            else        printf("%11.2fms  ", t1);
            printf("%11.2fms  %11.2fms  %11.2fms\n", t2, t3, t4);
        }
        return 0;
    }

    // ----- OJ / stdin mode -----
    // Verify all methods agree on sample cases
    vector<pair<vector<int>,int>> samples = {
        {{-1, 1, -1, 8},           -1},
        {{1, 2, 3, 3, 3, 4, 4, 5}, 3},
        {{2, 3, 1, 5, 4, 3, 2, 1}, 2},
    };
    for (auto& [v, expected] : samples) {
        assert(method1_brute(v)   == expected);
        assert(method2_hashmap(v) == expected);
        assert(method3_sort(v)    == expected);
        assert(method4_bucket(v)  == expected);
    }

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<int> nums;
        istringstream iss(line);
        int x;
        while (iss >> x) nums.push_back(x);
        if (!nums.empty()) cout << method2_hashmap(nums) << "\n";
    }
    return 0;
}
