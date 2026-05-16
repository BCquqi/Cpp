#include<iostream>
#include<vector>
using namespace std;

const int N = 5e5 + 5;
vector<int> G[N];
int dep[N],siz[N],fa[N][32],n,q;

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    siz[u] = 1;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v];
    }
}

int LCA(int u,int v) {
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return v;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int dis(int a,int b) {
    return dep[a] + dep[b] - 2 * dep[LCA(a,b)];
}

int C(int c,int x) {
    if (c == x) return 0;
    if (LCA(c,x) == c) {
        for (int i = 30;i >= 0;i--)
            if (dep[fa[x][i]] > dep[c]) x = fa[x][i];
        return siz[x];
    }
    else return n - siz[c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1,0);
    while (q--) {
        int a,b,c;
        cin >> a >> b >> c;
        if (dis(a,b) == dis(a,c) + dis(b,c)) cout << n - C(c,a) - C(c,b) << endl;
        else cout << 0 << endl;
    }
    return 0;
}