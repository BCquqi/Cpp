#include<iostream>
#include<cstring>
using namespace std;

const int N = 55;
long long dp[N][N][5][2]; // 位置 次数 方向
char c[N][N];

void solve() {
    memset(dp,0,sizeof dp);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cin >> c[i][j];
    for (int i = 1;i <= n;i++) {
        if (c[i][1] == 'H') break;
        dp[i][1][0][1] = 1;
    }
    for (int j = 1;j <= n;j++) {
        if (c[1][j] == 'H') break;
        dp[1][j][0][0] = 1;
    }
    for (int i = 2;i <= n;i++)
        for (int j = 2;j <= n;j++) {
            if (c[i][j] == 'H') continue;
            for (int k = 0;k <= m;k++) {
                if (i > 1) { // 向下
                    dp[i][j][k][1] += dp[i - 1][j][k][1];
                    if (k) dp[i][j][k][1] += dp[i - 1][j][k - 1][0];
                }
                if (j > 1) { // 向右
                    dp[i][j][k][0] += dp[i][j - 1][k][0];
                    if (k) dp[i][j][k][0] += dp[i][j - 1][k - 1][1];
                }
            }
        }
    int ans = 0;
    for (int k = 0;k <= m;k++)
        ans += dp[n][n][k][0] + dp[n][n][k][1];
    cout << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}