#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
void sol(){
    int n;
    cin >> n;
    stack<ll> st;
    while(n--){
        string op;
        cin >> op;
        if(op == "push"){
            ll x;
            cin >> x;
            st.push(x);
        }
        if(op == "query"){
            if(st.empty()){
                cout << "Anguei!\n";
                continue;
            }
            cout << st.top() << '\n';
        }
        if(op == "size"){
            cout << st.size() << '\n';
        }

        if(op == "pop"){
            if(st.empty()){
                cout << "Empty\n";
                continue;
            }
            st.pop();
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        sol();
    }
    return 0;
}