#include<iostream>
using namespace std;

const int N = 105,MOD = 9999973;
long long dp[N][N][N]; // 前 i 列，有 j 列有 1 个棋子， k 列有两个棋子，则有 m - j - k 列没有棋子的方案数

int C2(int i) {return (1ll * i * (i - 1) / 2) % MOD;}

int main() {
    int n,m;
    long long ans = 0;
    cin >> n >> m;
    dp[0][0][0] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= m;j++)
            for (int k = 0;k <= m - j;k++) {
                dp[i][j][k] = dp[i - 1][j][k]; // 不放棋子

                if (j >= 1) // 放 1 棋在空列上
                    dp[i][j][k] += 1ll * dp[i - 1][j - 1][k] * (m - j - k + 1) % MOD,
                    dp[i][j][k] %= MOD;
                    // 少了一个空列 (不呈现在 dp 中)，多了一个 1 棋子列，可以在任何空列放
                if (k >= 1 && j + 1 <= m) // 放 1 棋在有 1 棋子的列上
                    dp[i][j][k] += 1ll * dp[i - 1][j + 1][k - 1] * (j + 1) % MOD,
                    dp[i][j][k] %= MOD;
                    // 少了一个 1 棋子列，多了一个 2 棋子列，可以在任何 1 棋子列放

                if (j >= 2) // 放 2 棋在空列上
                    dp[i][j][k] += 1ll * dp[i - 1][j - 2][k] * C2(m - j - k + 2) % MOD,
                    dp[i][j][k] %= MOD;
                    // 少了两个空列 (不呈现在 dp 中)，多了两个 1 棋子列，可以在任何空列放
                if (k >= 1) // 放 1 棋在空列上，另一个在有 1 棋子的列上
                    dp[i][j][k] += 1ll * dp[i - 1][j][k - 1] * j * (m - j - k + 1) % MOD,
                    dp[i][j][k] %= MOD;
                    // 少了一个空列多了一个 2 棋子列，可以任选 1 个 1 棋子列和 1 个空列放 (1 棋子列 +1-1 总数不变)
                if (j + 2 <= m && k >= 2) // 放 2 棋在有 1 棋子的列上
                    dp[i][j][k] += 1ll * dp[i - 1][j + 2][k - 2] * C2(j + 2) % MOD,
                    dp[i][j][k] %= MOD;
                    // 少了两个 1 棋子列，多了两个 2 棋子列，可以在任何 1 棋子列放
            }
    for (int j = 0;j <= m;j++)
        for (int k = 0;k <= m - j;k++)
            ans += dp[n][j][k],ans %= MOD;
    cout << ans << endl;
    return 0;
}