#include <bits/stdc++.h>
using namespace std;
const int N = 100000;

bool p[N + 1];
void ai() {
    for (int i = 0; i <= N; i++) {
        p[i] = true;
    }
    p[0] = p[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (p[i]) {
            for (int j = i * i; j <= N; j += i) {
                p[j] = false;
            }
        }
    }
}

int steps(string a, string b) {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        int m = a[i] - '0';
        int n = b[i] - '0';
        int up = (n - m + 10) % 10;
        int down = (m - n + 10) % 10;
        res += min(up, down);
    }
    return res;
}

string add0(int n) {
    string s = to_string(n);
    while (s.length() < 5) {
        s.insert(0, "0");
    }
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    ai();
    vector<int> prime;
    for (int i = 10000; i <= N; i++) {
        if (p[i]) {
            prime.push_back(i);
        }
    }
    
    int min = INT_MAX;
    string ans;
    for (int i : prime) {
        string str = add0(i);
        int n = steps(s, str);
        if (n < min || (n == min && str > ans)) {
            min = n;
            ans = str;
        }
    }
    cout << ans << endl;
    return 0;
}
