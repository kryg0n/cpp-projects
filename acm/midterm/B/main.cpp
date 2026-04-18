
/*
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> circle;
    for(int i = 1; i <= n; i++) {circle.push_back(i);}
    int idx = 0;
    bool first = true;
    while(!circle.empty()){
        idx = (idx + m - 1) % circle.size();
        if(!first) cout << " ";
        cout << circle[idx];
        first = false;
        circle.erase(circle.begin() + idx);
        if(idx == (int)circle.size()) idx = 0;
    }
    cout << endl;
}
    */
/*
int main(){
     int n, m;
     cin >> n >> m;
     vector<int> circle, result;
     for(int i = 1; i <= n; i++) circle.push_back(i);
     int idx = 0;
     while(!circle.empty()){
         idx = (idx + m - 1) % circle.size();
         result.push_back(circle[idx]);
         circle.erase(circle.begin() + idx);
         if(idx == (int)circle.size()) idx = 0;
     }
     for(int i = 0; i < (int)result.size(); i++){
         if(i) cout << " ";
         cout << result[i];
     }
     cout << endl;
 }

*/
#include <iostream>
#include <vector>   
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> circle;
    vector<int> result;
    for(int i = 1; i <= n; i++){
        circle.push_back(i);
    }
    
    int idx = 0;   
    while(!circle.empty()){
        idx = (idx + m - 1) % circle.size();
        result.push_back(circle[idx]);
        circle.erase(circle.begin() + idx);
        
        if(idx == circle.size()){
            idx = 0;
        } else {
            idx = idx;
        }
    }
    
    for(int i = 0; i < result.size(); i++){
        if (i==result.size()-1) {
            cout << result[i];
        } else {cout << result[i] << " ";}
    }
    cout << endl;
    return 0;
}
