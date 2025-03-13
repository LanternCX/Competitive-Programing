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
struct node{
    string id, name;
    double price;
};
void sol(){
    vector<node> arr;
    map<string, int> cnt;
    int idx = 0;
    while (1) {
        string id, name;
        double price;
        cin >> id >> name >> price;
        if(id == "0"){
            break;
        }
        if(cnt[id]){
            continue;
        }
        arr.push_back({id, name, price});
        cnt[id]++;
    }
    cout << arr.size() << '\n';
    for(auto [id, name, price] : arr){
        cout << id << ' ' << name << ' ';
        printf("%.2lf\n", price);
    }
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}