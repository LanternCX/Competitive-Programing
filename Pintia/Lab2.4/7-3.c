#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	
	double ans = 0;
	for(int i = 1; i <= (n * 3 - 1); i += 3){
		ans = i % 2 == 0 ? (ans - 1.0 / i) : (ans + 1.0 / i);
	}
	printf("sum = %.3lf", ans);
	return 0;
}