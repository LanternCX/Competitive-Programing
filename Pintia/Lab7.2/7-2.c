#include<stdio.h>
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++){
		int sum = 0;
		for(int j = 1; j <= n; j++){
			int n;
			scanf("%d", &n);
			sum += n;
		}
		printf("%d\n", sum);
	}
	return 0;
}