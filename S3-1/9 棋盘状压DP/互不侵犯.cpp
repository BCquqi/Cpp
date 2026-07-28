#include<iostream>
using namespace std;

const int N = 10;
int p[1 << N];
long long dp[N][1 << N][N * N];

// dp[i][j][m] 有 i 行，第 i 行状态为 j，放置了 m 个国王的方案数

int f(int x) {
    int ret = 0;
    while (x) ret += x & 1,x >>= 1;
    return ret;
}

int main() {
    int n,K,cnt = 0;
    long long ans = 0;
    cin >> n >> K;
    for (int i = 0;i < (1 << n);i++) {
        if ((i & (i << 1))) continue;
        p[++cnt] = i;
    }
    dp[0][1][0] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= cnt;j++) // 当前行状态
            for (int m = f(p[j]);m <= K;m++) {
                for (int k = 1;k <= cnt;k++) { // 第 i - 1 行状态
                    if (p[j] & p[k]) continue;
                    if ((p[j] >> 1) & p[k]) continue;
                    if ((p[j] << 1) & p[k]) continue;
                    dp[i][j][m] += dp[i - 1][k][m - f(p[j])];
                }
            }
    for (int j = 1;j <= cnt;j++) ans += dp[n][j][K];
    cout << ans << endl;
    return 0;
}