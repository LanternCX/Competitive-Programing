#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e9 + 7;
void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto val = [&](string s) -> int {
        int res = 0;
        array<int, 2> cnt = {0, 0};
        for(int i = 0; i < n; i++){
            if(s.substr(i, 2) == "01"){
                cnt[0]++;
            }
            if(s.substr(i, 2) == "10"){
                cnt[1]++;
            }
        }
        // cout << s << ' ' << cnt[0] << ' ' << cnt[1] << '\n';
        for(int i = 0; i < n; i++){
            array<int, 2> temp = cnt;
            if(s[i] == '0'){
                if(i > 0){
                    if(s[i - 1] == '0'){
                        temp[0]++;
                    }
                    if(s[i - 1] == '1'){
                        temp[1]--;
                    }
                }
                if(i < n - 1){
                    if(s[i + 1] == '1'){
                        temp[0]--;
                    }
                    if(s[i + 1] == '0'){
                        temp[1]++;
                    }
                }
            }
            if(s[i] == '1'){
                if(i > 0){
                    if(s[i - 1] == '0'){
                        temp[0]--;
                    }
                    if(s[i - 1] == '1'){
                        temp[1]++;
                    }
                }
                if(i < n - 1){
                    if(s[i + 1] == '1'){
                        temp[0]++;
                    }
                    if(s[i + 1] == '0'){
                        temp[1]--;
                    }
                }
            }
            res += temp[0] == temp[1];
        }
        return res;
    };

    ll sum = 0;
    vector<int> idx;
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            s[i] = '0';
            idx.push_back(i);
        }
    }
    
    cout << sum << '\n';
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
 * 从枚举的思路出发
 * 注意到两次枚举的结果是相似的
 * 存在什么关系呢？
 * 
 * 对于
 * val(1000)和val(1001)
 * 
 * 可以对头尾和中间段分类讨论：
 * 对于中间段：
 * 对val的贡献可以统计
 * 对于头尾段同样可以
 * 也就是说下一个状态可以由上一个状态转移过来？
 * 所以可以考虑dp?
 * 先将所有 ？ 置为 0
 * 对于每个 被置为 0 的 s[i]
 * 如何定义状态呢？
 * 定义状态：把第 i 位由 0 置为 1的 val 值
 * 那么
 * dp[i]由什么变量决定呢？
 * 能到达 dp[i] 的所有状态 和 s[i + 1] s[i - 1] 决定
 * 是不是可以用 dp[i] 更新其他的状态？
 * 也不对
 * 
 * 貌似不能达到线性emm
 * 
 * 也就是说
 * dp[i] = sum(dp[i])
 */