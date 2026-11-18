#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,siz[N],dep[N],dp[N];

void dfs1(int u,int pa) {
    siz[u] = 1;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dep[v] = dep[u] + 1;
        dfs1(v,u);
        siz[u] += siz[v], dp[u] += dp[v] + w * siz[v];
    }
    return ;
}

// ans[v]=ans[u]+(n−sz[v])−sz[v]

void dfs2(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dp[v] = dp[u] + w * (n - siz[v] - siz[v]);
        dfs2(v,u);
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z}); G[y].push_back({x,z});
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i = 1;i <= n;i++) cout << dp[i] << endl;
    return 0;
}