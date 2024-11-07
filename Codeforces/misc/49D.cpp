#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && s[i] != '0'){
            cnt1++;
        }
        if(i % 2 == 1 && s[i] != '1'){
            cnt1++;
        }

        if(i % 2 == 1 && s[i] != '0'){
            cnt2++;
        }
        if(i % 2 == 0 && s[i] != '1'){
            cnt2++;
        }
    }

    cout << min(cnt1, cnt2);

    return 0;
}