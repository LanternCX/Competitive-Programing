#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int y;
    int m; 
    int d;
    int id;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<person> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), [](person a, person b) -> int {
        bool res = a.y < b.y;
        if(a.y == b.y){
            res = a.m < b.m;
            if (a.m == b.m) {
                res = a.d < b.d;
                if(a.d == b.d){
                    res = a.id > b.id;
                }
            }
        }
        return res;
    });
    for(auto p : a){
        cout << p.name << '\n';
    }
    return 0;
}