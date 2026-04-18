#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // 2 integers
    int a, b;
    cin>>a>>b;
    vector<vector<int>> arr;
    
    // input and store the arrays
    for (int i=0; i<a; i++) {
        int x;
        cin>>x;
        arr.resize(i+1);
        arr[i].resize(x);
        for (int j=0;j<x;j++) {
            cin>>arr[i][j]; 
        }

    }

    for (int k=0; k<b; k++) {
        int m,n;
        cin>>m>>n;
        cout<<arr[m][n]<<endl;
    }



    return 0;
}
