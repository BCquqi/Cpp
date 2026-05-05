#include<iostream>
#include<vector>
using namespace std;

const int N = 5e4 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dep[N],fa[N][32],dis[N];

void dfs(int u,int pa) {
    dep[u] = dep[pa] + 1;
    fa[u][0] = pa;
    for (int i = 1;i <= 30;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dis[v] = dis[u] + w;
        dfs(v,u);
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

int dist(int u,int v) {return dis[u] + dis[v] - 2 * dis[LCA(u,v)];}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while (cin >> n) {
        for (int i = 1;i <= n;i++) G[i].clear();
        for (int i = 1;i < n;i++) {
            int a,b,l;
            cin >> a >> b >> l;
            a++,b++;
            G[a].push_back({b,l}); G[b].push_back({a,l});
        }
        dfs(1,0);
        int q;
        cin >> q;
        while (q--) {
            int x,y,z;
            cin >> x >> y >> z;
            x++,y++,z++;
            cout << (dist(x,y) + dist(y,z) + dist(x,z)) / 2 << '\n';
        }
        cout << '\n';
    }
    return 0;
}