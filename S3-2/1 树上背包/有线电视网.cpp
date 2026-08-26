#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 3005;
struct Edge {int v,w;};
vector<Edge> G[N];
int k[N],dp[N][N],siz[N],a[N];

void dfs(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
        for (int j = siz[u];j >= 1;j--)
            for (int k = 1;k <= min(siz[v],j);k++)
                dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k] - w);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n - m;i++) {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++) {
            int x,c;
            cin >> x >> c;
            G[x].push_back({i,c}); G[i].push_back({x,c});
        }
    }
    for (int i = n - m + 1;i <= n;i++) cin >> a[i];
    memset(dp,-0x3f,sizeof dp);
    for (int i = 1;i <= n;i++) dp[i][0] = 0;
    for (int i = n - m + 1;i <= n;i++)
        siz[i] = 1, dp[i][1] = a[i];
    dfs(1,0);
    for (int i = n;i >= 1;i--) {
        if (dp[1][i] >= 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}