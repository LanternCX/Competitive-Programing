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
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
        x--;
    }
    vector<int> idx = {-1};

    int l = 0, r = n - 1;

    vector<int> tag = {0, 0};
    
    for(l = 0; l < n; l++){
        if(a[l] != l){
            tag[0] = 1;
            break;
        }
    }

    for(r = n - 1; r >= 0; r--){
        if(a[r] != r){
            tag[1] = 1;
            break;
        }
    }

    if(!tag[0] && !tag[1]){
        cout << 0 << '\n';
        return;
    }

    l--, r++;

    debug(l, r, n - 1);

    for(int i = l + 1; i < r; i++){
        if(a[i] == i){
            cout << 2 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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
/**
 * 位置正确的点就不能执行特殊交换
 * 所以这些点把数列划分为若干段
 * 
 * 如果这个数目标位置在段内 对答案贡献为 1
 * 如果这个数目标位置在段外 对答案贡献为 2
 * 不对
 * 
 * 贡献好像不是独立的
 * 
 * 事实上答案只有 0 1 2 三种情况
 * 
 * 对于之后末尾段或者开头段都合法的情况答案 1
 * 对于中间段由合法位置的情况 答案 2
 * 对于不需要操作的情况 答案 0
 */