#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    deque<int> arr;
    bool head = true;

    while (q--) {
        int a;
        cin >> a;

        if (a == 1) {
            int x;
            cin >> x;
            if (head) {
                arr.push_back(x);
            } else {
                arr.push_front(x);
            }
        } else if (a == 2) {
            if (head && !arr.empty()) {
                arr.pop_front();
            } else if (!head && !arr.empty()) {
                arr.pop_back();
            }
        } else if (a == 3) {
            head = !head;
        }

        if (arr.empty()) {
            cout << -1 << '\n';
        } else {
            int l = head ? arr.front() : arr.back();
            int r = head ? arr.back() : arr.front();
            cout << (l ^ r) << '\n';
        }
    }
    return 0;
}
