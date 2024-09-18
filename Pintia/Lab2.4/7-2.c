#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	double ans = 0;
	for(int i = 1; i <= (n * 2 - 1); i += 2){
		ans += 1.0 / i;
	}
	printf("sum = %.6f", ans);
	return 0;
}