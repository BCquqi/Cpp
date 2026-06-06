#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
long long dp1[N],dp2[N],f[N],best[N];

void dfs(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        if (dp1[v] + w > dp1[u]) {
            best[u] = v;
            dp2[u] = dp1[u];
            dp1[u] = dp1[v] + w;
        }
        else if (dp1[v] + w > dp2[u]) dp2[u] = dp1[v] + w;
    }
}

void dfs2(int u,int pa) {
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        if (v != best[u]) f[v] = max(f[u],dp1[u]) + w;
        else f[v] = max(f[u],dp2[u]) + w;
        dfs2(v,u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back({y,z}); G[y].push_back({x,z});
    }
    dfs(1,0);
    dfs2(1,0);
    for (int i = 1;i <= n;i++) cout << dp1[i] + dp2[i] + f[i] - min(f[i],min(dp1[i],dp2[i])) << '\n';
    return 0;
}