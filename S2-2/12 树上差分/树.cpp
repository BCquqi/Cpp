#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int fa[N][32],dep[N],d[N],a[N];

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
    int n,m,ans = 0;
    cin >> n >> m;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1,0);
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        int lca = LCA(a,b);
        d[a]++,d[b]++,d[lca] -= 2;
    }
    add(1,0);
    for (int i = 2;i <= n;i++) {
        if (a[i] == 0) ans += m;
        if (a[i] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}