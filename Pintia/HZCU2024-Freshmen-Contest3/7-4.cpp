#include <bits/stdc++.h>

using namespace std;

void sol(){
    string s;
    cin >> s;
    int ans = 1;
    stack<char> st;
    for(char ch : s){
        if(ch == '{' || ch == '[' || ch == '('){
            st.push(ch);
        }else{
            if(st.empty()){
                ans = 0;
                break;
            }
            if(st.top() == '{' && ch != '}' || st.top() == '(' && ch != ')' || st.top() == '[' && ch != ']'){
                ans = 0;
                break;
            }
            st.pop();
        }
    }
    if(!st.empty()){
        ans = 0;
    }
    if(ans == 1){
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        sol();
    }
    return 0;
}
/**
 * {()[]}
 * 
 * {{{{{{}}}}}}
 * 
 * {{}{}{}{{}}}{}{}
 */