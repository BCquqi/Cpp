#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> G[N];
int dep[N],fa[N][32];

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
    if (u == v) return v;
    for (int i = 30;i >= 0;i--)
        if (fa[u][i] != fa[v][i]) u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    dep[1] = 1;
    dfs(1,0);
    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        cout << dep[x] + dep[y] - 2 * dep[LCA(x,y)] << endl;
    }
    return 0;
}