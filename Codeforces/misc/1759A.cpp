#include <bits/stdc++.h>
using namespace std;
void slove(){
    string s;
    cin >> s;
    string tag;
    int l = s.length();
    while (tag.length() <= l + 6) {
        tag += "Yes";
    }

    if(tag.find(s) == string::npos){
        cout << "NO" << '\n';
    }else {
        cout << "YES" << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        slove();
    }
    return 0;
}