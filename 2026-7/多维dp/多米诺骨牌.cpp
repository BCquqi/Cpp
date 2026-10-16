#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005,M = 6005;
int a[N],b[N],dp[N][M]; // dp[i][j] 表示前 i 个骨牌，第一行骨牌数字和为j的最少旋转次数

int main() {
    int n,sum = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 6 * n;j++) {
            if (j >= a[i]) dp[i][j] = min(dp[i][j],dp[i - 1][j - a[i]]);
            if (j >= b[i]) dp[i][j] = min(dp[i][j],dp[i - 1][j - b[i]] + 1);
        }
    int minsub = 1e9,ans = 1e9;
    for (int i = 1;i <= 6 * n;i++) {
        if (abs(i - sum + i) < minsub)
            minsub = abs(i - sum + i),ans = dp[n][i];
        else if (abs(i - sum + i) == minsub) // 一样的话也要更新最少次数
            ans = min(ans,dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}