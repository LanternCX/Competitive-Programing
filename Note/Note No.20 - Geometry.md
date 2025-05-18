# ACM Note No.20: Geometry



### 多边形面积

连接原点与两个相邻的点，则封闭图形的面积就是`所有的这样的三角形的叉乘和 * (1 / 2)`

[P1183 多边形的面积 - 洛谷](https://www.luogu.com.cn/problem/P1183)

```c++
struct node {
    double x, y;
};
int main(){
    int n;
    cin >> n;
    vector<node> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    auto work = [&](node a, node b) {
        return a.x * b.y - a.y * b.x;
    };

    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += work(a[i], a[i + 1]);
    }
    cout << abs(ans)  / 2 << '\n';
    return 0;
}
```

### 多边形重心

**x 坐标**: `sum(x1 * x2 * 叉乘) / 6S`

**y 坐标**: `sum(y1 * y2 * 叉乘) / 6S`

```c++
int N;
cin >> N;
vector<node> p(N);

for (int i = 0; i < N; ++i) {
cin >> p[i].x >> p[i].y;
}

double s = 0.0;
double x = 0.0, y = 0.0;

for (int i = 0; i < N; ++i) {
    int j = (i + 1) % N;
    double temp = p[i].x * p[j].y - p[j].x * p[i].y;
    s += temp;
    x += (p[i].x + p[j].x) * temp;
    y += (p[i].y + p[j].y) * temp;
}

s *= 0.5;
x /= (6 * s);
y /= (6 * s);

cout << x << " " << y << '\n';
```

### 二维凸包

```c++
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
```

