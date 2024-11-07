#include <bits/stdc++.h>
#include <functional>
#include <stack>
using namespace std;
void sol(){
    int n, m, k;
    cin >> n >> m >> k;
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end(), greater<char>());
    sort(s2.begin(), s2.end(), greater<char>());
    stack<char> st1;
    stack<char> st2;
    int op1 = 0, op2 = 0;
    for(char ch : s1){
        st1.push(ch);
    }
    for(char ch : s2){
        st2.push(ch);
    }
    string ans;
    while (!(st1.empty() || st2.empty())) {
        if(st1.top() > st2.top()){
            if(op2 < k){
                ans.push_back(st2.top());
                st2.pop();
                op2++;
                op1 = 0;
            }else {
                ans.push_back(st1.top());
                st1.pop();
                op1++;
                op2 = 0;
            }
        }else {
            if(op1 < k){
                ans.push_back(st1.top());
                st1.pop();
                op1++;
                op2 = 0;
            }else {
                ans.push_back(st2.top());
                st2.pop();
                op2++;
                op1 = 0;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}