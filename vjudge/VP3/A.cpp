#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "67108864", // 双引号中替换为 A 题的答案
        "3181", // 双引号中替换为 B 题的答案
        "40257", // 双引号中替换为 C 题的答案
        "2430", // 双引号中替换为 D 题的答案
        "10266837", // 双引号中替换为 E 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}