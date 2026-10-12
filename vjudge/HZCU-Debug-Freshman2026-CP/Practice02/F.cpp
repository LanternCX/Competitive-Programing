#include <stdio.h>
#include <math.h>

int a[100 + 10][100 + 10];
double avg[100 + 10];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += a[i][j];
            }
            printf("%.2lf", sum * 1.0 / m);
            printf(i != (n - 1) ? " " : "\n");
        }
        
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i][j];
            }
            avg[j] = sum * 1.0 / n;
            printf("%.2lf", avg[j]);
            printf(j != (m - 1) ? " " : "\n");
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += a[i][j] < avg[j] ? 1 : 0;
            }
            
            ans += cnt > 0 ? 0 : 1;
        }
        printf("%d\n\n", ans);
    }
    return 0;
}