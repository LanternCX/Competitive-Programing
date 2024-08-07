#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int test(int i, int j){
    return i + j;
}
int main(){
    int m,n;
    cin >> m >> n;
    int ans[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i = m; i <= n; i++){
        string s = to_string(i);
        for(char c : s){
            ans[c - '0']++;
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}