#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e4 + 5,M = 1e3 + 5;
int x[N],y[N],dp[M],dp1[M],dp2[M]; // 横坐标为i时高度为j的最少点击次数，dp1/2分别存向上/下
int l[N],h[N]; // p 是横坐标，l 是下边沿高度，h 是上边沿高度

int main() {
    int n,m,k,ans = 0x3f3f3f3f,pass = 0; // pass 记录能通过的管道数量
    bool stopped = false; // 小鸟是否还能继续飞，用于辅助统计 pass
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) cin >> x[i] >> y[i];
    for (int i = 1;i <= k;i++) {
        int p;
        cin >> p;
        cin >> l[p] >> h[p];
    }
    dp[0] = 0x3f3f3f3f; // 除了地面都能起飞
    for (int i = 1;i <= n;i++) {
        memset(dp1,0x3f,sizeof dp1);
        memset(dp2,0x3f,sizeof dp2);
        for (int j = x[i] + 1;j <= m;j++) dp1[j] = min(dp[j - x[i]] + 1,dp1[j - x[i]] + 1); // 完全背包
        for (int j = m - x[i];j <= m;j++) dp1[m] = min(dp1[m],dp1[j] + 1),dp1[m] = min(dp1[m],dp[j] + 1); // 特判顶到天花板的情况
        for (int j = 1;j <= m - y[i];j++) dp2[j] = dp[j + y[i]]; // 01 背包，这里高度降低反而是 + 比较特殊且不能为 0，而且只要不跳就必须落下没有选择
        for (int j = 1;j <= m;j++) dp[j] = min(dp1[j],dp2[j]); // 合并 dp
        if (h[i] != 0) { // 只要不等于 0 必然有管道，反之亦然
            for (int j = 1;j <= l[i];j++) dp[j] = 0x3f3f3f3f;
            for (int j = h[i];j <= m;j++) dp[j] = 0x3f3f3f3f; // 管道不可达
            bool flag = false; // 是否能通过这一关
            for (int j = l[i] + 1; j < h[i]; j++)
                if (dp[j] != 0x3f3f3f3f) {
                    flag = true;
                    break;
                }
            if (!flag) {
                cout << 0 << endl << pass << endl;
                return 0;
            }
            else pass++; // 可以过关
        }
    }
    for (int i = 1;i <= m;i++) ans = min(ans,dp[i]);
    cout << 1 << endl << ans << endl;
    return 0;
}