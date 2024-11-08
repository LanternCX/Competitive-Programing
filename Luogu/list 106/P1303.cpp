#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> read(){
    string s;
    vector<int> res;

    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++){
        res.push_back(s[len - i - 1] - '0');
    }

    return res;
}

void print(vector<int> a){
    int i = a.size() - 1;
    while(i > 0 && a[i] == 0) i--;

    for(; i >= 0; i--){
        cout << a[i];
    }
}

vector<int> mul(vector<int> a, vector<int> b){
    vector<int> res(a.size() + b.size(), 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            res[i + j] += a[i] * b[j];
            if (res[i + j] >= 10) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> a = read();
    vector<int> b = read();

    vector<int> c = mul(a, b);
    print(c);
    return 0;
}