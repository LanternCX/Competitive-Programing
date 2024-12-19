#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    stack<int> st;
    string temp;
    for (char c : s) {
        if(c == '@'){
            break;
        }
        if(c == '.'){
            st.push(stoi(temp));
            temp = "";
        }

        if (isdigit(c)) {
            temp.push_back(c);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = st.top(); 
            st.pop();
            int a = st.top(); 
            st.pop();
            int res;
            switch (c) {
                case '+': 
                    res = a + b; 
                    break;
                case '-': 
                    res = a - b; 
                    break;
                case '*': 
                    res = a * b; 
                    break;
                case '/': 
                    res = a / b; 
                    break;
            }
            st.push(res);
        }
    }
    int ans = st.top();
    cout << ans;
    return 0;
}