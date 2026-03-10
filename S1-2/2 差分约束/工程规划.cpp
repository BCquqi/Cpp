#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1005;
struct Edge {int v,w;};
vector<Edge> G[N];
bool vis[N];
int cnt[N],dis[N],n,m,ans = -1e9;

bool spfa() {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        vis[i] = cnt[i] = 1;
        dis[i] = 0;
        q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (auto [v,w] : G[u]) {
            if (dis[v] <= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                if (++cnt[v] >= n) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,b;
        cin >> u >> v >> b;
        G[v].push_back({u,b});
    }
    if (spfa()) cout << "NO SOLUTION" << endl;
    else {
        int minn = 1e9;
        for (int i = 1;i <= n;i++) minn = min(minn,dis[i]);
        for (int i = 1;i <= n;i++) cout << dis[i] - minn << endl;
    }
    return 0;
}