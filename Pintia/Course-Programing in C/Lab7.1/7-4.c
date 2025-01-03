#include <stdio.h>
int an[10000];
int main(){
    int n;
    int min = 1e7;
    int max = -1e7;
    int minIdx = 0, maxIdx = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &an[i]);
        if(an[i] < min){
            min = an[i];
            minIdx = i;
        }
    }
    int temp;
    temp = an[0];
    an[0] = an[minIdx];
    an[minIdx] = temp;
    
    for(int i = 0; i < n; i++){
        if(an[i] > max){
            max = an[i];
            maxIdx = i;
        }
    }

    temp = an[n - 1];
    an[n - 1] = an[maxIdx];
    an[maxIdx] = temp; 
    for(int i = 0; i < n; i++){
        printf("%d ", an[i]);
    }
    return 0;
}