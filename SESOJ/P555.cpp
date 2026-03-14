#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e3 + 5;
struct Edge {int v,w;};
vector<Edge> G[N],rG[N];
int dis[N],rdis[N],vis[N],rvis[N],n,m,x,ans = -1e9;

void spfa() {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(x);
    dis[x] = 0,vis[x] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto [v,w] : G[u]) {
            if (dis[v] <= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            if (!vis[v]) q.push(v);
            vis[v] = 1;
        }
    }
}

void rspfa() {
    memset(rdis,0x3f,sizeof rdis);
    queue<int> q;
    q.push(x);
    rdis[x] = 0,rvis[x] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        rvis[u] = 0;
        for (auto [v,w] : rG[u]) {
            if (rdis[v] <= rdis[u] + w) continue;
            rdis[v] = rdis[u] + w;
            if (!rvis[v]) q.push(v);
            rvis[v] = 1;
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1;i <= m;i++) {
        int a,b,t;
        cin >> a >> b >> t;
        G[a].push_back({b,t});
        rG[b].push_back({a,t});
    }
    spfa(); rspfa();
    for (int i = 1;i <= n;i++) ans = max(ans,dis[i] + rdis[i]);
    cout << ans << endl;
    return 0;
}