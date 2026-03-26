#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 2e5 + 5;
int n,m,x;
long long dis[2 * N];
bool vis[2 * N];
struct Edge {int v; long long w;};
vector<Edge> G[2 * N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0;s
    q.push({1,0});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v,w] : G[u]) {
            if (vis[v]) continue;
            if (dis[v] <= dis[u] + w) continue;
            dis[v] = dis[u] + w;
            q.push({v,dis[v]});
        }
    }
}

int main() {
    cin >> n >> m >> x;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,1}); G[v + n].push_back({u + n,1});
    }
    for (int i = 1;i <= n;i++) {G[i].push_back({i + n,x}); G[i + n].push_back({i,x}); }
    dijkstra();
    cout << min(dis[n],dis[2 * n]) << endl;
    return 0;
}