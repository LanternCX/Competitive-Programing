#include <stdio.h>
struct node{
    char name[20];
    double base, det, out, in;
};
struct node arr[1000];
int main(){
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%s %lf %lf %lf", arr[i].name, &arr[i].base, &arr[i].det, &arr[i].out);
        arr[i].in = arr[i].base + arr[i].det - arr[i].out;
        printf("%s %.2lf\n", arr[i].name, arr[i].in);
    }
    
    return 0;
}