#include <iostream>
#include <vector>
using namespace std;
/*
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        vector<int> sorted_d = d;
        sort(sorted_d.begin(), sorted_d.end());

        vector<int> distinct;
        for (int i = 0; i < (int)sorted_d.size(); i++)
        {
            if (distinct.empty() || distinct.back() != sorted_d[i])
            {
                distinct.push_back(sorted_d[i]);
            }
        }

        int m = (int)distinct.size();

        int result = 0;

        for (int j = 0; j < m; j++)
        {
            int left_count = (int)j;
            int right_count = (int)(m - 1 - j);
            result += left_count * right_count;
        }

        cout << result << endl;
    }

    return 0;
*/


/**
 * @brief Counts the number of valid triplets (a, b, c) from distinct sorted values
 *        where a < b < c.
 *
 * For each test case:
 * 1. Reads n integers into a vector
 * 2. Sorts the vector using selection sort (O(n^2))
 * 3. Extracts distinct values into a separate vector
 * 4. For each distinct value at index j (acting as middle element b),
 *    counts all possible combinations of left elements (a < b) and
 *    right elements (c > b), multiplying their counts together
 * 5. Sums all products to get the total number of valid triplets
 *
 * @note We use `long long` instead of `int` for `result`, `left_count`, and
 *       `right_count` to prevent integer overflow. Since the number of distinct
 *       values m can be large, the product of left_count * right_count can
 *       exceed the maximum value of a 32-bit integer (2^31 - 1 ≈ 2.1 billion),
 *       causing incorrect results if `int` is used.
 *
 * @input Multiple test cases until EOF:
 *        - First line: integer n (size of array)
 *        - Second line: n space-separated integers
 *
 * @output For each test case, prints the count of valid triplets on a new line
 *
 * @example
 *      Input:  5
 *              1 2 3 4 5
 *      Output: 6
 */
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }

        // 1. Sort O(N log N)
        sort(d.begin(), d.end());

        // 2. Remove duplicates to get distinct values
        d.erase(unique(d.begin(), d.end()), d.end());

        // 3. Calculate combinations
        // We need to choose 3 distinct numbers from size m: mC3
        // Formula: m * (m-1) * (m-2) / 6
        long long m = d.size();
        long long result = 0;
        if (m >= 3) {
            result = m * (m - 1) * (m - 2) / 6;
        }

        cout << result << endl;
    }

    return 0;
}
