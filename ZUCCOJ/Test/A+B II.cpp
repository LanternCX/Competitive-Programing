#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

string add(string a, string b) {
    string res = "";
    
    int add = 0;

    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || add) {
        int sum = add;
        
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        res.insert(res.begin(), (sum % 10) + '0');
        add = sum / 10;
    }
    return res;
}

int main() {
    string a, b;
    vector<string> ans;
    while (cin >> a >> b) {
        if (a == "0" && b == "0"){
            ans.push_back("0");
            continue;
        }
        ans.push_back(add(a, b));
    }
    for(string s : ans){
        cout << s << '\n';
    }
    return 0;
}
