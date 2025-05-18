#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;

    // 删除字符串末尾等于号
    s.pop_back();

    // num 栈, 用于记录参与运算的数据
    stack<char> num;
    // op 栈，用于记录运算符
    stack<char> op;

    // 当前输出的表达式编号
    int cnt = 0;

    // 双目运算
    auto calc = [&](char a, char b, char op) {
        // 将字符转换为布尔值
        bool x = (a == 't'), y = (b == 't');
        // 判断运算类型并进行运算
        char res = (op == '&') ? (x && y ? 't' : 'f') : (x || y ? 't' : 'f');
        // 按题目要求构造输出
        cnt++;
        cout << cnt << ":" << a << " " << op << " " << b << " = " << res << "\n";
        // 返回结果
        return res;
    };

    // 单目运算
    auto calc_not = [&](char a) {
        // 非运算，将字符取反
        char res = (a == 't') ? 'f' : 't';
        // 按题目要求构造输出
        cnt++;
        cout << cnt << ":! " << a << " = " << res << "\n";
        // 返回结果
        return res;
    };

    // 运算符优先级表
    map<char, int> prec = {
        {'!', 3},
        {'&', 2},
        {'|', 1}
    };

    // 字符串前后加入哨兵括号方便处理
    s.insert(s.begin(), '(');
    s.push_back(')');

    for (char ch : s) {
        // 当前如果是运算值直接入运算值栈存储
        if (ch == 't' || ch == 'f') {
            num.push(ch);
            continue;
        }

        // 如果是左括号直接入运算符栈不需要处理逻辑
        if (ch == '(') {
            op.push(ch);
            continue;
        } 

        // 如果是运算符用栈进行模拟计算
        if (ch == '!' || ch == '&' || ch == '|') {
            // 如果不是 ! 需要判断运算符优先级
            // 高于当前运算符优先级的运算符需要先计算
            // 因此运算到优先级低于当前运算符优先级的运算符然后就可以 break
            while (ch != '!' && prec[op.top()] >= prec[ch]) {
                // 如果是右括号说明括号前的运算已经完成直接 break
                if(op.top() == '(') {
                    break;
                }
                
                // 取出操作符
                char oper = op.top(); 
                op.pop();

                // 如果是 ! 那么进行单目运算
                if (oper == '!') {
                    // 取出操作数
                    char a = num.top(); 
                    num.pop();
                    // 运算后推入操作数栈
                    num.push(calc_not(a));
                    continue;
                } 

                // 如果是 & 或者 | 进行双目运算
                if (oper == '&' || oper == '|'){
                    // 取出操作数
                    char b = num.top(); 
                    num.pop();
                    char a = num.top(); 
                    num.pop();
                    // 运算后推入操作数栈
                    num.push(calc(a, b, oper));
                    continue;
                }
            }

            // 推入当前操作符
            op.push(ch);
            continue;
        } 

        // 如果是右括号需要将上一个左括号前的表达式求值
        if (ch == ')') {
            // 栈空或者遇到左括号就停止循环
            while (op.top() != '(') {
                // 取出操作符
                char oper = op.top(); 
                op.pop();

                // 如果是 ! 那么进行单目运算
                if (oper == '!') {
                    // 取出操作数
                    char a = num.top(); 
                    num.pop();
                    // 运算后推入操作数栈
                    num.push(calc_not(a));
                    continue;
                } 

                // 如果是 & 或者 | 进行双目运算
                if (oper == '&' || oper == '|'){
                    // 取出操作数
                    char b = num.top(); 
                    num.pop();
                    char a = num.top(); 
                    num.pop();
                    // 运算后推入操作数栈
                    num.push(calc(a, b, oper));
                    continue;
                }
            }
            // 将右括号 ( 出栈
            op.pop();
            continue;
        }
    }

    cout << "result = " << num.top();
    return 0;
}