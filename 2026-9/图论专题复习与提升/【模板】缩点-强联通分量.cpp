#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

const int N = 1e4 + 5,M = 1e5 + 5;
int a[N],dfn[N],low[N],scc[N],val[N];
int idx = 0,cnt = 0,u[M],v[M],in[N],topo[N],cur = 0,dp[N];
int n,m;
stack<int> stk;
bool flag[N];
vector<int> G[N],nG[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    stk.push(u), flag[u] = true;
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (flag[v]) low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u]) {
        cnt++;
        int top = 0;
        do {
            top = stk.top(), stk.pop();
            scc[top] = cnt, flag[top] = false;
        } while (top != u);
    }
    return ;
}

void topo_sort() {
    queue<int> q;
    for (int i = 1;i <= cnt;i++)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo[++cur] = u;
        for (auto v : nG[u]) {
            dp[v] = max(dp[v],dp[u] + val[v]);
            if (--in[v] == 0) q.push(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++) {
        cin >> u[i] >> v[i];
        G[u[i]].push_back(v[i]);
    }
    for (int i = 1;i <= n;i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1;i <= n;i++) val[scc[i]] += a[i];
    for (int i = 1;i <= m;i++)
        if (scc[u[i]] != scc[v[i]]) nG[scc[u[i]]].push_back(scc[v[i]]), in[scc[v[i]]]++;
    for (int i = 1;i <= cnt;i++) dp[i] = val[i];
    topo_sort();
    int ans = 0;
    for (int i = 1;i <= cnt;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}