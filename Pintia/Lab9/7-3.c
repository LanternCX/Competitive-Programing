#include <stdio.h>
struct node{
    char id[10];
    char name[20];
    int sc;
};
struct node arr[15];
int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", arr[i].id, arr[i].name, &arr[i].sc);
        sum += arr[i].sc;
    }
    double avg = sum * 1.0 / n;
    printf("%.2lf\n", avg);
    for(int i = 0; i < n; i++){
        if(arr[i].sc < avg){
            printf("%s %s\n", arr[i].name, arr[i].id);
        }
    }
    return 0;
}