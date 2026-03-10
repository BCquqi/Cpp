#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e5 + 5;
int n,m,k,t,val[N]; long long dis[N]; bool vis[N];
struct Node {int v; long long w;};
vector<Node> G[N];

bool operator < (const Node &x,const Node &y) {return x.w > y.w;}

void dijkstra() {
	for (int i = 1;i <= n;i++) dis[i] = 1e18;
	priority_queue<Node> q;
	dis[1] = 0;
	q.push({1,dis[1]});
	while (!q.empty()) {
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (vis[v]) continue;
			w += val[v];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({v,dis[v]});
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> t;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
	}
	for (int i = 1;i <= t;i++) {
		int p;
		cin >> p;
		val[p] = k;
	}
	dijkstra();
	cout << (dis[n] == 1e18 ? -1 : dis[n]) << endl;
	return 0;
}