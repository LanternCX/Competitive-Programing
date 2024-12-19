#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n;
    cin >> n;
    queue<int> q;
    vector<int> tag(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    for(int i = 0; i < n; i++){
        cin >> tag[i];
    }
    stack<int> st;
    st.push(q.front());
    q.pop();
    for(int i = 0; i < n; i++){
        while((st.empty() || st.top() != tag[i]) && !q.empty()){
            st.push(q.front());
            q.pop();
        }
        if(st.empty() || st.top() != tag[i]){
            cout << "No" << '\n';
            return;
        }
        st.pop();
    }
    cout << "Yes" << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        sol();
    }
    return 0;
}
/**
 *  1 2 3 4 5
 *  
 *  1 3 2 4 5
 */