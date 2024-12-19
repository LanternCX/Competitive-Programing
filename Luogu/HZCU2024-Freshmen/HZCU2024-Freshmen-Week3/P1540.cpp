#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> m >> n;
    deque<int> a;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int tag = 0;
        for(int i : a){
            if(i == x){
                tag = 1;
            }
        }
        if(tag == 0){
            ans++;
            if(a.size() >= m){
                a.pop_front();
                a.push_back(x);
            }else {
                a.push_back(x);
            }
        }
    }
    cout << ans;
    return 0;
}