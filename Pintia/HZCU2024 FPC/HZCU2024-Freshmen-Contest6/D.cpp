#include <bits/stdc++.h>
using namespace std;
double a1, a2, a3, a0;
double f(double x){
	return a3 * x * x * x + a2 * x * x + a1 * x + a0; 
} 
int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
//	cin >> a3 >> a2 >> a1 >> a0;
	double l, r;
	scanf("%lf %lf", &l, &r);
	double mid = (l + r) / 2;
	while(r - l >= 0.01){
		mid = (l + r) / 2;
		double vm = f(mid);
		double vl = f(l);
		double vr = f(r);
		if(vm == 0){
			printf("%.2lf", mid);
			return 0;
		}
//		printf("%lf", vm * vr);
		if(vm * vr <= 0){
//			printf("%lf %lf\n", l, r);
			l = mid;
		}else{
//			printf("%lf %lf\n", l, r);
			r = mid;
		}
		
		if(vl * vr > 0){
			break;
		}
	}
	
	printf("%.2lf", (l + r) / 2);
	return 0; 
}