#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cmp(string& bin1, string& bin2) {
    if (bin1.size() < bin2.size()) {
        return -1;
    } else if (bin1.size() > bin2.size()) {
        return 1;
    }

    for (int i = 0; i < bin1.size(); ++i) {
        if (bin1[i] < bin2[i]) {
            return -1;
        } else if (bin1[i] > bin2[i]) {
            return 1;
        }
    }
    return 0;
}
void sol(){
    string s;
    cin >> s;
    cout << 1 << ' ' << s.length() << ' ';
    ll idx = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    ll len = s.length() - idx;
    string tag = s.substr(idx, len);
    ll tagnum = 0;
    for(char ch : tag){
        tagnum += ch - '0';
        tagnum *= 2;
    }
    string maxsum = "0";
    ll ansl = 0;
    for(ll begin = 0; begin < (s.length() - len); begin++){
        if(s[begin] == '0'){
            continue;
        }
        string sum;
        for(int i = begin; i < begin + len; i++){
            int ch1 = s[i] - '0';
            int ch2 = tag[i - begin] - '0';
            sum.push_back((ch1 ^ ch2) + '0');
        }
        if(cmp(sum, maxsum) > 0){
            ansl = begin;
            maxsum = sum;
        }
    }
    cout << ansl + 1 << ' ' << ansl + len << '\n';
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
/**
 * 1000
 * 3 3 1 3
 * 1000
 * 
 * 10111
 * 1 5 1 4
 * 10111
 *  1011
 * 
 * 11101
 * 3 4 1 5
 * 111111011111
 *       101111
 * 
 * 1100010001101
 * 1 13
 * 1 11
 * 1100010001101
 *   11000100011
 *   10001000110
 * 11101
 * 1 2
 * 11 34
 * 
 * 1 0 1
 * 0 1 1
 * 1 1 0
 */