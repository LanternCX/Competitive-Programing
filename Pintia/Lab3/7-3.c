#include<stdio.h>
int an[3];
int main(){
	int max = -1e3;
	int min = 1e3;
	int mid = 0;
	for(int i = 0; i < 3; i++){
		scanf("%d", &an[i]);
		max = max >= an[i] ? max : an[i];
		min = min >= an[i] ? an[i] : min;
	}
	for(int i = 0; i < 3; i++){
		if(an[i] > min && an[i] < max){
			mid = an[i];
		}
	}
    if(an[1] == an[2] && an[0] == an[1] && an[2] == an[0]){
        mid = an[1];
    }
	printf("%d->%d->%d", min, mid, max);
}