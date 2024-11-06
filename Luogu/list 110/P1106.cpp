#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(s[i + 1] - '0' == 0){
            s.erase(0, i + 1);
            n -= i + 1;
            i = 0;
        }
        while(s[0] == '0'){
            s.erase(0, 1);
        }
    }
    if(s == ""){
        cout << 0;
        return 0;
    }
    vector<int> arr;
    string temp = s;
    int idx = -1;
    for(int i = s.length() - n; i > 0; i--){
        int min = 10;
        for(int j = idx + 1; j <= s.length() - i; j++){
            int a = s[j] - '0';
            if(min > a){
                min = a;
                idx = j;
            }
        }
        arr.push_back(idx);
    }
    string ans;
    for(int i : arr){
        ans.push_back(temp[i]);
    }
    cout << ans;
    return 0;
}