#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2505;
int dis[N],n,c,s,e; bool vis[N];
struct Edge {
	int v,w;
}; vector<Edge> G[N];

void dijkstra() {
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	for (int i = 1;i <= n;i++) {
		int u = 0;
		for (int j = 1;j <= n;j++)
			if (!vis[j] && dis[j] < dis[u]) u = j;
		vis[u] = 1;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			dis[v] = min(dis[v],dis[u] + w);
		}
	}
}

int main() {
	cin >> n >> c >> s >> e;
	for (int i = 1;i <= c;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w}); G[v].push_back({u,w});
	}
	dijkstra();
	cout << dis[e] << endl;
	return 0;
}