#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int len;
            cin >> len;
            vector<int> b(len);
            for(auto &x : b){
                cin >> x;
            }
            int idx = 0;
            int l = 0, r = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] == b[idx]){
                    idx++;
                }else{
                    l = i + 1;
                    idx = 0;
                }
                if(idx == len){
                    r = i;
                    break;
                }
            }
            int len2;
            cin >> len2;
            vector<int> c(len2);
            for(auto &x : c){
                cin >> x;
            }
            // cerr << l << ' ' << r << '\n';
            if(r - l + 1 == len){
                a.erase(a.begin() + l, a.begin() + r + 1);
                // reverse(c.begin(), c.end());
                vector<int> temp;
                for(int i = 0; i < l; i++){
                    temp.push_back(a[i]);
                }
                for(auto x : c){
                    temp.push_back(x);
                }
                for(int i = l; i < a.size(); i++){
                    temp.push_back(a[i]);
                }
                a = temp;
            }
        }
        if(op == 2){
            vector<int> temp;
            for(int i = 0; i < a.size() - 1; i++){
                temp.push_back(a[i]);
                if((a[i] + a[i + 1]) % 2 == 0){
                    temp.push_back((a[i] + a[i + 1]) / 2);
                }
            }
            temp.push_back(a[a.size() - 1]);
            a = temp;
        }
        if(op == 3){
            int l, r;
            cin >> l >> r;
            l--, r--;
            reverse(a.begin() + l, a.begin() + r + 1);
        }
    }

    for(int i = 0; i < a.size(); i++){
        cout << a[i];
        if(i != a.size() - 1){
            cout << ' ';
        }
    };
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){     
        sol();
    }
}
