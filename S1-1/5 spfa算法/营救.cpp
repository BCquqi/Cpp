#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e4 + 5;
int dis[N],n,m,s,t; bool vis[N];
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
			if (dis[v] > max(dis[u],w)) {
				dis[v] = max(dis[u],w);
				if (!vis[v]) q.push(v);
				vis[v] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	spfa();
	cout << dis[t] << endl;
	return 0;
}