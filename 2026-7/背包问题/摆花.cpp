#include<iostream>
using namespace std;

const int N = 105,MOD = 1e6 + 7;
int a[N],dp[N][N]; // dp[i][j] 表示摆到第 i 朵花，目前共有 j 盆

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= m;j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1;k <= a[i];k++) {
                if (j >= k) dp[i][j] += dp[i - 1][j - k],dp[i][j] %= MOD;
            }
        }
    cout << dp[n][m] << endl;
    return 0;
}