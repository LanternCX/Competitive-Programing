#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    vector<double> all;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int an[20];
        int max = -114514;
        int min = 114514;
        for(int j = 0; j < m; j++){
            cin >> an[j];
            max = max > an[j] ? max : an[j];
            min = min < an[j] ? min : an[j];
        }
        bool mnTag = false;
        bool mxTag = false;
        for(int j = 0; j < m; j++){
            if (an[j] == max && !mxTag) {
                an[j] = -1;
                mxTag = true;
            }
            if (an[j] == min && !mnTag) {
                an[j] = -1;
                mnTag = true;
            }
        }

        int sc = 0;
        for(int j = 0; j < m; j++){
            if(an[j] < 0){
                continue;
            }
            sc += an[j];
        }
        all.push_back(sc * 1.0 / (m - 2));
    }
    double max = -114514;
    for(double i : all){
        max = max > i ? max : i;
    }
    cout << fixed << setprecision(2) << max;
    return 0;
}