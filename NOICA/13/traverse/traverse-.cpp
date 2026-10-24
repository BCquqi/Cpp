#include<iostream>
#include<vector>
using namespace std;

const int N = 3e5 + 5;
int a[N],id[N],dep[N],fa[N][32],vis[N];
vector<int> G[N];

void init(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u]) {
        if (v == pa) continue;
        init(v,u);
    }
}

int LCA(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return v;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int main() {
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    int n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1,id + n + 1,[](int x,int y) {return a[x] < a[y];});
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    init(1,0);
    int r = 0,last = 1,ans = 2 * (n - 1) + a[1];
    for (int i = 1;i <= n;i++) {
        int now = id[i];
        if (vis[now]) continue;
    }
    return 0;
}