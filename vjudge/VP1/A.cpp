#include<iostream>
using namespace std;
int main() {
    string ans [] = {
        "180414", // 双引号中替换为 A 题的答案
        "47373", // 双引号中替换为 B 题的答案
        "240", // 双引号中替换为 C 题的答案
        "101449", // 双引号中替换为 D 题的答案
        "36", // 双引号中替换为 E 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
