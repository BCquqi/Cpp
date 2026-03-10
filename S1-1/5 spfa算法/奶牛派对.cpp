#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e3 + 5;
int dis[N],rdis[N],n,m,x; bool vis[N];
struct Edge {
	int v,w;
};
vector<Edge> G[N],rG[N];

void spfa(int s,int dis[],vector<Edge> G[]) {
	for (int i = 1;i <= n;i++) dis[i] = 1e9;
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

int main() {
	int ans = 0;
	cin >> n >> m >> x;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w}); rG[v].push_back({u,w});
	}
	spfa(x,dis,G);
	spfa(x,rdis,rG);
	for (int i = 1;i <= n;i++) ans = max(ans,dis[i] + rdis[i]);
	cout << ans << endl;
	return 0;
}