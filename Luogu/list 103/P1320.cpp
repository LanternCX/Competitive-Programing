#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();

    for(int i = 0; i < n - 1; i++){
        string s1;
        cin >> s1;
        s += s1;
    }

    int an[202] = {0};
    int tag = 0;
    char now = '0';
    for(char c : s){
        if(c == now){
            an[tag]++;
        }else {
            tag++;
            an[tag] = 1;
            now = c;
        }
    }
    cout << n << ' ';
    for(int i = 0; i <= tag; i++){
        cout << an[i] << ' ';
    }
    return 0;
}