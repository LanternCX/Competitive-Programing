#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    string s;
    cin >> s;
    stack<char> st;
    for(auto ch : s){
        if(ch != ')'){
            st.push(ch);
        }else{
            string ans;
            while(st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
            st.pop();
        }
    }
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}
