#include<iostream>
#include<cstring>
using namespace std;

const int N = 105,M = 10;
int h[N],p[100];
long long dp[N][100][100];

int f(int x) {
    int ret = 0;
    while (x) ret += x & 1,x >>= 1;
    return ret;
}

int main() {
    int n,m,cnt = 0;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            h[i] = (h[i] << 1) | (c == 'H');
        }
    for (int i = 0;i < (1 << m);i++) {
        if (i & (i << 1)) continue;
        if (i & (i << 2)) continue;
        p[++cnt] = i;
    }
    memset(dp,-0x3f,sizeof dp);
    dp[0][1][1] = 0;
    for (int i = 1;i <= n;i++) // 当前行数
        for (int j = 1;j <= cnt;j++) { // 当前行状态
            if (p[j] & h[i]) continue;
            for (int k = 1;k <= cnt;k++) { // 前一行状态
                if (p[k] & h[i - 1]) continue;
                if (p[j] & p[k]) continue;
                for (int l = 1;l <= cnt;l++) { // 前两行状态
                    if (p[l] & h[i - 2]) continue;
                    if (p[j] & p[l]) continue;
                    dp[i][j][k] = max(dp[i][j][k],dp[i - 1][k][l] + f(p[j]));
                }
            }
        }
    for (int j = 1;j <= cnt;j++)
        for (int k = 1;k <= cnt;k++) ans = max(ans,dp[n][j][k]);
    cout << ans << endl;
    return 0;
}