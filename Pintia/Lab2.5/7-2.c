#include<stdio.h>
#include<math.h>
int main(){
	int n;
	scanf("%d", &n);
	double ans = 0;
	for(int i = 1; i <= n; i++){
		ans += sqrt((double) i);
	}
	printf("sum = %.2lf", ans);
}