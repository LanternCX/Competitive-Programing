#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	double ans = 0;
	int i = 1;
	for(i = 1; i <= n; i++){
		ans = ans + 1.0 / i;
	}
	printf("sum = %.6f", ans);
	return 0;
}