// 输入输出头文件
#include <stdio.h>

// 主函数，程序入口
int main(){
    // 运算符
    char ch;
    // 答案，初值为输入的第一个数
    int ans;
    // 输入数字
    scanf("%d", &ans);
    // 循环读取运算符和数字，到出现 '=' 循环终止
    while((ch = getchar()) != '='){
        // 被执行运算的数字
        int num;
        // 输入数字
        scanf("%d", &num);
        // 利用 switch 语句对运算符进行判断以执行相应的计算
        switch(ch){
            // 执行加法
            case '+':
                ans += num;
                break;
            // 执行减法
            case '-':
                ans -= num;
                break;
            // 执行乘法
            case '*':
                ans *= num;
                break;
            // 执行除法
            case '/':
                // 判断除法分母是否合法
                if(num == 0){
                    // 如果分母非法则打印 ERROR 并退出程序
                    printf("ERROR");
                    return 0;
                }
                // 执行除法
                ans /= num;
                break;
            // 非法字符则打印 ERROR
            default:
                printf("ERROR");
                return 0;
        }
    }
    // 打印最终答案
    printf("%d", ans);
    return 0;
}
// int main(){
//     int arr[1000];
//     char str[1000];
//     int len = 0;
//     while(1){
//         int n;
//         scanf("%d", &arr[len]);
//         str[len] = getchar();
//         if(str[len] == '='){
//             break;
//         }
//         len++;
//     }

//     // * and /
//     for(int i = 0; i <= len; i++){
//         if(str[i] == '*'){
//             int temp = arr[i] * arr[i + 1];
//             arr[i] = arr[i + 1] = temp;
//         }
//         if(str[i] == '/'){
//             int temp = arr[i] / arr[i + 1];
//             arr[i] = arr[i + 1] = temp;
//         }
//     }

//     // + and -
//     for(int i = 0; i <= len; i++){
//         if(str[i] == '+'){
//             int temp = arr[i] + arr[i + 1];
//             arr[i] = temp;
//             for(int j = i + 1; (str[j] != '+' && str[j] != '-') && j <= len; j++){
//                 arr[j] = arr[j + 1] = temp;
//             }
//         }
//         if(str[i] == '-'){
//             int temp = arr[i] - arr[i + 1];
//             arr[i] = temp;
//             for(int j = i + 1; (str[j] != '+' && str[j] != '-') && j <= len; j++){
//                 arr[j] = arr[j + 1] = temp;
//             }
//         }
//     }
//     printf("%d", arr[len]);
//     return 0;
// }
/**
 * 1 2 10 10 2
 * + * -  /  =
 * 
 * 1 20 20 5 5
 * + *  -  / =
 * 
 * 21 21 21 5 5
 * +  *  -  / =
 */