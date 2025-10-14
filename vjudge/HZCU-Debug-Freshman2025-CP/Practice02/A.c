#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[100] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int mn = 1e9, mx = 0;
	for (int i = 0; i < n; i++) {
		mn = fmin(a[i], mn);
		mx = fmax(a[i], mx);
	}
	printf("%d", mx - mn);
	return 0;
}