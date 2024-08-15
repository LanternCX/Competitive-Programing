#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
bool p[N];
void ai(){
    for(int i = 0; i < N; i++){
        p[i] = 1;
    }
    p[0] = p[1] = 0;
    for(int i = 2; i * i < N; i++){
        if(p[i]){
            for(int j = i * i; j < N; j += i){
                p[j] = 0;
            }
        }
    }
}
int main(){
    ai();
    int n;
    cin >> n;
    vector<string> ans;
    for(int i = 4; i <= n; i += 2){
        for(int j = 0; j <= i; j++){
            if(p[j] && p[i - j]){
                string res = to_string(i) + "=" + to_string(j) + "+" + to_string(i - j);
                ans.push_back(res);
                break;
            }
        }
    }

    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}