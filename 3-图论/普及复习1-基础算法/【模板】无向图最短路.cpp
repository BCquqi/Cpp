#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int n,m,dis[N];
bool vis[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0, q.push({1,dis[1]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v,w] : G[u]) {
            if (vis[v]) continue;
            if (dis[v] > dis[u] + w)
                dis[v] = dis[u] + w, q.push({v,dis[v]});
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w}), G[v].push_back({u,w});
    }
    dijkstra();
    cout << dis[n] << endl;
    return 0;
}