#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        int walls[n];
        for (int i = 0; i < n; i++) {
            cin >> walls[i];
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