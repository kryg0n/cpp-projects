#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        vector<int> walls;
        for (int i = 0; i < n; i++) {
            int hgt;
            cin >> hgt;
            walls.push_back(hgt);
        }
        int h = 0, l = 0;
        for (int i = 0; i < n - 1; i++) {
            if (walls[i + 1] > walls[i]) {
                h++;
            } else if (walls[i + 1] < walls[i]) {
                l++;
            }
        }
        cout << "Case " << c << ": " << h << " " << l << endl;
    }
    return 0;
}