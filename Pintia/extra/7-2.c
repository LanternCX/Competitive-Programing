#include <stdio.h>
int sol(char str[]){
    int i = 0;
    if (str[0] != '1') {
        return 0;
    }
    for(; str[i] != '\0'; i++){
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
    }
    if(i != 11){
        return 0;
    }
    return 1;
}
int main(){
    char str[1000] = "";
    int ans = 1;
    scanf("%s", str);
    printf("%s", sol(str) ? "yes" : "no");
    return 0;
}