#include <bits/stdc++.h>
using namespace std;

struct Stu {
    int id;
    int sc;
    int w;
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

string getAns(int sum, int count) {
    if (sum % count == 0) {
        return to_string(sum / count);
    }
    int d = gcd(sum, count);
    sum /= d;
    count /= d;
    int n = sum / count;
    sum -= n * count;
    string res;
    if (n != 0) {
        res += to_string(n) + '+';
    }
    res += to_string(sum) + '/' + to_string(count);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<Stu>> clss(n);
    
    for (int k = 0; k < n; k++) {
        int p;
        cin >> p;

        vector<int> id(p);
        vector<int> sc(p);
        vector<int> w(p);
        for (int i = 0; i < p; i++) {
            cin >> id[i];
        }
        for (int i = 0; i < p; i++) {
            cin >> sc[i];
        }
        for (int i = 0; i < p; i++) {
            cin >> w[i];
        }

        vector<Stu> cls(p);
        for (int i = 0; i < p; i++) {
            cls[i] = {id[i], sc[i], 0};
        }
        sort(cls.begin(), cls.end(), [](const Stu& a, const Stu& b) {
            return a.id < b.id;
        });

        vector<int> sortedScores(sc);
        sort(sortedScores.begin(), sortedScores.end(), greater<int>());
        for (int i = 0; i < p; i++) {
            int rank = 0;
            for (int j = 0; j < p; j++) {
                if (sortedScores[j] > sc[i]) {
                    rank++;
                }
            }
            cls[i].w = w[rank];
        }
        
        clss[k] = cls;
    }
    
    int tag;
    cin >> tag;

    int sum = 0;
    int count = 0;
    for (auto& cls : clss) {
        for (auto s : cls) {
            if (s.id == tag) {
                count++;
                sum += s.w;
            }
        }
    }
    
    cout << getAns(sum, count);
    return 0;
}
