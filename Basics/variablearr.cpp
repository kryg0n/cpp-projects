#include <iostream>
using namespace std;

int main() {

    // 2 integers
    int a, b;
    scanf("%d %d", &a, &b);
    
    // input and store the arrays
    for (int i=0; i<a; i++) {
        int x;
        scanf("%d", &x);
        int arr[i][x];

        for (int j=0;j<x;j++) {
            scanf("%d", arr[i][j]); 
        }

    }

    for (int k=0; k<b; k++) {
        int m,n;
        scanf("%d %d", &m,&n);
        printf("%d", arr[m][n]);
    }



    return 0;
}
