#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pii = pair<int, int>;

struct node {

    int a, b;
    string id;
    int age;
    auto operator > (node x) const  {
        return b > x.b;
    };
};

void sol() {
    int n;
    cin >> n;
    vector<node> arr;
    for (int i = 0; i < n; i++) {
        int a, b, age;
        string id;
        cin >> a >> b >> id >> age;
        arr.push_back({a, b, id, age});
    }
    priority_queue<node, vector<node>, greater<node>> pq;

    vector<node> q;

    int t = 0;
    while (!arr.empty()) {
        t++;
        vector<node> pending;
        for (auto nd : arr) {
            if (nd.a <= t - 1) {
                pending.push_back(nd);
            }
        }

        sort(pending.begin(), pending.end(), [](node a, node b) {
            return a.b < b.b;
        });

        if (pending.empty()) {
            continue;
        }

        int tag = 0;
        node next;
        for (auto nd : pending) {
            if (nd.age >= 80 && pending[0].b > t) {
                next = nd;
                tag = 1;
                break;
            }
        }

        if (!tag) {
            next = pending[0];
        }

        vector<node> temp;
        for (auto nd : arr) {
            if (nd.id == next.id) {
                continue;
            }
            temp.push_back(nd);
        }
        arr = temp;

        cout << t << ' ' << next.id << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}