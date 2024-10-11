#include <stdio.h>

int main(){
    char ch;
    int ans;
    scanf("%d", &ans);
    while((ch = getchar()) != '='){
        int temp;
        scanf("%d", &temp);
        switch(ch){
            case '+':
                ans += temp;
                break;
            case '-':
                ans -= temp;
                break;
            case '*':
                ans *= temp;
                break;
            case '/':
                if(temp == 0){
                    printf("ERROR");
                    return 0;
                }
                ans /= temp;
                break;
            default:
                printf("ERROR");
                return 0;
        }
        
    }
    printf("%d", ans);
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