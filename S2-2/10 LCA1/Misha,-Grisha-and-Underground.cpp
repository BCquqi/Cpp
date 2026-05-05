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

int dis(int u,int v) {return dep[u] + dep[v] - 2 * dep[LCA(u,v)];}

int func(int s,int t,int f) {return (dis(s,f) + dis(t,f) - dis(s,t)) / 2 + 1;}

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 2;i <= n;i++) {
        int p;
        cin >> p;
        G[p].push_back(i); G[i].push_back(p);
    }
    dfs(1,0);
    while (q--) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << max(func(a,b,c),max(func(a,c,b),func(b,c,a))) << endl;
    }
    return 0;
}