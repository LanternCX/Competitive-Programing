#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct value{
    int n;
    int idx;
};

struct cmp {
    bool operator()(const value& a, const value& b) {
        return a.n < b.n;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<value> a(n);
    priority_queue<value, vector<value>, cmp> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i].n;
        a[i].idx = i; 
    }
    
    for (int i = 0; i < k; i++) {
        b.push(a[i]);
    }

    cout << b.top().n << endl;
    for (int i = k; i < n; i++) {
        b.push(a[i]);
        while (b.top().idx <= i - k) {
            b.pop();
        }
        cout << b.top().n << endl;
    }

    return 0;
}
