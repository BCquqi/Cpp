#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 305;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,m,k,dp[N][N][2],siz[N];
// dp[u][i][0 / 1] 表示以 i 为根的子树中，有 i 个点被大头吃掉且点 u 是否被大头吃

void dfs(int u,int pa) {
    siz[u] = 1, dp[u][0][0] = dp[u][1][1] = 0;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        int tmp[N][2];
        for (int i = 0;i <= min(siz[u],k);i++)
            tmp[i][0] = dp[u][i][0], tmp[i][1] = dp[u][i][1], 
            dp[u][i][0] = 1e9, dp[u][i][1] = 1e9;
        for (int i = min(siz[u],k);i >= 0;i--)
            for (int j = 0;j <= siz[v] && i + j <= k;j++)
                dp[u][i + j][1] = min(dp[u][i + j][1],tmp[i][1] + dp[v][j][1] + w), 
                dp[u][i + j][1] = min(dp[u][i + j][1],tmp[i][1] + dp[v][j][0]), 
                dp[u][i + j][0] = min(dp[u][i + j][0],tmp[i][0] + dp[v][j][1]), 
                dp[u][i + j][0] = min(dp[u][i + j][0],tmp[i][0] + dp[v][j][0] + (m == 2) * w);
        siz[u] += siz[v];
    }
}

int main() {
    cin >> n >> m >> k;
    if (k < 1 || k > n - (m - 1) || m > n || m < 2) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1;i < n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c}); G[b].push_back({a,c});
    }
    memset(dp,0x3f,sizeof dp);
    dfs(1,0);
    cout << (dp[1][k][1] == 1e9 ? -1 : dp[1][k][1]) << endl;
    return 0;
}