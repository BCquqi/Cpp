#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dep[N],fa[N][32],siz[N],n,m;

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
        if (fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int dis(int u,int v) {return dep[u] + dep[v] - 2 * dep[LCA(u,v)];}

int get_k_parent(int u,int k) {
    for (int i = 30;i >= 0;i--)
        if (k & (1 << i)) u = fa[u][i];
    return u;
}

void solve(int x,int y) {
    int lca = LCA(x,y);
    int dist = dis(x,y);
    if (dist % 2 != 0) {
        cout << 0 << endl;
        return ;
    }
    if (dep[x] == dep[y]) {
        int xx = get_k_parent(x,dep[x] - dep[lca] - 1);
        int yy = get_k_parent(y,dep[y] - dep[lca] - 1);
        cout << n - siz[xx] - siz[yy] << endl;
    } else {
        if (dep[x] > dep[y]) swap(x,y);
        int yy = get_k_parent(y,dist / 2 - 1);
        int k =  get_k_parent(y,dist / 2);
        cout << siz[k] - siz[yy] << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1,0);
    cin >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        solve(x,y);
    }
    return 0;
}