#include <stdio.h>
struct node{
    char name[50];
    double price;
};
int main(){
    int n;
    scanf("%d", &n);
    struct node arr[20];
    int min_idx = 0;
    int max_idx = 0;
    for(int i = 0; i < n; i++){
        getchar();
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        scanf("%lf", &arr[i].price);
        min_idx = arr[min_idx].price > arr[i].price ? i : min_idx;
        max_idx = arr[max_idx].price < arr[i].price ? i : max_idx;
    }
    
    printf("%.2lf, %s", arr[max_idx].price, arr[max_idx].name);
    printf("%.2lf, %s", arr[min_idx].price, arr[min_idx].name);
    return 0;
}