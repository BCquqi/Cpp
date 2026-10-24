#include<iostream>
#define int long long
using namespace std;

const int N = 55, mod = 1e9 + 7;
int dp[N][N][N * N];

signed main() {
    int n, K;
    cin >> n >> K;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = j * 2; k <= K;k++) {
                dp[i][j][k] = ((2 * j + 1) * dp[i - 1][j][k - 2 * j] % mod + (j + 1) * (j + 1) % mod * (dp[i - 1][j + 1][k - 2 * j]) % mod) % mod;
                if (j > 0) dp[i][j][k] += dp[i - 1][j - 1][k - 2 * j], dp[i][j][k] %= mod;
            }
    cout << dp[n][0][K] % mod << endl;
    return 0;
}