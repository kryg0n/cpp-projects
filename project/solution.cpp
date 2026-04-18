// OJ Submission — Method 2: Hash Map  O(n) time, O(n) space
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve(const vector<int>& nums) {
    unordered_map<int, int> freq;
    unordered_map<int, int> firstIdx;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
        if (!firstIdx.count(nums[i])) firstIdx[nums[i]] = i;
    }

    int maxFreq = 1, result = 0, bestIdx = n;
    for (auto& [val, cnt] : freq) {
        if (cnt < 2) continue;                            // must be duplicate
        if (cnt > maxFreq || (cnt == maxFreq && firstIdx[val] < bestIdx)) {
            maxFreq = cnt;
            result  = val;
            bestIdx = firstIdx[val];
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<int> nums;
        istringstream iss(line);
        int x;
        while (iss >> x) nums.push_back(x);
        if (!nums.empty()) cout << solve(nums) << "\n";
    }
    return 0;
}
