#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int ans;
	if(n == 0){
		ans = 0;
	}else{
		ans = n > 0 ? 1 : -1;
	}
	printf("sign(%d) = %d", n, ans);
}