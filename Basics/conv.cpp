#include <iostream>
#include <cmath>
using namespace std;
int tenr(int i, int j) {return i*pow(10,j);}

int main () {
    

    cout<< tenr(4,2)<<endl;
    cout<<4/tenr(1,2)<<endl;

    return 0;
}