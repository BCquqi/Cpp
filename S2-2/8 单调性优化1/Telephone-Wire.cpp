#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int h[N],dp[N][105];
// dp[i][j]: 前 i 根电线杆, 第 i 根高度为 j 的最小成本

int main() {
    int n,c,ans = 1e9;
    cin >> n >> c;
    for (int i = 1;i <= n;i++) cin >> h[i];
    memset(dp,0x3f,sizeof dp);
    for (int j = h[1];j <= 100;j++)
        dp[1][j] = (j - h[1]) * (j - h[1]);
    for (int i = 2;i <= n;i++) {
        int minn = 2e9;
        for (int j = 1;j <= 100;j++) {
            minn = min(minn,dp[i - 1][j] - c * j);
            if (j >= h[i]) dp[i][j] = min(dp[i][j],(j - h[i]) * (j - h[i]) + c * j + minn);
        }
        minn = 2e9;
        for (int j = 100;j >= 1;j--) {
        	minn = min(minn,dp[i - 1][j] + c * j);
        	if (j >= h[i]) dp[i][j] = min(dp[i][j],(j - h[i]) * (j - h[i]) - c * j + minn);
        }
    }
    for (int i = 1;i <= 100;i++) ans = min(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}