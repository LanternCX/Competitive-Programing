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
const ll inf = INT_MAX;
void sol(){
    int n;
	cin >> n;
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> len;
    for(auto [x, v] : cnt){
        len.push_back(v);
    }

    int siz = len.size();
    vector<ll> dp(siz + 1, inf);
    dp[0] = 0;
    for(int i = 1; i <= siz; i++){
        vector<ll> temp = dp;
        for(int k = 1; k <= siz; k++){
            if(dp[k - 1] + len[i - 1] <= i - k){
                temp[k] = min(temp[k], dp[k - 1] + len[i - 1]);
            }
        }
        dp = temp;
    }
    
    int ans = siz;
    for(int i = siz; i >= 0; i--){
        if(dp[i] < inf){
            ans = i;
            break;
        }
    }
    cout << siz - ans << '\n';
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
 * 
排序一下
分成若干个相等的块
 
首先 A 肯定是从小的开始吃，吃完一个块之后就不能再吃 

B 要阻止 A
所以 B 要在 A 到达 某个块之前吃掉这个快后面的所有块

对于一个块 长度为 len 
A要在这个块产生贡献需要 1 回合
B要阻止A在这个块产生贡献需要 len 回合 

B 可以选择较短的块先吃这样 A 就无法在这个块产生贡献

dp?

01 背包

第 i 个块，B 只能从中吃掉 i 个蛋糕，最优选择就是从短的开始吃
那么 能产生贡献的块就是 i - 吃掉的数量
找到这些贡献中最小的

有 n 个物品
在 第 i 个物品可以拿走前 i 个物品中总价值为 i 的物品
求 可以拿走的最大物品数量 

设：dp[k] 表示能让 A 吃到恰好 k 块的 B 花费的最小代价
转移：那么 B 就要
dp[k] = min(dp[k], dp[k - 1] + len[i - 1]) 
*/ 