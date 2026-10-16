#include<iostream>
using namespace std;

const int N = 35,T = 1080005;
int w1[N],w2[N],v1[N],v2[N],dp[N][T]; // dp[i][j] 表示前 i 个题，用了 j 分钟时间的最高得分

int main() {
    int n,t;
    cin >> n >> t;
    for (int i = 1;i <= n;i++) cin >> v1[i] >> w1[i] >> v2[i] >> w2[i];
    for (int i = 1;i <= n;i++)
        for (int j = 0;j <= t;j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w1[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w1[i]] + v1[i]);
            if (j >= w2[i]) dp[i][j] = max(dp[i][j],dp[i - 1][j - w2[i]] + v2[i]);
        }
    cout << dp[n][t] << endl;
    return 0;
}