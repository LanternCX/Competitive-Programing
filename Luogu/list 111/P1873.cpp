#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    ll temp = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        temp += arr[i];
    }
    ll begin = 0;
    ll end = temp;
    ll mid;
    while(begin < end){
        ll sum = 0;
        mid = begin + (end - begin) / 2 + 1;
        // cout << begin << ' ' << end << ' ' << mid << ' ';
        for(int i = 0; i < n; i++){
            sum += arr[i] >= mid ? arr[i] - mid : 0;
        }
        // cout << sum << '\n';
        if(sum < m){
            end = mid - 1;
        }else{
            begin = mid;
        }
    }
    cout << begin;
    return 0;
}