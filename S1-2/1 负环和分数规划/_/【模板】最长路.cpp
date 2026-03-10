#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N = 2005;
int n,m,dis[N],vis[N],cnt[N];
struct Edge {int v,w;};
vector<Edge> G[N];

bool spfa() {
	memset(dis,-0x3f,sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0,vis[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (auto p : G[u]) {
			int v = p.v,w = p.w;
			if (dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
					if (++cnt[v] >= n) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
	}
	if (spfa()) cout << "INF" << endl;
	else cout << dis[n] << endl;
	return 0;
}