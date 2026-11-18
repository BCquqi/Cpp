#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,k,dep[N],fa[N],dp[N],tmp = 0;
bool flag[N];

void dfs(int u,int pa,bool record) {
    dep[u] = dep[pa] + 1;
    if (record) fa[u] = pa;
    for (auto [v,w] : G[u]) {
        if (v == pa) continue;
        dfs(v,u,record);
    }
    return ;
}

void calc(int u,int pa) {
    for (auto &[v,w] : G[u]) {
        if (v == pa) continue;
        if (flag[u] && flag[v]) w = -1;
        calc(v,u);
        tmp = max(tmp,dp[u] + dp[v] + w);
        dp[u] = max(dp[u],dp[v] + w);
    }
    return ;
}

int main() {
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back({b,1}); G[b].push_back({a,1});
    }
    dfs(1,0,0);
    int s,mxdep = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i], s = i;
    memset(dep,0,sizeof dep);
    dfs(s,0,1);
    mxdep = 0;
    int t = 0;
    for (int i = 1;i <= n;i++)
        if (mxdep < dep[i]) mxdep = dep[i], t = i;
    mxdep--;
    if (k == 1) {
        cout << 2 * (n - 1) - mxdep + 1 << endl;
    } else {
        for (int i = t;i;i = fa[i]) flag[i] = true;
        calc(1,0);
        cout << 2 * n - mxdep - tmp << endl;
    }
    return 0;
}