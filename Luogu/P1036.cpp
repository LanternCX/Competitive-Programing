#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7;
int k, n;
ll ans;
int arr[100];
struct node{
    int idx, val;
};

bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = true;
    }
    p[0] = p[1] = false;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = false;
            }
        }
    }
}

void dfs(int sum, int cnt, int idx){
    if(cnt == k){
        if(p[sum]){
            // cout << sum << '\n';
            ans++;
        }
        return;
    }
    for(int i = idx; i < n; i++){
        dfs(sum + arr[i], cnt + 1, i + 1);
    }
    return;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ai();
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0, 0 , 0);
    cout << ans;
    return 0;
}