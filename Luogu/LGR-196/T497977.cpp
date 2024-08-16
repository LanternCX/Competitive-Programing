#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int pow10(int n){
    int res = 1;
    for(int i = 0; i < n; i++){
        res *= 10;
    }
    return res;
}
int main(){
    int n, t;
    cin >> n >> t;
    int t1 = pow(10, t);
    set<int> sn;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sn.insert(x % t1);
    }
    cout << sn.size();
    return 0;
}