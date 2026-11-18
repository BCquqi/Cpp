#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005,M = 15,PMAX = 1e5 + 5;
int p[N],G[N],gp[N][M],pv[N][M];
// p 是游戏机价格，G 是游戏机的游戏数量，gp 是游戏价格，pv 是产值

int f[PMAX],g[PMAX]; // f 是忽略游戏机价格的最大价值，g 不忽略游戏机价格

int main() {
    int n,v,ans = 0;
    cin >> n >> v;
    for (int i = 1;i <= n;i++) {
        cin >> p[i] >> G[i];
        for (int j = 1;j <= G[i];j++)
            cin >> gp[i][j] >> pv[i][j];
    }
    for (int i = 1;i <= n;i++) { // i 台游戏机
        for (int j = 0;j <= v;j++) f[j] = g[j]; // 上一个含游戏机价格的 g 就是初始值
        for (int j = 1;j <= G[i];j++) // j 个游戏
            for (int k = v;k >= gp[i][j];k--) { // 目前背包容量为 k
                f[k] = max(f[k],f[k - gp[i][j]] + pv[i][j]); // 01 背包
            }
        for (int j = 0;j <= v;j++)
            g[j] = max(g[j],f[j - p[i]]); // 更新 g，要么不选要么扣掉游戏机的钱选上
    }
    for (int i = 0;i <= v;i++)
        ans = max(ans,g[i]); // 预算以内求最大 (不要求刚好付完所以要循环)
    cout << ans << endl;
    return 0;
}