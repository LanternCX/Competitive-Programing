#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){return a % b == 0 ? b : gcd(b, a % b);}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    string dict = "123456789";
    string temp = dict;
    bool isFound = 0;

    while (next_permutation(dict.begin(), dict.end())) {
        int a = stoi(temp.substr(0,3));
        int b = stoi(temp.substr(3, 3));
        int c = stoi(temp.substr(6,3));
        if(A * b == B * a && A * c ==  C * a){
            cout << a << ' ' << b << ' ' << c << '\n';
            isFound = 1;
        }
        temp = dict;
    }

    if (!isFound) {
        cout << "No!!!" << endl;
    }
    return 0;
}