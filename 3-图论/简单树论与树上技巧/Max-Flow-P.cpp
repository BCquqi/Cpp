#include<iostream>
#include<vector>
using namespace std;

const int N = 5e4 + 5;
vector<int> G[N];
int d[N],fa[N][32],a[N],dep[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
    }
}

int LCA(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

void add(int u,int pa) {
    a[u] = d[u];
    for (auto v : G[u]) {
        if (v == pa) continue;
        add(v,u);
        a[u] += a[v];
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i <= k;i++) {
        int s,t;
        cin >> s >> t;
        int lca = LCA(s,t);
        d[s] += 1,d[t] += 1,d[lca] -= 1,d[fa[lca][0]] -= 1;
    }
    add(1,0);
    int ans = 0;
    for (int i = 1;i <= n;i++) ans = max(ans,a[i]);
    cout << ans << endl;
    return 0;
}