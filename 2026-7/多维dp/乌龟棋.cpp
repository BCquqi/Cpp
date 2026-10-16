#include<iostream>
using namespace std;

const int N = 355,M = 125;
int a[N],b[M],cnt[5],dp[M][M][M][M];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    dp[0][0][0][0] = a[1];
    for (int i = 0;i <= cnt[1];i++)
        for (int j = 0;j <= cnt[2];j++)
            for (int k = 0;k <= cnt[3];k++)
                for (int l = 0;l <= cnt[4];l++) {
                    if (i > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i - 1][j][k][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (j > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j - 1][k][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (k > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k - 1][l] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                    if (l > 0) dp[i][j][k][l] = max(dp[i][j][k][l],dp[i][j][k][l - 1] + a[1 + i + 2 * j + 3 * k + 4 * l]);
                }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return 0;
}