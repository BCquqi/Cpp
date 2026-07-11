#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 55;
int a[N][N];
long long dp[105][N][N];
// dp[i][j][k] 代表走了 i 步，一个位于 j 行，另一个位于 k 行的最大好感度

int main() {
    int m,n;
    cin >> m >> n;
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++) cin >> a[i][j];
    memset(dp,-0x3f,sizeof dp);
    dp[0][1][1] = a[1][1];
    for (int i = 1;i <= n + m - 2;i++)
        for (int j = 1;j <= m && i + 2 - j > 0;j++) // 必须做越界约束
            for (int k = 1;k <= m && i + 2 - k > 0;k++) {
                long long val;
                if (j == k) val = a[j][i + 2 - j];
                else val = a[j][i + 2 - j] + a[k][i + 2 - k];
                dp[i][j][k] = max(max(dp[i - 1][j][k],dp[i - 1][j - 1][k]),max(dp[i - 1][j][k - 1],dp[i - 1][j - 1][k - 1])) + val;
            }
    cout << dp[n + m - 2][m][m] << endl;
    return 0;
}