#include <bits/stdc++.h>
using namespace std;
#define int long long
// struct BIT{
//     int n;
//     vector<int> tr;
//     BIT(int siz){
//         n = siz;
//         tr = vector<int>(n + 1);
//     }
//     int lowbit(int x){
//         return x & -x;
//     }
//     void add(int idx, int x){
//         for(int i = idx; i <= n; i += lowbit(i)){
//             tr[i] += x;
//         }
//     }
//     int query(int idx){
//         int res = 0;
//         for(int i = idx; i >= 1; i -= lowbit(i)){
//             res += tr[i];
//         };
//         return res;
//     }
// };
void sol(){
    int n;
    cin >> n;
    auto work = [&](string s){
        int res = 0;
        res += stoi(s.substr(0, 2)) * 60 * 60;
        res += stoi(s.substr(3, 2)) * 60;
        res += stoi(s.substr(6, 2));
        return res;
    };
    // BIT bit(work("23:59:59"));

    int len = work("23:59:59") + 1;
    vector<int> diff(len);
    for(int i = 0; i < n; i++){
        string l, r;
        cin >> l >> r;
        diff[work(l)]++;
        diff[work(r) + 1]--;
    }
    for(int i = 1; i < len; i++){
        diff[i] += diff[i - 1];
    }
    // for(auto x : diff){
    //     cout << x << ' ';
    // }
    // cout << '\n';
    cout << *max_element(diff.begin(), diff.end());
}
void test(){
    vector<int> diff = {1, 2, 1, 1, 0};
    for(int i = 1; i < diff.size(); i++){
        diff[i] += diff[i - 1];
    }
    for(auto x : diff){
        cout << x << '\n';
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
/**
 * 树状数组的区间修改 + 点查
 * 实际上是前缀和的基础上做一遍差分
 * 
 * 好像不用写树状数组
 * 
 * int x + 1;
 * diff[]
 */
