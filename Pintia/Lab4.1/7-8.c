#include <stdio.h>
int an[105];
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int t = 0;
    int i;
    for(i = 1; i <= n; i++){
        int in;
        scanf("%d", &in);
        if(in < 0){
            an[i] = 5;
            break;
        }

        an[i] = in > m ? 1 : 0;
        t++;

        if(in == m){
            if (t == 1) {
                an[i] = 2;
            }else if(t <= 3){
                an[i] = 3;
            }else {
                an[i] = 4;
            }
            break;
        }
        if(i == n){
            an[i + 1] = 5;
        }
    }
    
    for(int j = 1; j <= i; j++){
        switch (an[j]) {
            case 0:
                printf("Too small");
                break;
            case 1:
                printf("Too big");
                break;
            case 2:
                printf("Bingo!");
                break;
            case 3:
                printf("Lucky You!");
                break;
            case 4:
                printf("Good Guess!");
                break;
            case 5:
                printf("Game Over");
                break;
        }
        printf("\n");
    }
    return 0;
}
/**
 * 0 : too small
 * 1 : too big
 * 2 : Bingo!
 * 3 : Lucky You!
 * 4 : Good Guess!
 * 5 : Game Over!
 */