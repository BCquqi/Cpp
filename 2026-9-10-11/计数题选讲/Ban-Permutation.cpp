#include<iostream>
using namespace std;

const int N = 105,mod = 998244353;
int dp[N][N][1 << 9];
// 处理到第 i 位，匹配 j 对，状态为 k

signed main() {
    int n,x;
    cin >> n >> x;
    int len = 2 * x - 2,lim = (1 << len) - 1;
    int cnt0 = 0,cnt1 = 0;
    dp[0][0][lim] = 1;
    for (int i = 0;i < len;i += 2) cnt0 |= 1 << i;
    for (int i = 1;i < len;i += 2) cnt1 |= 1 << i;
    for (int i = 0;i < n;i++)
        for (int j = 0;j <= i;j++)
            for (int k = 0;k <= lim;k++) {
                if (!dp[i][j][k]) continue;
                int l = i - j - __builtin_popcount(lim ^ (k & cnt0 | cnt1)), 
                    r = i - j - __builtin_popcount(lim ^ (k & cnt1 | cnt0));
                dp[i + 1][j][(k << 2) & lim] = (dp[i + 1][j][(k << 2) & lim] + dp[i][j][k]) % mod;
                dp[i + 1][j + 1][(k << 2 | 1) & lim] = (dp[i + 1][j + 1][(k << 2 | 1) & lim] + 1ll * r * dp[i][j][k]) % mod;
                dp[i + 1][j + 1][(k << 2 | 2) & lim] = (dp[i + 1][j + 1][(k << 2 | 2) & lim] + 1ll * l * dp[i][j][k]) % mod;
                dp[i + 1][j + 2][(k << 2 | 3) & lim] = (dp[i + 1][j + 2][(k << 2 | 3) & lim] + 1ll * l * r * dp[i][j][k]) % mod;
            }
    cout << dp[n][n][lim] << endl;
    return 0;
}