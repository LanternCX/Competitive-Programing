#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0;
    while (1) {
        vector<int> pos;
        for(int i = 0; i < s.length(); i++){
            string p = s.substr(i, 3);
            if(p == "not"){
                pos.push_back(i);
            }
        }
        if(pos.empty()){
            break;
        }
        for(int i = 0; i < pos.size(); i++){
            s.erase(pos[i] - i * 3, 3);
        }
        t++;
    }
    cout << s << '\n' << t;
    return 0;
}