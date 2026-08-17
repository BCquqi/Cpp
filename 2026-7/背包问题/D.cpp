#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 405,M = 1005,DIFF = 4e5;
int s[N],f[N];
long long dp[2][2 * DIFF]; // 智商为消耗、情商为价值，带4e5偏移量

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> s[i] >> f[i];
    for (int j = 0;j <= 2 * DIFF;j++) dp[0][j] = -1e18;
    dp[0][DIFF] = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 2 * DIFF;j++) { // 智商和
            dp[i & 1][j] = dp[i - 1 & 1][j];
            if (j - s[i] >= 0 && j - s[i] <= 2 * DIFF) dp[i & 1][j] = max(dp[i & 1][j],dp[i - 1 & 1][j - s[i]] + f[i]);
        }
    }
    for (int j = DIFF;j <= 2 * DIFF;j++) // 枚举正智商和
        if (dp[n & 1][j] >= 0) ans = max(ans,dp[n & 1][j] + j - DIFF);
    cout << ans << endl;
    return 0;
}