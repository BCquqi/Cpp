#include<iostream>
using namespace std;

const int N = 1e3 + 5,K = 5e3 + 5;
int a[N][K],dp[N][N],maxn[N][N];
bool flag[N][N];
// dp[i][j] 表示处理到 i，以 j 结尾的最长上升子序列长度

int main() {
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    int k,n,ans = 0;
    cin >> k >> n;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= k;j++) {
            cin >> a[i][j];
            flag[i][a[i][j]] = true;
        }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 1000;j++) {
            dp[i][j] = dp[i - 1][j]; // 不选
            if (flag[i][j]) dp[i][j] = max(dp[i][j],maxn[i - 1][j - 1] + 1); // 选
            maxn[i][j] = max(maxn[i][j - 1],dp[i][j]);
        }
    }
    for (int i = 0;i <= 1000;i++) ans = max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}