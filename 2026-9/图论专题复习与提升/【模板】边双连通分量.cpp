#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5,M = 2e6 + 5;
struct Edge {int v,id;};
vector<Edge> G[N];
int dfn[N],low[N],idx = 0;
bool flag[M],vis[N];
vector<vector<int>> dcc;
vector<int> now;

void tarjan(int u,int edge) {
    dfn[u] = low[u] = ++idx;
    for (auto [v,id] : G[u]) {
        if (id == edge) continue;
        if (!dfn[v]) {
            tarjan(v,id);
            low[u] = min(low[u],low[v]);
            if (low[v] > dfn[u]) flag[id] = true;
        }
        else low[u] = min(low[u],dfn[v]);
    }
}

void dfs(int u) {
    vis[u] = true, now.push_back(u);
    for (auto [v,id] : G[u]) {
        if (flag[id]) continue;
        if (vis[v]) continue;
        dfs(v);
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,i}), G[v].push_back({u,i});
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i,0);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) now.clear(), dfs(i), dcc.push_back(now);
    cout << dcc.size() << endl;
    for (auto it : dcc) {
        cout << it.size();
        for (int u : it) cout << ' ' << u;
        cout << endl;
    }
    return 0;
}