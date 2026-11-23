#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1005;
struct Edge {int v,w,f;};
vector<Edge> G[N];
int dis[N],vis[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra(int lim) {
    memset(vis,false,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1,dis[1]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w,f] : G[u]) {
            if (vis[v] || f < lim) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    int maxf = 0;
    for (int i = 1;i <= m;i++) {
        int a,b,c,f;
        cin >> a >> b >> c >> f;
        maxf = max(maxf,f);
        G[a].push_back({b,c,f}), G[b].push_back({a,c,f});
    }
    int ans = 0;
    for (int i = 1;i <= maxf;i++)
        dijkstra(i), ans = max(ans,i * 1000000 / dis[n]);
    cout << ans << endl;
    return 0;
}