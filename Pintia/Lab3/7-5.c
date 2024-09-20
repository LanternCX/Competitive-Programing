#include <stdio.h>
int an[5];

int main(){
    int i = 0;
    for(i = 0; i < 5; i++){
        scanf("%d", &an[i]);
        if(an[i] == 0){
            break;
        }
    }
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    for(int j = 0; j < i; j++){
        double ans;
        switch (an[j]) {
            case 1:
                ans = 3.00;
                break;
            case 2:
                ans = 2.50;
                break;
            case 3:
                ans = 4.10;
                break;
            case 4:
                ans = 10.20;
                break;
            default:
                ans = 0.00;
        }
        printf("price = %.2lf\n", ans);
    }
    return 0;
}