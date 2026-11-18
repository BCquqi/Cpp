#include <iostream>
#define int long long
using namespace std;

const int N = 4e3 + 5, mod = 1e9 + 7;
int dp[N][N];
// 有 i 位数位和为 j 的 K 进制数个数

signed main() {
    int n, m, K;
    cin >> n >> m >> K;
    dp[0][0] = 1;
    for (int i = 1; i <= (n + m - 1) / (K - 1); i++)
        for (int j = 0; j < K; j++)
            for (int k = j;k <= m && k <= 1ll * i * K; k++)
                dp[i][k] += dp[i - 1][k - j], dp[i][k] %= mod;
    long long ans = 0;
    for (int i = m, j = (n + m - 1) / (K - 1); i >= 1; i -= K - 1, j--)
        ans += dp[j][i], ans %= mod;
    cout << ans << endl;
    return 0;
}