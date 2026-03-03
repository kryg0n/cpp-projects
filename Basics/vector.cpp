#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> arr = {{1,2,3},{4,5,6}};
    arr.resize(3);
    cout<<arr[1][1];


    return 0;
}