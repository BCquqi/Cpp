#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 2005;
vector<int> G[N];
int dis[N],vis[N];

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true,dis[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u])
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    bfs();
    cout << dis[n] << endl;
    return 0;
}