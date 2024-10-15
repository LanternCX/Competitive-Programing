#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	int ans = 0;
	int i = 1;
	for(i = 1; i <= n; i++){
		ans = ans + i;
	}
	printf("sum = %d", ans);
	return 0;
}