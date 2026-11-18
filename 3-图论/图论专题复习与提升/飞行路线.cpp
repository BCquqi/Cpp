#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
int n,m,k,s,t;
long long dis[15][N];
bool vis[15][N];
struct Edge {int v; long long w;};
struct Node {int u,l,d;};
vector<Edge> G[N];

bool operator < (const Node &x,const Node &y) {return x.d > y.d;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Node> q;
    q.push({s,0,0});
    dis[0][s] = 0;
    while (!q.empty()) {
        int u = q.top().u,l = q.top().l; q.pop();
        if (vis[l][u]) continue;
        vis[l][u] = true;
        for (auto [v,w] : G[u]) {
            if (vis[l][v]) continue;
            if (dis[l][v] <= dis[l][u] + w) continue;
            dis[l][v] = dis[l][u] + w;
            q.push({v,l,dis[l][v]});
        }
        if (l == k) continue;
        for (auto [v,w] : G[u]) {
            if (vis[l + 1][v]) continue;
            if (dis[l + 1][v] <= dis[l][u]) continue;
            dis[l + 1][v] = dis[l][u];
            q.push({v,l + 1,dis[l + 1][v]});
        }
    }
}

int main() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 1;i <= m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c}); G[b].push_back({a,c});
    }
    dijkstra();
    long long ans = 1e18;
    for (int i = 0;i <= k;i++) ans = min(ans,dis[i][t]);
    cout << ans << endl;
    return 0;
}