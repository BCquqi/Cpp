#include<iostream>
#include<cstring>
using namespace std;

const int N = 205,M = 5005,K = 55;
int w[N],v[N],dp[M][K],st1[N],st2[N]; // dp 表示用了 M 空间的 K 优解

// 这题先尝试一下一维优化

int main() {
    int k,m,n,tail1 = 0,tail2 = 0;
    cin >> k >> m >> n;
    for (int i = 1;i <= n;i++) cin >> w[i] >> v[i];
    memset(dp,-0x3f,sizeof dp);
    dp[0][1] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = m;j >= w[i];j--) {
            for (int u = 1;u <= k;u++)
                st1[u] = dp[j - w[i]][u] + v[i],st2[u] = dp[j][u];
            tail1 = tail2 = 1;
            for (int u = 1;u <= k;u++)
                if (st1[tail1] > st2[tail2]) dp[j][u] = st1[tail1],tail1++;
                else dp[j][u] = st2[tail2],tail2++;
        }
    int ans = 0;
    for (int i = 1;i <= k;i++) ans += dp[m][i];
    cout << ans << endl;
    return 0;
}