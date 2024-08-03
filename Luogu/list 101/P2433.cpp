#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 6 << " " << 4;
    } else if (T == 3) {
        cout << 3 << endl << 12 << endl << 2;
    } else if (T == 4) {
        cout << fixed << setprecision(3) << 1.0*500/3;
    } else if (T == 5) {
        cout << 15;
    } else if (T == 6) {
        cout<<sqrt(6*6 + 9*9);
    } else if (T == 7) {
        cout<< 100 + 10 << endl << 100 + 10 - 20 << endl << 0;
    } else if (T == 8) {
        cout << 3.141593 * 2 * 5 << endl << 3.141593 * 5 * 5 << endl << 4.0/3 * 125 * 3.141593;
    } else if (T == 9) {
        cout << 22;
    } else if (T == 10) {
        cout << 9;
    } else if (T == 11) {
        cout<< 1.0 * 100 / 3;
    } else if (T == 12) {
        cout << 13 << endl <<'R';
    } else if (T == 13) {
        cout << 16;
    } else if (T == 14) {
        int  j = 10000;
        for(int i = 0; i < 110 ; i++){
            if((i + 10) * (110 - i) == 3500 && 110 - i < j){
                j = 110 - i;
            }
        }
        cout << j;
    }
    return 0;
}