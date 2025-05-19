#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
struct Node {
    int x, y;
    double dis, sin_x;
};

void sol(){
    int n;
    while (cin >> n) {
        if (n == 0) {
            return;
        }

        int cnt = 0;
        vector<Node> node(n), ans(n);

        for (auto& [x, y, dis, sin_x] : node) {
            cin >> x >> y;
        }

        if (n == 1) {
            cout << "0.00\n";
            continue;
        }

        sort(node.begin(), node.end(), [](const Node& a, const Node& b) {
            return (a.x == b.x) ? a.y < b.y : a.x < b.x;
        });

        node[0].dis = 0;
        node[0].sin_x = -1;

        auto dis = [&](int n) {
            for (int i = 1; i < n; i++) {
                double dx = node[i].x - node[0].x;
                double dy = node[i].y - node[0].y;
                node[i].dis = sqrt(dx * dx + dy * dy);
                node[i].sin_x = dy / node[i].dis;
            }
        };
        dis(n);

        sort(node.begin(), node.end(), [](const Node& a, const Node& b) {
            return (a.sin_x == b.sin_x) ? a.dis < b.dis : a.sin_x < b.sin_x;
        });

        ans[cnt++] = node[0];
        ans[cnt++] = node[1];

        auto judge = [&](int ni) {
            if (cnt < 2) return true;
            Node& a = ans[cnt - 1];
            Node& b = ans[cnt - 2];
            Node& c = node[ni];
            return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y) > 0;
        };

        for (int i = 2; i < n; i++) {
            while (!judge(i)) cnt--;
            ans[cnt++] = node[i];
        }

        auto lang = [&]() {
            double sum = 0;
            for (int i = 1; i < cnt; i++) {
                double dx = ans[i].x - ans[i - 1].x;
                double dy = ans[i].y - ans[i - 1].y;
                sum += sqrt(dx * dx + dy * dy);
            }
            if (cnt > 2) {
                double dx = ans[0].x - ans[cnt - 1].x;
                double dy = ans[0].y - ans[cnt - 1].y;
                sum += sqrt(dx * dx + dy * dy);
            }
            cout << fixed << setprecision(2) << sum << '\n';
        };

        lang();
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}