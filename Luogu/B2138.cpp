#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
bool p[N + 5];
vector<int> ai(){
    vector<int> pn;
    for(int i = 0; i <= N; i++){
        p[i] = 1;
    }

    p[0] = p[1] = 0;
    for(int i = 2; i * i <= N; i++){
        if(p[i]){
            for(int j = i * i; j <= N; j += i){
                p[j] = 0;
            }
        }
    }
    for(int i = 0; i <= N; i++){
        if(p[i]){
            pn.push_back(i);
        }
    }
    return pn;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> pn = ai();
    int a, b;
    vector<int> ans;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        int temp = 1;
        for(int j = pn.size() - 1; j >= 0; j--){
            if (pn[j] > i) continue;
            if (i % pn[j] == 0) {
                temp = pn[j];
                break;
            }
        }
        ans.push_back(temp);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << (i == ans.size() - 1 ? ' ' : ',');
    }
    return 0;
}