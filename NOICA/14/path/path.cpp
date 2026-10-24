#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int w[N],dfn[N],low[N],scc[N],mn[N],mx[N],f[N],g[N],stk[N];
int idx = 0,cnt = 0,top = 0;
bool flag[N];
vector<int> G[N],nG[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stk[++top] = u,flag[u] = true;
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (flag[v]) low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u]) {
        cnt++;
        int v;
        do {
            v = stk[top--],flag[v] = false;
            scc[v] = cnt;
            mn[cnt] = min(mn[cnt],w[v]);
            mx[cnt] = max(mx[cnt],w[v]);
        } while (v != u);
    }
    return ;
}

signed main() {
    freopen("path.in","r",stdin);
    freopen("path.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
        mn[i] = 1e9,mx[i] = -1e9;
    }
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i);
    for (int u = 1;u <= n;u++)
        for (auto v : G[u])
            if (scc[u] != scc[v]) nG[scc[u]].push_back(scc[v]);
    for (int i = 1;i <= cnt;i++) f[i] = mn[i],g[i] = mx[i];
    for (int i = 1;i <= cnt;i++) f[i] = mn[i],g[i] = mx[i];
    for (int i = cnt;i >= 1;i--)
        for (auto v : nG[i]) {
            f[v] = min(f[v],f[i]);
            g[v] = max(g[v],g[i]);
        }
    int ans = 0;
    for (int i = 1;i <= cnt;i++) ans = max(ans,g[i] - f[i]);
    cout << ans << endl;
    return 0;
}