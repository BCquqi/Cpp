#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
struct Edge {int v,w;};
struct Node {int u,l; long long d;};
vector<Edge> G[N];
long long dis[105][N];
bool vis[105][N];
int n,m,k;

bool operator < (const Node &x,const Node &y) {return x.d > y.d;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Node> q;
    q.push({1,0,0});
    dis[0][1] = 0;
    while (!q.empty()) {
        int u = q.top().u,l = q.top().l; q.pop();
        if (vis[l][u]) continue;
        vis[l][u] = true;
        for (auto [v,w] : G[u]) {
            int tim = dis[l][u],nxt = (l + 1) % k;
            if (tim < w) tim += (w - tim + k - 1) / k * k;
            if (vis[nxt][v]) continue;
            if (dis[nxt][v] <= tim + 1) continue;
            dis[nxt][v] = tim + 1;
            q.push({v,nxt,dis[nxt][v]});
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        int u,v,a;
        cin >> u >> v >> a;
        G[u].push_back({v,a});
    }
    dijkstra();
    cout << (dis[0][n] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[0][n]) << endl;
    return 0;
}