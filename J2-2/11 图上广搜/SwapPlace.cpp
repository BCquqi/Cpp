#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2005;
struct Node {
    int a,b;
};
int c[N],n,m,dis[N][N];
bool vis[N][N];
vector<int> G[N];
queue<Node> q;

void bfs() {
    q.push({1,n});
    vis[1][n] = true,dis[1][n] = 0;
    while (!q.empty()) {
        int u = q.front().a,v = q.front().b;
        q.pop();
        for (auto a : G[u])
            for (auto b : G[v]) {
                if (vis[a][b]) continue;
                if (c[a] == c[b]) continue;
                q.push({a,b});
                vis[a][b] = true,dis[a][b] = dis[u][v] + 1;
            }
    }
}

void solve() {
	memset(c,0,sizeof c); memset(dis,0x3f,sizeof dis); memset(vis,false,sizeof vis);
	for (int i = 1;i <= 2000;i++) G[i].clear();
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> c[i];
	for (int i = 1;i <= m;i++) {
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
    bfs();
    cout << (vis[n][1] ? dis[n][1] : -1) << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}