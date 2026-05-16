#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 5e4 + 5;
struct Edge {int v,w;};
struct Node {int x,y,z;} a[N];
vector<Edge> G[N];
int f[N],dep[N],cnt,n,m,fa[N][32],minn[N][32];
bool vis[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void Union(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

void kruskal() {
    sort(a + 1,a + m + 1,[](Node x,Node y) {return x.z > y.z;});
    for (int i = 1;i <= n;i++) f[i] = i;
    int ans = 0;
    for (int i = 1;i <= m;i++) {
        int x = a[i].x,y = a[i].y,z = a[i].z;
        if (find(x) == find(y)) continue;
        Union(x,y);
        G[x].push_back({y,z}); G[y].push_back({x,z});
        if (++cnt == n - 1) break;
    }
}

void dfs(int u,int pa,int W) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    minn[u][0] = W;
    vis[u] = true;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1],
        minn[u][i] = min(minn[fa[u][i - 1]][i - 1],minn[u][i - 1]);
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u,w);
    }
}

int LCA(int u,int v) {
    int ans = 1e9;
    if (dep[u] < dep[v]) swap(u,v);
    for (int i = 30;i >= 0;i--)
        if (dep[fa[u][i]] >= dep[v])
            ans = min(ans, minn[u][i]),u = fa[u][i];
    if (u == v) return ans;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i])
            ans = min(ans,minn[u][i]),
            ans = min(ans,minn[v][i]),
            u = fa[u][i],v = fa[v][i];
    return min(ans,min(minn[u][0],minn[v][0]));
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        a[i] = {x,y,z};
    }
    kruskal();
    dep[1] = 1;
    for (int i = 1;i <= n;i++)
        if (!vis[i]) dfs(i,0,1e9);
    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        if (find(x) != find(y)) cout << -1 << endl;
        else cout << LCA(x,y) << endl;
    }
    return 0;
}