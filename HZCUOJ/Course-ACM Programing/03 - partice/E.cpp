#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// 叉积 （用 long long 防止溢出）
long long cross(const Point& O, const Point& A, const Point& B) {
    return 1LL*(A.x - O.x)*(B.y - O.y)
         - 1LL*(A.y - O.y)*(B.x - O.x);
}

// 两点间欧氏距离
double dist(const Point& A, const Point& B) {
    return hypot(double(A.x - B.x), double(A.y - B.y));
}

// Andrew’s Monotone Chain 求凸包
vector<Point> convexHull(vector<Point>& P) {
    int n = P.size(), k = 0;
    if (n <= 1) return P;

    sort(P.begin(), P.end());
    vector<Point> H(2*n);

    // 下半包
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    // 上半包
    for (int i = n-2, t = k+1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while ( (cin >> n) && n ){
        vector<Point> pts(n);
        for (int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
        }

        auto hull = convexHull(pts);
        double per = 0;
        int m = hull.size();
        if (m > 1) {
            for (int i = 0; i < m; i++){
                per += dist(hull[i], hull[(i+1)%m]);
            }
        }
        // 输出保留两位小数
        cout << fixed << setprecision(2) << per << "\n";
    }
    return 0;
}
