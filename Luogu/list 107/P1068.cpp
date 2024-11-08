#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct person{
    int id;
    int sc;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<person> a(n);
    for(int i = 0; i < n; i++){
        person p;
        cin >> a[i].id >> a[i].sc;

    }
    sort(a.begin(), a.end(), [](person a, person b) -> int {
        bool res = a.sc > b.sc;
        if(a.sc == b.sc){
            res = a.id < b.id;
        }
        return res;
    });
    vector<person> ans;
    int rank = m * 1.5;
    for(int i = 0; i < n; i++){
         if(a[i].sc >= a[rank - 1].sc){
            ans.push_back(a[i]);
         }
    }
    cout << a[rank - 1].sc << ' ' << ans.size() << '\n';
    for(auto p : ans){
        cout << p.id << ' ' << p.sc << '\n';
    }
    return 0;
}