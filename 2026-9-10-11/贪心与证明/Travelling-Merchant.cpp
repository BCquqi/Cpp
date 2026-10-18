#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 2e5 + 5;
struct Node {int u,v,r,p,id;} a[N];
struct Edge {int u,r,p,id;};
vector<Edge> G[N];
int out[N],n,m,dp[N];
bool vis[N];
queue<int> q;

void topo_sort() {
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v,r,p,id] : G[u]) {
            if (vis[id]) continue;
            vis[id] = true;
            if (--out[v] == 0) q.push(v);
            if (dp[u] != 0x3f3f3f3f3f3f3f3f) dp[v] = min(dp[v],max(dp[u] - p,r));
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].u >> a[i].v >> a[i].r >> a[i].p;
        out[a[i].u]++, a[i].id = i;
        G[a[i].v].push_back({a[i].u,a[i].r,a[i].p,i});
    }
    for (int i = 1;i <= n;i++)
        if (out[i] == 0) q.push(i);
    sort(a + 1,a + m + 1,[](Node x,Node y) {return x.r > y.r;});
    memset(dp,0x3f,sizeof dp);
    for (int i = 1;i <= m;i++) {
        topo_sort();
        auto [u,v,r,p,id] = a[i];
        if (!vis[id]) {
            vis[id] = true, dp[u] = min(dp[u], r);
            if (--out[u] == 0) q.push(u);
        }
    }
    for (int i = 1;i <= n;i++)
        cout << (dp[i] == 0x3f3f3f3f3f3f3f3f ? -1 : dp[i]) << ' ';
    cout << endl;
    return 0;
}