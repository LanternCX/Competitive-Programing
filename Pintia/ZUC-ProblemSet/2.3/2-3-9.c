#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n < 100 || n > 999){
    	printf("Invalid Value.");
    	return 0;
	}
	int a = n / 100;
	int c = n % 10;
	int b = (n - a * 100 - c) / 10;
	printf("%s", a * a * a + b * b * b + c * c * c == n ? "Yes" : "No");
	return 0;
}