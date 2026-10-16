#include<iostream>
#include<vector>
#define int long long
using namespace std;

const int N = 5e5 + 5,M = 2e6 + 5;
const long long mod = 1e9 + 7;

struct Edge {int v,id;};
vector<Edge> G[N];
vector<int> nG[N];

int dfn[N],low[N],idx = 0;
bool flag[M];
int scc[N],cnt = 0;
int stk[N],top = 0;
int cnt1[N],cnt2[N],pw[M],dp[N][2],siz[N];
bool exist[N];

void tarjan(int u,int edge) {
    dfn[u] = low[u] = ++idx;
    stk[++top] = u,exist[u] = true;
    for (auto [v,id] : G[u]) {
        if (id == edge) continue;
        if (!dfn[v]) {
            tarjan(v,id);
            low[u] = min(low[u],low[v]);
            if (low[v] > dfn[u]) flag[id] = true;
        }
        else if (exist[v]) low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u]) {
        cnt++;
        int x;
        do {
            x = stk[top--];
            exist[x] = false;
            scc[x] = cnt;
        } while (x != u);
    }
}

void dfs(int u,int pa) {
    dp[u][0] = pw[cnt2[u]];
    dp[u][1] = (pw[cnt1[u]] - 1 + mod) % mod * pw[cnt2[u]] % mod;
    siz[u] = cnt2[u];
    for (auto v : nG[u]) {
        if (v == pa) continue;
        dfs(v,u);
        siz[u] += siz[v] + 1;
        dp[u][1] = (dp[u][1] * ((2 * dp[v][0] % mod + dp[v][1]) % mod) % mod + dp[u][0] * dp[v][1] % mod) % mod;
        dp[u][0] = dp[u][0] * (2 * dp[v][0] % mod) % mod;
    }
    return ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,i}), G[v].push_back({u,i});
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i,0);
    for (int i = 1;i <= n;i++) cnt1[scc[i]]++;
    for (int u = 1;u <= n;u++)
        for (auto [v,id] : G[u])
            if (scc[u] == scc[v]) cnt2[scc[u]]++;
    for (int i = 1;i <= cnt;i++) cnt2[i] /= 2;
    for (int u = 1;u <= n;u++)
        for (auto [v,id] : G[u])
            if (scc[u] != scc[v])
                nG[scc[u]].push_back(scc[v]);
    pw[0] = 1;
    for (int i = 1;i <= m + n;i++) pw[i] = pw[i - 1] * 2 % mod;
    dfs(1,0);
    long long ans = dp[1][1];
    for (int i = 2;i <= cnt;i++)
        ans = (ans + dp[i][1] * pw[m - siz[i] - 1]) % mod;
    cout << ans << endl;
    return 0;
}