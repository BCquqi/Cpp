#include <cstdio>
#include <cstring>
int a[201], b[201], r[100001];
int dp[201];
int dp2[201][201][201];
inline int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    //freopen("axis.in", "r", stdin);
    //freopen("axis.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &r[i]);
    }
    for (int l = 1; l <= n; ++l) {
        for (int r1 = l; r1 <= n; ++r1) {
            for (int w = 200; w >= 0; --w) {
                dp2[l][r1][w] = dp2[l][r1 - 1][w];
                if (w - a[r1] >= 0) {
                    dp2[l][r1][w] = max(dp2[l][r1][w - a[r1]] + b[r1], dp2[l][r1][w]);
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j; --j) {
            for (int last = 0; last < j; ++last) {
                int nw = r[i];
                int nst = last + 1;
                int ned = j;
                int nans = 0;
                for (int w = nw; w >= 0; --w) {
                    nans = max(nans, dp2[nst][ned][w]);
                }
                dp[j] = max(dp[j], dp[last] + nans);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
