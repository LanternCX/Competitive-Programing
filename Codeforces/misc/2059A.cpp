#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    set<int> s1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s1.insert(x);
    }

    set<int> s2;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s2.insert(x);
    }

    int ans = 0;
    if(s1.size() + s2.size() > 3){
        ans = 1;
    }
    cout << (ans ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}
/**
 * 1 2 3
 * 1
 */