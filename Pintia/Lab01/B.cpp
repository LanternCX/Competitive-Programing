#include <stdio.h>
#include <string.h>
struct node{
    char name[100];
    int sc;
};
void swap(struct node * a, struct node * b) {
    struct node temp = *a;
    *a = *b;
    *b = temp;
}
const int N = 10000;
void sol(){
    int n;
    scanf("%d", &n);
    struct node arr[N + 10];

    for(int i = 0; i < n; i++){
        scanf("%s %d\n", arr[i].name, &arr[i].sc);
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i].sc == arr[j].sc){
                if(strcmp(arr[i].name, arr[j].name) > 0){
                    swap(&arr[i], &arr[j]);
                }
            }else if(arr[i].sc < arr[j].sc){
                swap(&arr[i], &arr[j]);
            }
        }
    }
    
    int rk = 1;
    int cnt = 0;
    int temp = -1;
    for(int i = 0; i < n; i++){
        int sc = arr[i].sc;
        if(sc != temp){
            temp = sc;
            rk += cnt;
            cnt = 0;
        }
        cnt++;
        printf("%d %s\n", rk, arr[i].name);
    }
}
int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}