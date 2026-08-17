#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005,M = 205,MOD = 1e9 + 7;
int dp[2][M][M][2]; // f[i][j][k][1/0] 表示从 A 的前 i 个字符选 k 个子串拼出 B 串的前 j 个字符的方案数，第 i 个字符选/不选

int main() {
    int n,m,K;
    string a,b;
    cin >> n >> m >> K >> a >> b;
    a = '?' + a,b = '?' + b;
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            for (int k = 0;k <= K;k++) {
                dp[i & 1][j][k][0] = dp[i & 1][j][k][1] = 0; // 重要！查错发现这里一定要加，不然会有之前的数据混进来！
                dp[i & 1][j][k][0] = (dp[i - 1 & 1][j][k][0] + dp[i - 1 & 1][j][k][1]) % MOD; // 上一步直接继承
                if (a[i] == b[j]) { // 可以选
                    dp[i & 1][j][k][1] += dp[i - 1 & 1][j - 1][k][1];
                    dp[i & 1][j][k][1] %= MOD;
                    if (k)
                        dp[i & 1][j][k][1] += (dp[i - 1 & 1][j - 1][k - 1][0] + dp[i - 1 & 1][j - 1][k - 1][1]) % MOD,
                        dp[i & 1][j][k][1] %= MOD;
                }
            }
    cout << (dp[n & 1][m][K][0] + dp[n & 1][m][K][1]) % MOD << endl;
    return 0;
}