#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
struct Edge {
    int u,w;
};
vector<Edge> G[N];
queue<int> q;
int dis[N],n,m,s,t;

void bfs() {
    memset(dis,0x3f,sizeof dis);
    q.push(s);
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v,w] : G[u]) {
            int r = max(dis[u],w);
            if (r < dis[v]) {
                dis[v] = r;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    bfs();
    cout << dis[t] << endl;
    return 0;
}