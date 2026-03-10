#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
int dis[N],n,m,s; bool vis[N];
struct Edge {
	int v,w;
}; vector<Edge> G[N];

void spfa() {
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	q.push(s);
	dis[s] = 0,vis[s] = 1;
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

int main() {;
	cin >> n >> m >> s;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
	}
	spfa();
	for (int i = 1;i <= n;i++) cout << ((dis[i] == 0x3f3f3f3f) ? 2147483647 : dis[i]) << ' ';
	cout << endl;
	return 0;
}