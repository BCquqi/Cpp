#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

const int N = 205,M = 25;
long long a[M],b[M],dp[M][N]; // 前 m 个物品写 n 篇的最少时间

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) cin >> a[i] >> b[i];
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1;i <= m;i++) // i 个主题
        for (int j = 0;j <= n;j++) // 总共写了 j 篇论文
            for (int k = 0;k <= j;k++) { // 这个主题写了 k 篇
                long long t = a[i] * pow(k,b[i]);
                dp[i][j] = min(dp[i][j],dp[i - 1][j - k] + t);
            }
    cout << dp[m][n] << endl;
    return 0;
}