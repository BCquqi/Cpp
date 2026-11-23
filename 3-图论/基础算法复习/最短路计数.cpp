#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e6 + 5,mod = 100003;
int n,m,s,dis[N],cnt[N]; bool vis[N];
struct Node {int v,w;};
vector<Node> G[N];

bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra() {
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    cnt[1] = 1;
    priority_queue<Node> q;
    q.push({1,dis[1]});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto p : G[u]) {
            int v = p.v,w = p.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u];
                q.push({v,dis[v]});
            } else if (dis[v] == dis[u] + w)
                cnt[v] = (cnt[v] + cnt[u]) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back({v,1}), G[v].push_back({u,1});
    }
    dijkstra();
    for (int i = 1;i <= n;i++) cout << cnt[i] << '\n';
    return 0;
}