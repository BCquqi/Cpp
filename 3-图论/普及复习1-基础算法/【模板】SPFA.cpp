#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
struct Edge {int v,w;};
vector<Edge> G[N];
int dis[N]; bool vis[N];

void spfa() {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(1);
    dis[1] = 0,vis[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto p : G[u]) {
            int v = p.v,w = p.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c}), G[b].push_back({a,c});
    }
    spfa();
    cout << dis[n] << endl;
    return 0;
}