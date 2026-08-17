#include<iostream>
#define int long long
using namespace std;

const int N = 205,M = 1e5 + 5;
int dp[N][M],a[N],b[N],r[M],f[N][N][N];

// dp[i][j] 表示已经处理到第 i 个物品、进行到第 j 次行动时的最大价值
// f[i][j][k] 表示区间 [i,j] 用容量为 k 的包能获得的最大价值

signed main() {
    freopen("axis.in","r",stdin);
    freopen("axis.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    for (int i = 1;i <= m;i++) cin >> r[i];
    for (int i = 1;i <= n;i++)
        for (int j = i;j <= n;j++)
            for (int k = 0;k <= 200;k++) {
                f[i][j][k] = f[i][j - 1][k];
                if (k >= a[j])
                    f[i][j][k] = max(f[i][j][k],f[i][j - 1][k - a[j]] + b[j]);
            }
    // 优化，如果 m > n 则处理最后 m 次操作即可，r 也取最大的最后 m 个
    if (m > n) {
        for (int i = 1;i <= n;i++)
            for (int j = m - n + 1;j <= m;j++) {
                dp[i][j - m + n] = dp[i][j - m + n - 1]; // 不行动
                for (int k = 1;k <= i;k++)
                    dp[i][j - m + n] = max(dp[i][j - m + n],dp[k - 1][j - m + n - 1] + f[k][i][r[j]]);
            }
        cout << dp[n][n] << endl;
    }
    else {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++) {
                dp[i][j] = dp[i][j - 1]; // 不行动
                for (int k = 1;k <= i;k++)
                    dp[i][j] = max(dp[i][j],dp[k - 1][j - 1] + f[k][i][r[j]]);
            }
        cout << dp[n][m] << endl;
    }
    return 0;
}