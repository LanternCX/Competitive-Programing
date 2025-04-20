#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n, a, b;
    cin >> n >> a >> b;
    auto work = [&](int x){
        string s = to_string(x);
        for(int i = 1; i <= s.length(); i++){
            int x = stoi(s.substr(0, i));
            if(x % i != 0){
                return 0;
            }
        }
        return 1;
    };
    int cnt = 0;
    int temp = 0;
    if(b - a > 1e7){
        cout << "No Solution\n";
        return;
    }
    for(int i = a; i <= b; i += n){
        if(work(i)){
            cnt++;
            cout << i << '\n';
        }
    }
    if(cnt <= 0){
        cout << "No Solution\n";
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}
