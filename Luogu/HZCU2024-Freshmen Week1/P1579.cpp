#include <bits/stdc++.h>
using namespace std;
const int N = 20005;

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
int main(){
    vector<int> ans(3);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ai();
    int n;
    cin >> n;
    int isDone = 0;
    for(int i = 2; i <= n; i++){
        if(isDone){
            break;
        }
        if(p[i]){
            for(int j = 2; j <= n - i; j++){
                if(p[j] && p[n - i - j]) {
                    ans[0] = j;  
                    ans[1] = n - i - j;
                    ans[2] = i;
                    isDone = 1;
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}