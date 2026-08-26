#include<iostream>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

const int N = 2005;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,k,dp[N][N],siz[N];
// dp[i][j] 表示以 i 为根节点时子树中有 j 个染黑的最大价值

void dfs(int u,int pa) {
    siz[u] = 1, dp[u][0] = dp[u][1] = 0;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
        for (int i = min(k,siz[u]);i >= 0;i--)
            for (int j = 0;j <= min(i,siz[v]);j++) {
                int tmp = w * (j * (k - j) + (siz[v] - j) * (n - k - siz[v] + j));
                dp[u][i] = max(dp[u][i],dp[u][i - j] + dp[v][j] + tmp);
            }
    }
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w}); G[v].push_back({u,w});
    }
    memset(dp,-0x3f,sizeof dp);
    dfs(1,0);
    cout << dp[1][k] << endl;
    return 0;
}