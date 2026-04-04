#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1505;
struct Edge {int v,w;};
vector<Edge> G[N];
bool vis[N]; long long dis[N];

void spfa() {
    memset(dis,-0x3f,sizeof dis);
    queue<int> q;
    dis[1] = 0,vis[1] = true;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (auto [v,w] : G[u]) {
            if (dis[v] >= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return ;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    spfa();
    cout << (dis[n] <= -1e9 ? -1 : dis[n]) << endl;
    return 0;
}