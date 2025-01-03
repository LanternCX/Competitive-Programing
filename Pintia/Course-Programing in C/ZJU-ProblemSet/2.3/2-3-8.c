#include<stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int h1 = a / 100;
    int h2 = b / 100;
    int m1 = a % 100;
    int m2 = b % 100;
    int h, m;
    if(h1 == h2){
    	m = 60 - m1 + m2;	
    	h = 0;
	}else{
		if(m2 >= m1){
			m = m2 - m1;
			h = h2 - h1;
		}else{
			m = m2 + 60 - m1;
			h = h2 - 1 - h1;
		}
	}
	printf("%02d:%02d", h, m);
	return 0;
}