#include <bits/stdc++.h>
using namespace std;
struct person{
    int id;
    string s;
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<person> arr(n);
    for(int i = 0; i < n; i++){
        person p = {i + 1};
        cin >> p.s;
        arr[i] = p;
    }
    sort(arr.begin(), arr.end(), [](person a, person b) -> int {
        int res = a.s.length() < b.s.length();
        if(a.s.length() == b.s.length()){
            res = a.s < b.s;
        }
        return res;
    });
    cout << arr[n - 1].id << '\n' << arr[n - 1].s;
    return 0;
}