#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;
    int num0 = 0, num1 = 0;
    for(char ch : s){
        if(ch == '1'){
            num1++;
        }else {
            num0++;
        }
    }
    int ans = 1;
    for(char ch : r){
        if(num0 == 0 && num1 != 1 || num1 == 0 && num0 != 1){
            ans = 0;
            break;
        }
        if(ch == '1'){
            num0--;
        }else {
            num1--;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * 010010
 * 0 : 4 1 : 2
 * 11010
 * 
 */