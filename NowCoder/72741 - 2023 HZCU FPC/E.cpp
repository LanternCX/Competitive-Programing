#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> zip;
    map<int, int> mp;
    stack<int> st;
    queue<int> que;
    cin >> a[0];
    zip.push_back(a[0]);
    mp[a[0]]++;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] != a[i - 1]){
            zip.push_back(a[i]);
            mp[a[i]]++;
        }
    }
    for(int x : zip){
        que.push(x);
        if(mp[x] == 1){
            que.push(x);
        }
    }
    while (que.size() != 0) {
        int now = que.front();
        que.pop();
        if(st.empty()){
            st.push(now);
        }else {
            if(st.top() == now){
                st.pop();
            }else {
                st.push(now);
            }
        }
    }
    if(!st.empty()){
        cout << "NO\n";
    }else {
        cout << "YES\n";
        map<int, int> temp;
        for(int x : zip){
            if(temp[x] == 0){
                cout << x << ' ';
            }
            temp[x]++;
        }
        cout << '\n';
    }
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
 * 1 1 1 2 2 2 1 3 3 3 1 1
 * 1 2 3 3 2 1
 * 
 * 
 * 1 3 2 2 1
 * 1 2 1 3 1
 * 
 */