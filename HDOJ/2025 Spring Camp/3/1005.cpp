 #include <bits/stdc++.h>
 using namespace std;
 #ifndef ONLINE_JUDGE
 #include "include/debug.cpp"
 #else
 #define debug(...) (void)(0)
 #endif
 using ll = long long;
 using ull = unsigned long long;
 using pii = pair<int, int>;
 struct DSU {
    vector<int> fa;
    int n;
    DSU(int size): n(size), fa(size) {
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };
 
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
 
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }
 
    bool query(int x, int y){
        return find(x) == find(y);
    }
 
    int root(void){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == i){
                res++;
            }
        }
        return res;
    }
 };
 void sol(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    DSU dsu(n);
    for(int i = 0; i < n; i++){
        if(arr[i] + i < n){
            dsu.merge(arr[i] + i, i);
        }
        if(i - arr[i] >= 0){
            dsu.merge(i - arr[i], i);
        }
    }
    cout << dsu.root() - 1 << '\n';
 }
 int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
 }