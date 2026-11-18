#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105,M = 205;
int m[N],t[N],dp[N][M][M];

int main() {
    int n,M,T;
    cin >> n >> M >> T;
    for (int i = 1;i <= n;i++) cin >> m[i] >> t[i];
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= M;j++)
            for (int k = 0;k <= T;k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= m[i] && k >= t[i])
                    dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - m[i]][k - t[i]] + 1);
            }
    cout << dp[n][M][T] << endl;
    return 0;
}