#include <bits/stdc++.h>
using namespace std;
int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int msize, n;
    cin >> msize >> n;
    int tsize;
    for (tsize = msize; !isPrime(tsize); tsize++);
    vector<bool> hashmap(tsize, false);
    for (int t = 0; t < n; t++) {
        int key;
        cin >> key;
        int h = key % tsize;
        int tag = 0;
        for (int i = 0; i < tsize; i++) {
            int idx = (h + i * i) % tsize;
            if (!hashmap[idx]) { 
                cout << idx << " \n"[t == n - 1];
                hashmap[idx] = true;
                tag = 1;
                break;                
            }
        }
        if (!tag) {
            cout << "-" << " \n"[t == n - 1];
        }
    }
    return 0;
}