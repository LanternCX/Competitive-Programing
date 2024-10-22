#include <bits/stdc++.h>
using namespace std;
void slove(){
    vector<int> temp(26, -1);
    int n;
    cin >> n;    
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        int idx = temp[s[i] - 'a'];
        if((i - idx) % 2 == 1 && idx != -1){
            cout << "No" << '\n';
            return;
        }else {
            temp[s[i] - 'a'] = i;
        }
    }
    cout << "YES" << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}