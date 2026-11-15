#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define int long long
using namespace std;

const int N = 2005,M = 20005,mod = 1e9 + 7;
int n,m,q,tot;
int in[N],out[N];
int w[N][N];
int dp[N];
int topo[N],pos[N];
int t[N];
vector<int> G[N],rG[N];

void topo_sort() {
    queue<int> q;
    for (int i = 0;i <= n + 1;i++)
        if (!in[i]) q.push(i);
    int idx = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo[++idx] = u,pos[u] = idx;
        for (auto v : G[u])
            if (--in[v] == 0) q.push(v);
    }
    tot = idx;
    return ;
}

void init() {
    for (int i = 1;i <= tot;i++) {
        int u = topo[i];
        w[u][u] = 1;
        for (auto v : G[u])
            for (int j = 0;j <= n + 1;j++)
                if (w[u][j]) w[v][j] = (w[v][j] + w[u][j]) % mod;
    }
    return ;
}

signed main() {
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
        in[v]++,out[u]++;
    }
    for (int i = 1;i <= n;i++) {
        if (!in[i]) {
            G[0].push_back(i);
            rG[i].push_back(0);
            in[i]++;
        }
        if (!out[i]) {
            G[i].push_back(n + 1);
            rG[n + 1].push_back(i);
            out[i]++;
        }
    }
    topo_sort();
    init();
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        for (int i = 1;i <= k;i++) cin >> t[i];
        sort(t + 1,t + k + 1,[](int x,int y) {return pos[x] < pos[y];});
        for (int i = 1;i <= k;i++) {
            int u = t[i];
            dp[u] = w[u][0];
            for (int j = 1;j < i;j++) {
                int v = t[j];
                if (w[u][v]) dp[u] = (dp[u] - w[u][v] * dp[v] % mod + mod) % mod;
            }
        }
        int ans = w[n + 1][0];
        for (int i = 1;i <= k;i++) {
            int u = t[i];
            if (w[n + 1][u]) ans = (ans - w[n + 1][u] * dp[u] % mod + mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}