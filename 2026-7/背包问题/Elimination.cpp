#include<iostream>
#include<cstring>
using namespace std;

const int N = 105;
int dp[2][N * N],w[3],v[3]; // 人为消耗，题目为价值

int main() {
    int m,k;
    cin >> v[1] >> v[2] >> w[1] >> m >> k;
    w[2] = 1;
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= 2;i++)
        for (int j = 0;j <= 10000;j++) {
            dp[i & 1][j] = dp[i - 1 & 1][j];
            if (j >= w[i]) dp[i & 1][j] = min(dp[i & 1][j],dp[i & 1][j - w[i]] + v[i]);
        }
    int ans = 1e9;
    for (int i = w[1] * m - k;i <= 10000;i++)
        ans = min(ans,dp[0][i]);
    cout << ans << endl;
    return 0;
}