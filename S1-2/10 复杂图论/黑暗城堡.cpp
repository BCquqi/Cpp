#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1005,mod = (1 << 31) - 1;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N],cnt[N];
bool vis[N];

bool operator < (const Edge &x,const Edge &y) {return x.w > y.w;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    priority_queue<Edge> q;
    dis[1] = 0;
    q.push({1,0});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w] : G[u]) {
            if (vis[v]) continue;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
    return ;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,l;
        cin >> x >> y >> l;
        G[x].push_back({y,l}); G[y].push_back({x,l});
    }
    dijkstra();
    long long ans = 1;
    for (int u = 1;u <= n;u++)
        for (auto [v,w] : G[u])
            if (dis[u] + w == dis[v]) cnt[v]++;
    for (int i = 2;i <= n;i++) ans = ans * cnt[i] % mod;
    cout << ans << endl;
    return 0;
}