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
    ll n,x;
	cin >> n >> x;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum |= i;
    }

	int tag = 1;
	for(int i = 0; i < n; i++){
        if(i == n - 1){
            if(sum == x){
                cout << n - 1 << ' ';
            }else{
                cout << x << ' ';
            }
            break;
        }

        if(tag){
            if((i & x) == i){
                cout << i << ' ';
			}else{
                tag = 0;
			}
		}
        if(!tag){
            cout << x << ' ';
		}
	}
	cout << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        debug(9 - t);
        sol();
    }
    return 0;
}
/**
 * 什么时候有 x 什么时候没有？
 * 
 * 首先我找到第一个 0 出现的位置
 * 
 * 从 0 开始遍历到这个位置代表的二进制数 mex - 1
 * 这是一部分
 * 
 * x 是另一部分
 * 
 * 如果长度允许
 * 如果 mex 这位之后还有 1 那么一定要有 x
 * 如果没有 那就直接 0 -> mex
 * 
 * 
 * 如果长度不允许
 * 一定要有 x 的最高位
 * 然后 0 -> mex
 */