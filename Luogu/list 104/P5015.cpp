#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
    string n;
    getline(cin, n);
    int ans = 0;
    for(char c : n){
        if(c == ' '){
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}