#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 1e6 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int a[N],ring_u,ring_v,id,dp[N][2];
bool vis_ring[N];

void find_ring(int u,int pa) {
    vis_ring[u] = true;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        if (vis_ring[v]) ring_u = u, ring_v = v, id = w;
        else find_ring(v,u);
    }
}

void dfs(int u,int pa) {
    dp[u][0] = 0, dp[u][1] = a[u];
    for (auto [v,w] : G[u]) {
        if (v == pa || w == id) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]), dp[u][1] += dp[v][0];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int u;
        cin >> a[i] >> u;
        G[u].push_back({i,i}); G[i].push_back({u,i});
    }
    for (int i = 1;i <= n;i++) {
        if (!vis_ring[i]) {
            find_ring(i,0);
            dfs(ring_u,0);
            int res = dp[ring_u][0];
            dfs(ring_v,0);
            res = max(res,dp[ring_v][0]);
            ans += res;
        }
    }
    cout << ans << '\n';
    return 0;
}