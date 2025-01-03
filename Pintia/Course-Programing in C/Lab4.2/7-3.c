#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char ch = 'A' - 1;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < i; j++){
            ch++;
            printf("%c", ch);
            printf("%c", ' ');
        }
        printf("%c", '\n');
    }
    return 0;
}