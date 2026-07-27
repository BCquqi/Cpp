#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
int sum[N][33];
long long dp[N][33];
// sum: 从 e 开始的 5 个格子为 j 时高兴的人的个数
// dp: 枚举到第 i 个围栏且 [i,i+5] 的围栏移走状态为 s 时的答案
int x[N],y[N];

int main() {
    int n,c;
    long long ans = 0;
    cin >> n >> c;
    for (int i = 1;i <= c;i++) {
        int e,f,l,h = 0,d = 0;
        cin >> e >> f >> l;
        for (int j = 1;j <= f;j++) {
            cin >> x[j];
            x[j] = (x[j] - e + n) % n;
            h = h | (1 << x[j]);
        }
        for (int j = 1;j <= l;j++) {
            cin >> y[j];
            y[j] = (y[j] - e + n) % n;
            d = d | (1 << y[j]);
        }
        for (int j = 0;j < 32;j++)
            if ((~j & h) || (j & d)) sum[e][j]++;
    }
    for (int i = 0;i < 32;i++) { // 初始状态
        memset(dp,-0x3f,sizeof dp);
        dp[0][i] = 0;
        for (int j = 1;j <= n;j++)
            for (int k = 0;k < 32;k++)
                dp[j][k] = max(dp[j - 1][((k & 15) << 1) | 0],dp[j - 1][((k & 15) << 1) | 1]) + sum[j][k];
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}