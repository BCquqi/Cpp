#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e4 + 5;
vector<int> G[N],rG[N];
queue<int> q;
bool vis[N],flag[N];
int n,m,s,t,dis[N];

void dfs(int u) {
    vis[u] = true;
    for (auto v : rG[u]) if (!vis[v]) dfs(v);
}

void bfs() {
    memset(vis,false,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    q.push(s);
    vis[s] = true,dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (flag[v] || vis[v]) continue;
            q.push(v);
            vis[v] = true,dis[v] = dis[u] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        rG[y].push_back(x);
    }
    cin >> s >> t;
    dfs(t);
    for (int u = 1;u <= n;u++)
        for (auto v : G[u]) flag[u] |= (!vis[v]);
    if (flag[s]) {cout << -1 << endl; return 0;}
    bfs();
    cout << (dis[t] > 1e9 ? -1 : dis[t]) << endl;
    return 0;
}